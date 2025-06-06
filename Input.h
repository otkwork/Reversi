#pragma once
#include "Vector2.h"
#include "DxLib.h"

#define KEY_INPUT_ENTER KEY_INPUT_RETURN

// 入力クラス
class Input
{
private:
	// キーボード
	static constexpr int KeyStateNum = 256; // キー入力状態の要素数

	char m_keyState[KeyStateNum];		// 現フレームのキー入力状態
	char m_keyStatePost[KeyStateNum];	// 前フレームのキー入力状態

	// マウス
	Vector2 m_mousePoint;	// マウス位置
	int m_mouseWheel;		// マウスホイール
	int m_mouseButton;		// 現フレームのマウスボタン入力状態
	int m_mouseButtonPost;	// 前フレームのマウスボタン入力状態

	// コンストラクタ
	Input() :
		m_keyState{ 0 },
		m_keyStatePost{ 0 },
		m_mouseWheel(0),
		m_mouseButton(0),
		m_mouseButtonPost(0) {}

public:
	// シングルトン
	static Input* GetInstance()
	{
		static Input instance;
		return &instance;
	}

	// 更新
	void Update();

	// キーが押された瞬間
	bool IsKeyDown(int key)
	{
		return !m_keyStatePost[key] && m_keyState[key];
	}

	// キーが押されている
	bool IsKeyPress(int key)
	{
		return m_keyState[key];
	}

	// キーが離された瞬間
	bool IsKeyUp(int key)
	{
		return m_keyStatePost[key] && !m_keyState[key];
	}

	// いずれかのキーが押された瞬間
	bool IsAnyKeyDown();

	// マウス位置を取得
	Vector2 GetMousePoint()
	{
		return m_mousePoint;
	}

	// マウスホイールを取得
	int GetMouseWheelRot()
	{
		return m_mouseWheel;
	}

	// マウスボタンが押された瞬間
	bool IsMouseDown(int button)
	{
		return(m_mouseButton & button) && !(m_mouseButtonPost & button);
	}

	// マウスボタンが押されている
	bool IsMousePress(int button)
	{
		return (m_mouseButton & button);
	}

	// マウスボタンが離された瞬間
	bool IsMouseUp(int button)
	{
		return !(m_mouseButton & button) && (m_mouseButtonPost & button);
	}
};
