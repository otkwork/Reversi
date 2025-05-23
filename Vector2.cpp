#include "Vector2.h"
#include "Vector3.h"
#include <cmath>

// Vector3へのキャスト
Vector2::operator Vector3() const
{
	return Vector3(x, y, 0);
}

// 長さを取得
float Vector2::Magnitude() const
{
	return std::sqrtf(SqrMagnitude());
}