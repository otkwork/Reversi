#pragma once
#include "SceneBase.h"
#include "Player.h"
#include <list>
#include <vector>

class Node;
class Stage;
class UiText;

//�Q�[���V�[��
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
	Player::PlayerType m_playerType[2];	// �v���C���[�̃^�C�v
	UiText* m_uiText;

	bool m_trun;
	bool m_secondPass;

	static constexpr float CPUTime = 0.5f;	// CPU�̎v�l����
	float m_cpuTime;


public:
	//�R���X�g���N�^
	SceneGame(Player::PlayerType player1, Player::PlayerType player2) :
		m_phase(Phase::CanPlay),
		m_rootNode(nullptr),
		m_stage(nullptr),
		m_player{ nullptr },
		m_playerType{ player1, player2 },
		m_trun(false),
		m_secondPass(false),
		m_cpuTime(0) {}

	virtual void Initialize() override;			//������
	virtual void Finalize() override;			//�I��
	virtual SceneBase* Update() override;		//�X�V
	virtual void Draw() override;				//�`��

	Phase GetPhase() { return m_phase; }
};