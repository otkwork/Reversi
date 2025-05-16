#pragma once
#include "Actor.h"

class Disc : public Actor
{
public:
	enum class Color
	{
		Black,
		White,

		Length,
	};

	static constexpr Vector2 Size = Vector2(40, 40);
	static const char* Texture[static_cast<int>(Color::Length)];
	static const char* ColorStr[static_cast<int>(Color::Length)];

private:
	Color m_color;	// �����̐F
	Vector2 m_boardPos;	// �Ֆʏ�̈ʒu

public:
	Disc(Color color, const Vector2& boardPos);

	// �v���C���[�̑��삪�I��
	void FixPlay(const Vector2& boardPos);

	// �Ђ�����Ԃ�
	void Flip(Color color);

	Color GetColor() const
	{
		return m_color;
	}

	const Vector2& GetBoardPos() const
	{
		return m_boardPos;
	}
};