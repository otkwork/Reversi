#include "Vector3.h"
#include "Vector2.h"
#include <cmath>

// Vector2へのキャスト
Vector3::operator Vector2() const
{
	return Vector2(x, y);
}

// 長さを取得
float Vector3::Magnitude() const
{
	return std::sqrtf(SqrMagnitude());
}