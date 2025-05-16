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

//������
void SceneGame::Initialize()
{
	// �摜�̎��O�ǂݍ���
	for (auto image : ImagePreload)
	{
		ImageLoader::GetInstance()->Load(image);
	}

	// ���[�g
	m_rootNode = new Node();

	// �w�i
	m_rootNode->AddChild(new Actor("Background", "game.png", Screen::Center));

	// �A�N�^�[���C���[
	Node* actorLayer = new Node();
	m_rootNode->AddChild(actorLayer);

	// UI���C���[
	Node* uiLayer = new Node();
	m_rootNode->AddChild(uiLayer);

	// �Ֆ�
	m_stage = new Stage();
	actorLayer->AddChild(m_stage);

	actorLayer->AddChild(new CanPut(m_stage));

	// �v���C���[
	for (int i = 0; i < static_cast<int>(Disc::Color::Length); i++)
	{
		m_player[i] = new Player(m_stage, static_cast<Disc::Color>(i), m_playerType[i]);
		actorLayer->AddChild(m_player[i]);
	}

	m_uiText = new UiText();
	uiLayer->AddChild(m_uiText);
}

//�I��
void SceneGame::Finalize()
{
	// ���O�ǂݍ��݂����摜�̔j��
	for (auto image : ImagePreload)
	{
		ImageLoader::GetInstance()->Load(image);
	}

	// �m�[�h�̍폜
	m_rootNode->TreeRelease();
	delete m_rootNode;
	m_rootNode = nullptr;
}

//�X�V
SceneBase* SceneGame::Update()
{
	switch (m_phase)
	{
	case Phase::CanPlay:
		if (m_player[static_cast<int>(m_trun)]->CanPutList())	// ���̃^�[��(������)���u���ꏊ����ȏ゠�邩�ǂ���
		{
			// ���肪�u���Ȃ��Ƃ�
			if (m_secondPass)
			{
				m_uiText->SetDrawType(UiText::Type::Pass);
			}
			m_secondPass = false;
			m_stage->ChangeTurn(static_cast<Disc::Color>(m_trun));
			m_cpuTime = 0;	// CPU�̎v�l���Ԃ����Z�b�g
			m_phase = Phase::Player;	// �u����
		}
		else if(m_secondPass)	// ���ڂ̃p�X���ǂ���
		{
			m_phase = Phase::GameOver;	// �����u���Ȃ�
		}
		else
		{
			m_secondPass = true;		// ���u���Ȃ���΃Q�[���I��
			m_trun = !m_trun;			// �F��ς���
			m_phase = Phase::CanPlay;	// �u���Ȃ�
		}
		break;

	case Phase::Player:
		if (Input::GetInstance()->IsMouseDown(1) || m_player[static_cast<int>(m_trun)]->GetPlayerType() != Player::PlayerType::Player)
		{
			if (m_uiText->IsPassTime())	// �p�X�̕\�����o�Ă��邩�ǂ���
			{
				break;	// �p�X�̕\�����o�Ă���Ƃ��͉������Ȃ�
			}

			if (m_player[static_cast<int>(m_trun)]->GetPlayerType() != Player::PlayerType::Player)
			{
				m_cpuTime += Time::GetInstance()->GetDeltaTime();
				if (m_cpuTime < CPUTime) break;	// CPU�̎v�l����
			}

			if (m_player[static_cast<int>(m_trun)]->Play())
			{
				m_trun = !m_trun;
				m_phase = Phase::CanPlay;
			}
		}
		break;

	case Phase::GameOver:	// �Q�[���I��
		// ���̕��������Ȃ�
		if (m_stage->GetDiscAmount(Disc::Color::Black) > m_stage->GetDiscAmount(Disc::Color::White))
		{
			m_uiText->SetDrawType(UiText::Type::WinBlack);
		}
		// ���̕��������Ȃ�
		else if (m_stage->GetDiscAmount(Disc::Color::Black) < m_stage->GetDiscAmount(Disc::Color::White))
		{
			m_uiText->SetDrawType(UiText::Type::WinWhite);
		}
		// ��������
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

	// �m�[�h�̍X�V
	m_rootNode->TreeUpdate();

	return this;
}

//�`��
void SceneGame::Draw()
{
	// �m�[�h�̕`��
	m_rootNode->TreeDraw();
}
