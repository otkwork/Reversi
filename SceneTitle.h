#pragma once
#include "SceneBase.h"
#include "Player.h"
#include "Button.h"

class Node;

//タイトルシーン
class SceneTitle : public SceneBase
{
private:
	Node* m_rootNode;

	Player::PlayerType m_playerType[2];	// プレイヤーのタイプ
	bool m_isStart;	// ゲーム開始フラグ


public:
	//コンストラクタ
	SceneTitle() :
		m_rootNode(nullptr),
		m_playerType{ Player::PlayerType::Player },
		m_isStart(false)
	{}

	virtual void Initialize() override;		//初期化
	virtual void Finalize() override;		//終了
	virtual SceneBase* Update() override;	//更新
	virtual void Draw() override;			//描画

	void SetPlayerType(Player::PlayerType playerType, Disc::Color color)
	{
		m_playerType[static_cast<int>(color)] = playerType;
	}

	Player::PlayerType GetPlayerType(Disc::Color color)
	{
		return m_playerType[static_cast<int>(color)];
	}

	// ゲームの開始
	void IsStart() { m_isStart = true;}

};
