#include "UiText.h"
#include "Screen.h"
#include "Disc.h"
#include "Time.h"

UiText::UiText() :
	m_elapsedTime(0),
	m_drawType(Type::None)
{
	m_transform.position = Screen::Center;
	m_transform.scale = 0.3f;
	m_passImg.Register("pass.png");
	m_blackWinImg.Register("black_win.png");
	m_whiteWinImg.Register("white_win.png");
	m_DrawImg.Register("draw.png");
}

void UiText::Load()
{
	m_passImg.Load();
	m_blackWinImg.Load();
	m_whiteWinImg.Load();
	m_DrawImg.Load();
}

void UiText::Release()
{
	m_passImg.Release();
	m_blackWinImg.Release();
	m_whiteWinImg.Release();
	m_DrawImg.Release();
}

void UiText::Update()
{
	m_passImg.Update();
	m_blackWinImg.Update();
	m_whiteWinImg.Update();
	m_DrawImg.Update();
}

void UiText::Draw()
{
	// ƒpƒX‚ÌŽž‚¾‚¯ŽžŠÔŒo‰ß‚Å•`‰æ‚ðŽ~‚ß‚é
	if (m_drawType != UiText::Type::None) m_elapsedTime += Time::GetInstance()->GetDeltaTime();
	if (m_drawType == Type::Pass && m_elapsedTime > DrawTime)
	{
		m_drawType = Type::None;
		return;
	}

	switch (m_drawType)
	{
	case Type::None:
		break;

	case Type::Pass:
		m_passImg.Draw(m_transform);
		break;
		
	case Type::WinBlack:
		m_blackWinImg.Draw(m_transform);
		break;

	case Type::WinWhite:
		m_whiteWinImg.Draw(m_transform);
		break;

	case Type::Draw:
		m_DrawImg.Draw(m_transform);
		break;
	}
}

void UiText::SetDrawType(UiText::Type drawType)
{
	m_drawType = drawType; 
	m_elapsedTime = 0;
}