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

	Transform m_transform;	// �p�����
	Sprite m_passImg;		// �p�X�摜
	Sprite m_blackWinImg;	// ���̏���
	Sprite m_whiteWinImg;	// ���̏���
	Sprite m_DrawImg;		// ��������
	float m_elapsedTime;	// �o�ߎ���

	Type m_drawType;	// �\������e�L�X�g��I��

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