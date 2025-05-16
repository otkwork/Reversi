#include "GameMain.h"
#include "GameConfig.h"
#include "Screen.h"
#include "SceneManager.h"
#include "SceneGame.h"
#include "SceneTitle.h"
#include "Input.h"
#include "Time.h"
#include "Fade.h"
#include "ImageLoader.h"
#include "DxLib.h"

//�f�X�g���N�^
GameMain::~GameMain()
{
	// ����X�N���[���̔j��
	DeleteGraph(m_screen);

	// �V�[���̔j��
	delete m_sceneManager;
	m_sceneManager = nullptr;

	//DxLib �I��
	DxLib_End();
}

//���C�����[�v���s
void GameMain::Run()
{
	SetMainWindowText(GameConfig::Title); //�E�B���h�E�^�C�g��
	SetAlwaysRunFlag(GameConfig::AlwaysRunFlag);//��A�N�e�B�u���[�h�œ��삷��
	ChangeWindowMode(GameConfig::WindowMode);//�E�B���h�E���[�h�ŋN��
	SetGraphMode(Screen::Width, Screen::Height, GameConfig::ColorBit);//�E�B���h�E�T�C�Y

	//DX���C�u�����̏�����
	if (DxLib_Init())
	{
		throw - 1;
	}

	// �V�[���N��
	m_sceneManager = new SceneManager(new SceneTitle());

	// �X�N���[���쐬
	m_screen = MakeScreen(Screen::Width, Screen::Height);

	//�Q�[�����[�v
	while (ProcessMessage() == 0)
	{
		// ���̓V�X�e���̍X�V
		Input::GetInstance()->Update();

		// ���Ԃ̍X�V
		Time::GetInstance()->Update();

		//ESC�L�[�������ꂽ��I��
		if (Input::GetInstance()->IsKeyDown(KEY_INPUT_ESCAPE))
		{
			break;
		}

		// �V�[���̍X�V
		m_sceneManager->Update();

		// ����X�N���[���ɕ`��
		SetDrawScreen(m_screen);

		//��ʂɕ`����Ă�����̂�S������
		ClearDrawScreen();

		// �V�[���̕`��
		m_sceneManager->Draw();
		
#ifdef _DEBUG
		// �摜���[�_�[
		ImageLoader::GetInstance()->Draw();
#endif

		// �t�F�[�h
		Fade::GetInstance()->Update(m_screen);

		// ����X�N���[���𗠉�ʂɕ`��
		SetDrawScreen(DX_SCREEN_BACK);
		ClearDrawScreen();
		DrawGraph(0, 0, m_screen, false);

		//����ʂƕ\��ʂ��Ђ�����Ԃ�
		ScreenFlip();
	}
}
