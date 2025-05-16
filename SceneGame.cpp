#include "SceneGame.h"
#include "SceneTitle.h"
#include "SceneManager.h"
#include "Screen.h"
#include "Input.h"
#include "Time.h"
#include "Node.h"
#include "Actor.h"
#include "ImageLoader.h"
#include "DxLib.h"
#include "Stage.h"
#include "PlayerBase.h"
#include "UiText.h"

//初期化
void SceneGame::Initialize()
{
	// 画像の事前読み込み
	for (auto image : ImagePreload)
	{
		ImageLoader::GetInstance()->Load(image);
	}

	// ルート
	m_rootNode = new Node();

	// 背景
	m_rootNode->AddChild(new Actor("Background", "game.png", Screen::Center));

	// アクターレイヤー
	Node* actorLayer = new Node();
	m_rootNode->AddChild(actorLayer);

	// UIレイヤー
	Node* uiLayer = new Node();
	m_rootNode->AddChild(uiLayer);

	// 盤面
	m_stage = new Stage();
	actorLayer->AddChild(m_stage);

	actorLayer->AddChild(new CanPut(m_stage));

	// プレイヤー
	for (int i = 0; i < static_cast<int>(Disc::Color::Length); i++)
	{
		m_player[i] = new Player(m_stage, static_cast<Disc::Color>(i), m_playerType[i]);
		actorLayer->AddChild(m_player[i]);
	}

	m_uiText = new UiText();
	uiLayer->AddChild(m_uiText);
}

//終了
void SceneGame::Finalize()
{
	// 事前読み込みした画像の破棄
	for (auto image : ImagePreload)
	{
		ImageLoader::GetInstance()->Load(image);
	}

	// ノードの削除
	m_rootNode->TreeRelease();
	delete m_rootNode;
	m_rootNode = nullptr;
}

//更新
SceneBase* SceneGame::Update()
{
	switch (m_phase)
	{
	case Phase::CanPlay:
		if (m_player[static_cast<int>(m_trun)]->CanPutList())	// 今のターン(白か黒)が置く場所が一個以上あるかどうか
		{
			// 相手が置けないとき
			if (m_secondPass)
			{
				m_uiText->SetDrawType(UiText::Type::Pass);
			}
			m_secondPass = false;
			m_stage->ChangeTurn(static_cast<Disc::Color>(m_trun));
			m_cpuTime = 0;	// CPUの思考時間をリセット
			m_phase = Phase::Player;	// 置ける
		}
		else if(m_secondPass)	// 二回目のパスかどうか
		{
			m_phase = Phase::GameOver;	// 両方置けない
		}
		else
		{
			m_secondPass = true;		// 次置けなければゲーム終了
			m_trun = !m_trun;			// 色を変える
			m_phase = Phase::CanPlay;	// 置けない
		}
		break;

	case Phase::Player:
		if (Input::GetInstance()->IsMouseDown(1) || m_player[static_cast<int>(m_trun)]->GetPlayerType() != Player::PlayerType::Player)
		{
			if (m_uiText->IsPassTime())	// パスの表示が出ているかどうか
			{
				break;	// パスの表示が出ているときは何もしない
			}

			if (m_player[static_cast<int>(m_trun)]->GetPlayerType() != Player::PlayerType::Player)
			{
				m_cpuTime += Time::GetInstance()->GetDeltaTime();
				if (m_cpuTime < CPUTime) break;	// CPUの思考時間
			}

			if (m_player[static_cast<int>(m_trun)]->Play())
			{
				m_trun = !m_trun;
				m_phase = Phase::CanPlay;
			}
		}
		break;

	case Phase::GameOver:	// ゲーム終了
		// 黒の方が多いなら
		if (m_stage->GetDiscAmount(Disc::Color::Black) > m_stage->GetDiscAmount(Disc::Color::White))
		{
			m_uiText->SetDrawType(UiText::Type::WinBlack);
		}
		// 白の方が多いなら
		else if (m_stage->GetDiscAmount(Disc::Color::Black) < m_stage->GetDiscAmount(Disc::Color::White))
		{
			m_uiText->SetDrawType(UiText::Type::WinWhite);
		}
		// 引き分け
		else
		{
			m_uiText->SetDrawType(UiText::Type::Draw);
		}
		
		if (Input::GetInstance()->IsAnyKeyDown())
		{
			return new SceneTitle();
		}
		break;
	}

	// ノードの更新
	m_rootNode->TreeUpdate();

	return this;
}

//描画
void SceneGame::Draw()
{
	// ノードの描画
	m_rootNode->TreeDraw();
}
