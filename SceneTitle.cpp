#include "SceneTitle.h"
#include "SceneGame.h"
#include "SelectButton.h"
#include "TitleUi.h"
#include "DxLib.h"
#include "Input.h"
#include "Screen.h"
#include "Actor.h"

//初期化
void SceneTitle::Initialize()
{
	m_rootNode = new Node();

	// 背景
	m_rootNode->AddChild(new Actor(
		"Background",
		"title.png",
		Screen::Center
	));

	// タイトルロゴ
	m_rootNode->AddChild(new Actor(
		"Logo",
		"title_logo.png",
		Screen::TopCenter + Vector2(0, Screen::Height / 3)
	));

	m_rootNode->AddChild(new TitleUi(
		Screen::Center + Vector2(0, 200),
		this
	));

	// タイトルのセレクトボタン
	for (int i = 0; i < static_cast<int>(Disc::Color::Length); i++)
	{
		m_rootNode->AddChild(new SelectButton(
			Player::PlayerType::CPU,
			static_cast<Disc::Color>(i),
			"cpu_button.png",
			Screen::Center + Vector2((i * 3 - 2) * 100, 100),
			this
		));
	}

	for (int i = 0; i < static_cast<int>(Disc::Color::Length); i++)
	{
		m_rootNode->AddChild(new SelectButton(
			Player::PlayerType::Player,
			static_cast<Disc::Color>(i),
			"player_button.png",
			Screen::Center + Vector2((i * 3 - 1) * 100, 100),
			this
		));
	}
}

//終了
void SceneTitle::Finalize()
{
	m_rootNode->TreeRelease();
	delete m_rootNode;
	m_rootNode = nullptr;
}

//更新
SceneBase* SceneTitle::Update()
{
	// いずれかのキーが推されたらゲームシーンへ遷移
	if (m_isStart)
	{
		return new SceneGame(m_playerType[0], m_playerType[1]);
	}
	// ノードの更新
	m_rootNode->TreeUpdate();

	return this;
}

//描画
void SceneTitle::Draw()
{
	// ノードの描画
	m_rootNode->TreeDraw();
}