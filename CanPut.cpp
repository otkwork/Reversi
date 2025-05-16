#include "CanPut.h"
#include "Screen.h"
#include "Stage.h"

CanPut::CanPut(Stage* stage) :
	m_stage(stage)
{
	m_canPutBlack.Register("Black_Can.png");
	m_canPutWhite.Register("White_Can.png");
}

void CanPut::Load()
{
	m_canPutBlack.Load();
	m_canPutWhite.Load();
}

void CanPut::Release()
{
	m_canPutBlack.Release();
	m_canPutWhite.Release();
}

void CanPut::Draw()
{
	for (Vector2 canPut : m_stage->GetCanPutList(m_stage->GetColor()))
	{
		m_canPutTransform.position = m_stage->BoardToScreen(canPut);
		if (m_stage->GetColor() == Disc::Color::Black)	// çï
		{
			m_canPutBlack.Draw(m_canPutTransform);
		}
		else
		{
			m_canPutWhite.Draw(m_canPutTransform);
		}
	}
}