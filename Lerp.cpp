#include "Lerp.h"
#define _USE_MATH_DEFINES	// M_PI���g�����߂ɕK�v��define
#include <cmath>

// �����o�֐����֐��|�C���^�ɃZ�b�g
float (*Lerp::m_funcTable[])(float) =
{
	// enum Model�Ɠ�������
	&Lerp::Linear,
	&Lerp::EaseInOutQuad,
};

float Lerp::Linear(float t)
{
	return t;
}

float Lerp::EaseInOutQuad(float t)
{
	return t < 0.5f ?
		2 * t * t :
		1 - std::powf(-2 * t + 2, 2.0f) / 2.0f;
}
