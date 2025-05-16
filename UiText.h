#pragma once
#include "Node.h"
#include "Sprite.h"

class UiText : public Node
{
public:
	enum class Type
	{
		None = -1,
		Pass,
		WinBlack,
		WinWhite,
		Draw,

	};

private:
	static constexpr float DrawTime = 1.5f;

	Transform m_transform;	// 姿勢情報
	Sprite m_passImg;		// パス画像
	Sprite m_blackWinImg;	// 黒の勝ち
	Sprite m_whiteWinImg;	// 白の勝ち
	Sprite m_DrawImg;		// 引き分け
	float m_elapsedTime;	// 経過時間

	Type m_drawType;	// 表示するテキストを選択

protected:
	virtual void Load() override;
	virtual void Release() override;
	virtual void Update() override;
	virtual void Draw() override;

public:
	UiText();

	void SetDrawType(UiText::Type drawType);

	bool IsPassTime() { return m_drawType == Type::Pass; }
};