#pragma once
#include "Vector2.h"

//��ʂɊւ���
namespace Screen
{
	static constexpr int Width = 640;	//��
	static constexpr int Height = 480;	//����
	static constexpr Vector2 Size = Vector2(Width, Height);	// ���E����

	static constexpr int Top = 0;			// ��
	static constexpr int Bottom = Height;	// ��
	static constexpr int Left = 0;			// ��
	static constexpr int Right = Width;		// �E
	static constexpr Vector2 Center = Size / 2;	// ����

	static constexpr Vector2 TopLeft = Vector2(Left, Top);				// ����
	static constexpr Vector2 TopCenter = Vector2(Center.x, Top);		// ������
	static constexpr Vector2 TopRight = Vector2(Right, Top);			// �E��

	static constexpr Vector2 CenterLeft = Vector2(Left, Center.y);		// ������
	static constexpr Vector2 CenterRight = Vector2(Right, Center.y);		// �����E

	static constexpr Vector2 BottomLeft = Vector2(Left, Bottom);		// ����
	static constexpr Vector2 BottomCenter = Vector2(Center.x, Bottom);	// ������
	static constexpr Vector2 BottomRight = Vector2(Right, Bottom);		// �E��
};