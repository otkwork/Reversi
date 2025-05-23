#include "SelectButton.h"
#include "SceneTitle.h"

SelectButton::SelectButton(Player::PlayerType playerType, Disc::Color color, const char* selectName, const Vector2& position, SceneTitle* sceneTitle) :
	Actor("TitleButton", selectName, position),
	m_button(Size, MOUSE_INPUT_LEFT, std::bind(&SelectButton::OnClick, this)),
	m_playerType(playerType),
	m_color(color),
	m_sceneTitle(sceneTitle)
{
	m_transform.position = position;
}

void SelectButton::Update()
{
	Actor::Update();
	m_button.Update(m_transform.position);
}

void SelectButton::Draw()
{
	// 条件を満たしていない場合はボタンを暗化させる
	if (m_sceneTitle->GetPlayerType(m_color) != m_playerType)
	{
		// 以降、輝度を下げて描画する
		SetDrawBright(100, 100, 100);
	}

	// 本来の描画処理
	Actor::Draw();

	// 輝度の設定を元に戻す
	SetDrawBright(255, 255, 255);

#ifdef _DEBUG
	m_button.Draw(m_transform.position);
#endif
}

void SelectButton::OnClick()
{
	m_sceneTitle->SetPlayerType(m_playerType, m_color);
}