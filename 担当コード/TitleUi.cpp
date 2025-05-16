#include "TitleUi.h"
#include "SceneTitle.h"
#include "Screen.h"

TitleUi::TitleUi(const Vector2& position, SceneTitle* sceneTitle) :
	m_button(Size, MOUSE_INPUT_LEFT, std::bind(&TitleUi::OnClick, this)),
	m_sceneTitle(sceneTitle)
{
	m_blackTransform.position = Screen::Center + Vector2(-TextOffset.x, TextOffset.y);
	m_whiteTransform.position = Screen::Center + Vector2( TextOffset.x, TextOffset.y);

	m_transform.position = position;

	m_blackImg.Register("black_text.png");
	m_whiteImg.Register("white_text.png");
	m_startImg.Register("start.png");
}

void TitleUi::Load()
{
	// ‰æ‘œ‚Ì“Ç‚Ýž‚Ý
	m_blackImg.Load();
	m_whiteImg.Load();
	m_startImg.Load();
}

void TitleUi::Release()
{
	// ‰æ‘œ‚Ì‰ð•ú
	m_blackImg.Release();
	m_whiteImg.Release();
	m_startImg.Release();
}

void TitleUi::Update()
{
	m_button.Update(m_transform.position);
}

void TitleUi::Draw()
{
	m_blackImg.Draw(m_blackTransform);
	m_whiteImg.Draw(m_whiteTransform);
	m_startImg.Draw(m_transform);

#ifdef _DEBUG
	m_button.Draw(m_transform.position);
#endif
}

void TitleUi::OnClick()
{
	m_sceneTitle->IsStart();
}