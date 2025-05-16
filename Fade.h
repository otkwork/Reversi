#pragma once

class Fade
{
private:
	static constexpr int BrightBlack = -255;	// �P�x:��
	static constexpr int BrightWhite = 255;		// �P�x:��
	static constexpr int BrightNeutral = 0;		// �P�x:�ʏ�

	enum class Phase
	{
		Idle,	// �������Ă��Ȃ�
		Fade,	// �t�F�[�h��
	};

	Phase m_phase;
	float m_elapsedTime;	// �o�ߎ���
	float m_duration;		// ���v����
	int m_beginBright;		// �t�F�[�h�J�n���̋P�x
	int m_endBright;		// �t�F�[�h�I�����̋P�x

	// �R���X�g���N�^
	Fade();

public:
	// �V���O���g��
	static Fade* GetInstance()
	{
		static Fade instance;
		return &instance;
	}

	enum class Color
	{
		Black,
		White,
	};

	// �X�V
	void Update(int screen);

	// �t�F�[�h�C��
	void StartFadeIn(float duration = 0.5f, Color color = Color::Black);

	// �t�F�[�h�A�E�g
	void StartFadeOut(float duration = 0.5f, Color color = Color::Black);

	// �t�F�[�h�����ǂ���
	bool IsFade()
	{
		return m_phase == Phase::Fade;
	}
};
