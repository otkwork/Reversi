#pragma once

// ���ԊǗ��N���X
class Time
{
private:
	int m_prevTime;		// �O�t���[���̎���
	float m_deltaTime;	// �O�t���[������̌o�ߎ���

	Time(); // �R���X�g���N�^

public:
	// �V���O���g��
	static Time* GetInstance()
	{
		static Time instance;
		return &instance;
	}

	void Update();	// �X�V

	// �O�t���[������̌o�ߎ��Ԃ��擾
	float GetDeltaTime()
	{
		return m_deltaTime;
	}
};
