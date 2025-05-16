#include "Time.h"
#include "DxLib.h"

// �R���X�g���N�^
Time::Time() :
	m_prevTime(GetNowCount()),
	m_deltaTime(0)
{
}

// �X�V
void Time::Update()
{
	// ���ݎ������擾�i�P�ʂ̓~���b�j
	// �����m�ɂ͌��ݎ����ł͂Ȃ�
	int nowTime = GetNowCount();

	// �O�t���[���̎����ƌ��ݎ�������o�ߎ��Ԃ����߂�
	// ���łɒP�ʂ��~���b����b�ɕϊ�
	m_deltaTime = (nowTime - m_prevTime) / 1000.0f;

	// ���ݎ������o���Ă���
	m_prevTime = nowTime;
}