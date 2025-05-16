#include "Player.h"
#include "Vector2.h"
#include "Disc.h"
#include "Input.h"
#include "Stage.h"

bool Player::Play()
{
	Vector2 mousePos = Vector2(0, 0);
	Vector2 discPos = Vector2(0, 0);
	switch (m_type)
	{
	case PlayerType::Player:
		// マウスカーソルの座標を取得
		mousePos = Input::GetInstance()->GetMousePoint();

		if (!Stage::IsOnBoard(mousePos)) return false;

		discPos = Stage::ScreenToBoard(mousePos);

		if (std::find(m_canPutList.begin(), m_canPutList.end(), discPos) == m_canPutList.end()) return false;
		if (m_stageNode->FixPlay(discPos, m_color))
		{
			return true;
		}
		return false;

		break;

	case PlayerType::CPU:
		int randomIndex = GetRand(m_canPutList.size() - 1);
		m_stageNode->FixPlay(m_canPutList[randomIndex], m_color);
		return true;
		break; 
	}
}

bool Player::CanPutList()
{
	m_canPutList = m_stageNode->GetCanPutList(m_color);
	return m_canPutList.size() > 0;
}