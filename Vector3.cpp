#include "Vector3.h"
#include "Vector2.h"
#include <cmath>

// Vector2‚Ö‚ÌƒLƒƒƒXƒg
Vector3::operator Vector2() const
{
	return Vector2(x, y);
}

// ’·‚³‚ğæ“¾
float Vector3::Magnitude() const
{
	return std::sqrtf(SqrMagnitude());
}