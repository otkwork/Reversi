#pragma once
#include "Node.h"
#include "Disc.h"

class Stage;

class CanPut : public  Node
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
	Sprite m_canPutBlack;
	Sprite m_canPutWhite;
	Transform m_canPutTransform;
	Stage* m_stage;

protected:
	virtual void Load() override;
	virtual void Release() override;
	virtual void Draw() override;

public:
	CanPut(Stage* stage);

	void destroy() { Destroy(); }
};
