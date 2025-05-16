#include "Disc.h"
#include "Screen.h"
#include "Stage.h"

const char* Disc::Texture[static_cast<int>(Color::Length)] =
{
	"Black.png",
	"White.png",
};
const char* Disc::ColorStr[static_cast<int>(Color::Length)] =
{
	"Black",
	"White",
};

Disc::Disc(Color color, const Vector2& boardPos) :
	Actor(
		"Disc",
		nullptr,
		Stage::BoardToScreen(boardPos)
	),
	m_color(color),
	m_boardPos(boardPos)
{
	m_sprite = new Sprite();
	m_sprite->Register(ColorStr[static_cast<int>(Color::Black)], Animation(Texture[static_cast<int>(Color::Black)], 1, 1, false));
	m_sprite->Register(ColorStr[static_cast<int>(Color::White)], Animation(Texture[static_cast<int>(Color::White)], 1, 1, false));

	m_sprite->Play(ColorStr[static_cast<int>(m_color)]);
}

// プレイヤーの操作が終了
void Disc::FixPlay(const Vector2& boardPos)
{
	m_boardPos = boardPos;
	m_transform.position = Stage::BoardToScreen(m_boardPos);
}

// ひっくり返す
void Disc::Flip(Color color)
{
	int tmp = abs(static_cast<int>(color) - 1);
	m_color = static_cast<Color>(tmp);
	m_sprite->Play(ColorStr[static_cast<int>(m_color)]);
}
