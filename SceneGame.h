#pragma once
#include "SceneBase.h"
#include "Player.h"
#include <list>
#include <vector>

class Node;
class Stage;
class UiText;

//ゲームシーン
class SceneGame : public SceneBase
{
public:
	enum class Phase
	{
		CanPlay,
		Player,
		GameOver,
	};

private:
	const std::list<const char*> ImagePreload =
	{
	};


	Phase m_phase;
	Node* m_rootNode;
	Stage* m_stage;
	Player* m_player[2];
	Player::PlayerType m_playerType[2];	// プレイヤーのタイプ
	UiText* m_uiText;

	bool m_trun;
	bool m_secondPass;

	static constexpr float CPUTime = 0.5f;	// CPUの思考時間
	float m_cpuTime;


public:
	//コンストラクタ
	SceneGame(Player::PlayerType player1, Player::PlayerType player2) :
		m_phase(Phase::CanPlay),
		m_rootNode(nullptr),
		m_stage(nullptr),
		m_player{ nullptr },
		m_playerType{ player1, player2 },
		m_trun(false),
		m_secondPass(false),
		m_cpuTime(0) {}

	virtual void Initialize() override;			//初期化
	virtual void Finalize() override;			//終了
	virtual SceneBase* Update() override;		//更新
	virtual void Draw() override;				//描画

	Phase GetPhase() { return m_phase; }
};