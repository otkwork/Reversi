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
	// ðŒ‚ð–ž‚½‚µ‚Ä‚¢‚È‚¢ê‡‚Íƒ{ƒ^ƒ“‚ðˆÃ‰»‚³‚¹‚é
	if (m_sceneTitle->GetPlayerType(m_color) != m_playerType)
	{
		// ˆÈ~A‹P“x‚ð‰º‚°‚Ä•`‰æ‚·‚é
		SetDrawBright(100, 100, 100);
	}

	// –{—ˆ‚Ì•`‰æˆ—
	Actor::Draw();

	// ‹P“x‚ÌÝ’è‚ðŒ³‚É–ß‚·
	SetDrawBright(255, 255, 255);

#ifdef _DEBUG
	m_button.Draw(m_transform.position);
#endif
}

void SelectButton::OnClick()
{
	m_sceneTitle->SetPlayerType(m_playerType, m_color);
}