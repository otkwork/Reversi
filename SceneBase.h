#pragma once

// �V�[�����N���X
class SceneBase
{
public:
	virtual ~SceneBase() {}

	//�������z�֐�
	virtual void Initialize() = 0;		//������
	virtual void Finalize() = 0;		//�I��
	virtual SceneBase* Update() = 0;	//�X�V
	virtual void Draw() = 0;			//�`��
};
