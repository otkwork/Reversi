#include "SceneTitle.h"
#include "SceneGame.h"
#include "SelectButton.h"
#include "TitleUi.h"
#include "DxLib.h"
#include "Input.h"
#include "Screen.h"
#include "Actor.h"

//������
void SceneTitle::Initialize()
{
	m_rootNode = new Node();

	// �w�i
	m_rootNode->AddChild(new Actor(
		"Background",
		"title.png",
		Screen::Center
	));

	// �^�C�g�����S
	m_rootNode->AddChild(new Actor(
		"Logo",
		"title_logo.png",
		Screen::TopCenter + Vector2(0, Screen::Height / 3)
	));

	m_rootNode->AddChild(new TitleUi(
		Screen::Center + Vector2(0, 200),
		this
	));

	// �^�C�g���̃Z���N�g�{�^��
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

//�I��
void SceneTitle::Finalize()
{
	m_rootNode->TreeRelease();
	delete m_rootNode;
	m_rootNode = nullptr;
}

//�X�V
SceneBase* SceneTitle::Update()
{
	// �����ꂩ�̃L�[�������ꂽ��Q�[���V�[���֑J��
	if (m_isStart)
	{
		return new SceneGame(m_playerType[0], m_playerType[1]);
	}
	// �m�[�h�̍X�V
	m_rootNode->TreeUpdate();

	return this;
}

//�`��
void SceneTitle::Draw()
{
	// �m�[�h�̕`��
	m_rootNode->TreeDraw();
}