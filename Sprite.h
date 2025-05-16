#pragma once
#include "Vector2.h"
#include "Transform.h"
#include "Animation.h"
#include <map>

class Sprite
{
private:
	std::map<const char*, Animation> m_animationList;	// <�A�j���[�V������ : �A�j���[�V�����f�[�^>�̘A�z�z��
	const Animation* m_runningAnime;		// �Đ����̃A�j���[�V�������X�g�ւ̃|�C���^
	float m_elapsedTime;		// �o�ߎ��ԁi�b�j

public:
	Vector2 gridSize;	// �A�j���[�V�����̂P�R�}�̕��E����
	bool flipX;			// ���E���]
	bool flipY;			// �㉺���]

	// �R���X�g���N�^
	Sprite() :
		m_runningAnime(nullptr),
		m_elapsedTime(0),
		flipX(false),
		flipY(false) {}

	// �f�X�g���N�^
	virtual ~Sprite();

	// �摜�̓ǂݍ���
	void Load();

	// �摜�̉��
	void Release();

	// �X�V
	void Update();

	// �`��
	void Draw(const Transform& transform);

	// �A�j���[�V�����̓o�^
	void Register(const char* textureName);
	void Register(const char* animeName, const Animation& animation);

	// �A�j���[�V�����̍Đ�
	void Play(const char* animaName);

	// �A�j���[�V�����̂P�R�}�̕`�掞�Ԃ��擾
	float GetFrameTime()
	{
		return m_runningAnime ? 1.0f / m_runningAnime->sampleRate : 0.0f;
	}

	// �A�j���[�V�����̑����Ԃ��擾
	float GetTotalFrameTime()
	{
		return m_runningAnime ? GetFrameTime() * m_runningAnime->gridAmount : 0.0f;
	}

	// �A�j���[�V�������I���������ǂ���
	bool IsFinishAnime()
	{
		return m_runningAnime ? m_elapsedTime >= GetTotalFrameTime() : true;
	}
};
