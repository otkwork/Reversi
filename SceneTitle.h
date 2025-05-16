#pragma once
#include "SceneBase.h"
#include "Player.h"
#include "Button.h"

class Node;

//�^�C�g���V�[��
class SceneTitle : public SceneBase
{
private:
	Node* m_rootNode;

	Player::PlayerType m_playerType[2];	// �v���C���[�̃^�C�v
	bool m_isStart;	// �Q�[���J�n�t���O


public:
	//�R���X�g���N�^
	SceneTitle() :
		m_rootNode(nullptr),
		m_playerType{ Player::PlayerType::Player },
		m_isStart(false)
	{}

	virtual void Initialize() override;		//������
	virtual void Finalize() override;		//�I��
	virtual SceneBase* Update() override;	//�X�V
	virtual void Draw() override;			//�`��

	void SetPlayerType(Player::PlayerType playerType, Disc::Color color)
	{
		m_playerType[static_cast<int>(color)] = playerType;
	}

	Player::PlayerType GetPlayerType(Disc::Color color)
	{
		return m_playerType[static_cast<int>(color)];
	}

	// �Q�[���̊J�n
	void IsStart() { m_isStart = true;}

};
