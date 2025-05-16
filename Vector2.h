#pragma once

class Vector3;

class Vector2
{
public:
	float x;
	float y;

	// �R���X�g���N�^
	constexpr Vector2() :
		x(0),
		y(0) {}

	template <typename T1, typename T2>
	constexpr Vector2(T1 x, T2 y) : 
		x(static_cast<float>(x)),
		y(static_cast<float>(y)){}

	// Vector3�ւ̃L���X�g
	operator Vector3() const;

	// ���Z
	constexpr Vector2 operator + (const Vector2& other) const	// Vector2 + Vector2
	{
		return Vector2(x + other.x, y + other.y);
	}
	constexpr Vector2& operator += (const Vector2& other)		// Vector2 += Vector2
	{
		x += other.x;
		y += other.y;
		return *this;
	}

	// ���Z
	constexpr Vector2 operator - (const Vector2& other) const	// Vector2 - Vector2
	{
		return Vector2(x - other.x, y - other.y);
	}
	constexpr Vector2& operator -= (const Vector2& other)		// Vector2 -= Vector2
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}

	// ��Z
	constexpr Vector2 operator * (const float& scalar) const	// Vector2 * scalar
	{
		return Vector2(x * scalar, y * scalar);
	}
	constexpr friend Vector2 operator * (const float& scalar, const Vector2& v)	// scalar * Vector2
	{
		return v * scalar;
	}
	constexpr Vector2& operator *= (const float& scalar)		// Vector2 *= scalar
	{
		x *= scalar;
		y *= scalar;
		return *this;
	}

	// ���Z
	constexpr Vector2 operator / (const float& scalar) const	// Vector2 / scalar
	{
		return Vector2(x / scalar, y / scalar);
	}
	constexpr Vector2& operator /= (const float& scalar)		// Vector2 /= scalar
	{
		x /= scalar;
		y /= scalar;
		return *this;
	}

	// ��
	constexpr Vector2 operator - () const	// -Vector2
	{
		return Vector2(-x, -y);
	}

	// ����
	constexpr bool operator == (const Vector2& other) const	// Vector2 == Vector2
	{
		return (x == other.x) && (y == other.y);
	}

	// �񓙉�
	constexpr bool operator != (const Vector2& other) const	// Vector2 != Vector2
	{
		return !(*this == other);
	}

	// �[������
	constexpr bool IsZero() const
	{
		return (x == 0) && (y == 0);
	}

	// �����̓����擾
	constexpr float SqrMagnitude() const
	{
		return x * x + y * y;
	}

	// �������擾
	float Magnitude() const;
};
