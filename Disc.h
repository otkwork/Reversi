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
	Color m_color;	// 自分の色
	Vector2 m_boardPos;	// 盤面上の位置

public:
	Disc(Color color, const Vector2& boardPos);

	// プレイヤーの操作が終了
	void FixPlay(const Vector2& boardPos);

	// ひっくり返る
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