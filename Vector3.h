#pragma once

class Vector2;

class Vector3
{
public:
	float x;
	float y;
	float z;

	// コンストラクタ
	constexpr Vector3() :
		x(0),
		y(0),
		z(0){}

	template <typename T1, typename T2 ,typename T3>
	constexpr Vector3(T1 x, T2 y, T3 z) :
		x(static_cast<float>(x)),
		y(static_cast<float>(y)), 
		z(static_cast<float>(z)) {}

	// Vector2へのキャスト
	operator Vector2() const;

	// 加算
	constexpr Vector3 operator + (const Vector3& other) const	// Vector3 + Vector3
	{
		return Vector3(x + other.x, y + other.y, z + other.z);
	}
	constexpr Vector3& operator += (const Vector3& other)		// Vector3 += Vector3
	{
		x += other.x;
		y += other.y;
		z += other.z;
		return *this;
	}

	// 減算
	constexpr Vector3 operator - (const Vector3& other) const	// Vector3 - Vector3
	{
		return Vector3(x - other.x, y - other.y, z - other.z);
	}
	constexpr Vector3& operator -= (const Vector3& other)		// Vector3 -= Vector3
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
		return *this;
	}

	// 乗算
	constexpr Vector3 operator * (const float& scalar) const	// Vector3 * scalar
	{
		return Vector3(x * scalar, y * scalar, z * scalar);
	}
	constexpr friend Vector3 operator * (const float& scalar, const Vector3& v)	// scalar * Vector3
	{
		return v * scalar;
	}
	constexpr Vector3& operator *= (const float& scalar)		// Vector3 *= scalar
	{
		x *= scalar;
		y *= scalar;
		z *= scalar;
		return *this;
	}

	// 除算
	constexpr Vector3 operator / (const float& scalar) const	// Vector3 / scalar
	{
		return Vector3(x / scalar, y / scalar, z / scalar);
	}
	constexpr Vector3& operator /= (const float& scalar)		// Vector3 /= scalar
	{
		x /= scalar;
		y /= scalar;
		z /= scalar;
		return *this;
	}

	// 負
	constexpr Vector3 operator - () const	// -Vector3
	{
		return Vector3(-x, -y, -z);
	}

	// 等価
	constexpr bool operator == (const Vector3& other) const	// Vector3 == Vector3 
	{
		return (x == other.x) && (y == other.y) && (z == other.z);
	}

	// 非等価
	constexpr bool operator != (const Vector3& other) const	// Vector3 != Vector3 
	{
		return !(*this == other);
	}

	// ゼロ判定
	constexpr bool IsZero() const
	{
		return (x == 0) && (y == 0) && (z == 0);
	}

	// 長さの二乗を取得
	constexpr float SqrMagnitude() const
	{
		return x * x + y * y + z * z;
	}

	// 長さを取得
	float Magnitude() const;
};
