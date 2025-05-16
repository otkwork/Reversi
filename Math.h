#pragma once
#include "Vector2.h"
#include <cmath>

namespace Math
{
	// �~����
	static constexpr double Pi = 3.141592653589793;

	// �f�O���i�x���@�j���烉�W�A���i�ʓx�@�j�ɕϊ�
	static constexpr double DegToRad(double deg)
	{
		return deg * Pi / 180.0;
	}

	// ���W�A���i�ʓx�@�j����f�O���i�x���@�j�ɕϊ�
	static constexpr double RadToDeg(double rad)
	{
		return rad / Pi * 180.0;
	}

	// �p�x��������֕ϊ�
	static constexpr Vector2 AngleToDirect(double deg)
	{
		double rad = DegToRad(deg);
		return Vector2(std::cos(rad), -std::sin(rad));
	}
}
