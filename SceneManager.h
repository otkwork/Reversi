#pragma once

//�N���X�̑O���錾
class SceneBase;

// �V�[���J�ڃN���X
class SceneManager
{
private:
	// �t�F�[�Y
	enum class Phase
	{
		Run,		//���s��
		FadeOut,	// �t�F�[�h�A�E�g
		Transition,	//�J��
	};

	SceneBase* m_scene;		//���s���̃V�[��
	SceneBase* m_nextScene;	//�J�ڐ�̃V�[��
	Phase m_phase;			//�t�F�[�Y
public:
	// �R���X�g���N�^
	SceneManager(SceneBase* initScene) :
		m_scene(nullptr),
		m_nextScene(initScene),
		m_phase(Phase::Transition) {}
	
	//�f�X�g���N�^
	virtual ~SceneManager();

	void Update();	// �X�V
	void Draw();	// �`��
};