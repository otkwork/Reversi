#include "SceneManager.h"
#include "SceneBase.h"
#include "Fade.h"

// �f�X�g���N�^
SceneManager::~SceneManager()
{
	// ���s���V�[���ƑJ�ڐ�V�[���������Ȃ�B�A���ddelete���Ȃ�
	if (m_scene == m_nextScene)
	{
		m_nextScene = nullptr;
	}

	// ���s���V�[���̔j��
	if (m_scene)
	{
		m_scene->Finalize();
		delete m_scene;
		m_scene = nullptr;
	}

	//�J�ڐ�V�[���̔j��
	if (m_nextScene)
	{
		m_scene->Finalize();
		delete m_nextScene;
		m_nextScene = nullptr;
	}
}

//�X�V
void SceneManager::Update()
{
	switch (m_phase)
	{
	// ���s��
	case Phase::Run:
		//���s���V�[���̍X�V
		m_nextScene = m_scene->Update();
			
		//�J�ڐ�V�[�������s���V�[���ƈ������J�ڊJ�n
		if (m_nextScene != m_scene)
		{
			// �t�F�[�h�A�E�g�J�n
			m_phase = Phase::FadeOut;
			Fade::GetInstance()->StartFadeOut();
		}
		break;

		// �t�F�[�h�A�E�g
	case Phase::FadeOut:
		// �t�F�[�h�A�E�g���I���܂őҋ@
		if (Fade::GetInstance()->IsFade())
		{
			break;
		}
		
		// �t�F�[�h���I������̂ŃV�[���J�ڂ���
		m_phase = Phase::Transition;
		break;

		// �V�[���J��
	case Phase::Transition:
		//�J�ڐ�V�[���̏�����
		m_nextScene->Initialize();

		//���s���V�[��������Δj������
		if (m_scene)
		{
			m_scene->Finalize();
			delete m_scene;
			m_scene = nullptr;
		}

		//�J�ڐ�V�[�������s���V�[���ɂ���
		m_scene = m_nextScene;
		m_nextScene = nullptr;
		
		// �t�F�[�h�C��
		Fade::GetInstance()->StartFadeIn(0.2f);

		m_phase = Phase::Run;
		break;
	}
}

// �`��
void SceneManager::Draw()
{
	switch (m_phase)
	{
	case Phase::Run:
	case Phase::FadeOut:
		if (m_scene)
		{
			m_scene->Draw();
		}
		break;
	}
}