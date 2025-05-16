#pragma once
#include "Actor.h"
#include "Button.h"
#include "Player.h"
#include "Disc.h"
#include <functional>	// std::functionを使うのに必要
#include "DxLib.h"

class SceneTitle;

class SelectButton : public Actor
{
private:
	static constexpr Vector2 Size = Vector2(80, 80);	// ボタンのサイズ

	Button m_button;	// ボタン
	Player::PlayerType m_playerType;	// プレイヤーのタイプ
	Disc::Color m_color;	// 色
	SceneTitle* m_sceneTitle;

protected:
	virtual void Update() override;
	virtual void Draw() override;

public:
	// コンストラクタ
	SelectButton(Player::PlayerType playerType, Disc::Color color, const char* selectName, const Vector2& position, SceneTitle* sceneTitle);

	// ボタンが押されたときに呼ばれるコールバック関数
	void OnClick();	
};