#include "Stage.h"
#include "SceneGame.h"
#include "CanPut.h"
#include "Player.h"

Stage::Stage() :
	Actor(
		"Stage",
		"stage.png",
		TopLeft + Vector2(Disc::Size.x * Column, Disc::Size.y * Row) / 2
	),
	m_board{ nullptr },
	m_color(Disc::Color::Black)
{
	for (int i = 0; i < 4; ++i)
	{
		Disc* disc = new Disc(static_cast<Disc::Color>(static_cast<int>(i % 3 != 0)), Vector2(3 + i % 2, 3 + i / 2));
		m_board[3 + i % 2][3 + i / 2] = disc;
		AddChild(disc);
	}
}

// 指定された座標が盤面の中かどうか
const bool Stage::IsOnBoard(const Vector2& screenPos)
{
	if (screenPos.x < TopLeft.x) return false;
	if (screenPos.y < TopLeft.y) return false;
	if (TopLeft.x + Disc::Size.x * Column <= screenPos.x) return false;
	if (TopLeft.y + Disc::Size.y * Row <= screenPos.y) return false;
	return true;
}

// マス目から描画座標への変換
const Vector2 Stage::BoardToScreen(const Vector2& boardPos)
{
	return TopLeft + Disc::Size / 2 + Vector2(boardPos.x * Disc::Size.x, boardPos.y * Disc::Size.y);
}

// 描画座標からマス目への変換
const Vector2 Stage::ScreenToBoard(const Vector2& screenPos)
{
	Vector2 tmp = screenPos - TopLeft;
	return Vector2(static_cast<int>(tmp.x / Disc::Size.x), static_cast<int>(tmp.y / Disc::Size.y));
}

// プレイヤーの操作が終了したぷよを盤面に配置する
bool Stage::FixPlay(const Vector2& boardPos, Disc::Color color)
{
	if (!IsEmpty(boardPos)) return false;

	Disc* disc = new Disc(color, boardPos);

	int x = static_cast<int>(boardPos.x);
	int y = static_cast<int>(boardPos.y);

	disc->FixPlay(boardPos);
	m_board[x][y] = disc;
	AddChild(disc);



	FlipDisc(x, y, color);



	return true;
}

// 置ける場所に半透明の石を表示する
void Stage::ChangeTurn(Disc::Color color)
{
	m_color = color;
}

// 空いているかどうか
bool Stage::IsEmpty(const Vector2& boardPos)
{
	int x = static_cast<int>(boardPos.x);
	int y = static_cast<int>(boardPos.y);


	return !m_board[x][y];
}

void Stage::ParentCheckFlip(int x, int y, Disc::Color color, std::list<Disc*>& flipList)
{
	static const Vector2 Director[8] = {
		Vector2(1, 0),
		Vector2(1, 1),
		Vector2(0, 1),
		Vector2(-1, 1),
		Vector2(-1, 0),
		Vector2(-1, -1),
		Vector2(0, -1),
		Vector2(1, -1),
	};

	for (auto dir : Director)
	{
		CheckFlip(x + static_cast<int>(dir.x), y + static_cast<int>(dir.y), color, flipList, dir);
	}
}

bool Stage::CheckFlip(int x, int y, Disc::Color color, std::list<Disc*>& flipList, const Vector2& direction)
{
	// 盤面の中かどうか
	if (x < 0 || x >= Column || y < 0 || y >= Row)
	{
		return false;
	}

	// 石があるか
	if (!m_board[x][y])
	{
		return false;
	}

	// 置いた石と同じ色？
	if (m_board[x][y]->GetColor() == color)
	{
		return true;
	}

	if (CheckFlip(x + static_cast<int>(direction.x), y + static_cast<int>(direction.y), color, flipList, direction))
	{
		// ひっくり返す予定リストに登録
		flipList.push_back(m_board[x][y]);
		return true;
	}

	return false;
}

bool Stage::SandFlip(int x, int y, std::list<Disc*>& flipList)
{
	flipList.push_back(m_board[x][y]);
	return true;
}


void Stage::FlipDisc(int x, int y, Disc::Color color)
{	
	std::list<Disc*> flipList;

	ParentCheckFlip(x, y, color, flipList);

	for (Disc* disc : flipList)
	{
		// 石をひっくり返す
		disc->Flip(disc->GetColor());
	}
}

std::vector<Vector2> Stage::GetCanPutList(Disc::Color color)
{
	std::vector<Vector2> canPutList;

	for (int x = 0; x < 8; ++x)
	{
		for (int y = 0; y < 8; ++y)
		{
			if (m_board[x][y]) continue;
			std::list<Disc*> flipList;
			ParentCheckFlip(x, y, color, flipList);
			if (!flipList.empty())
			{
				canPutList.push_back(Vector2(x, y));
			}
		}
	}
	return canPutList;
}

int Stage::GetDiscAmount(Disc::Color color)
{
	int discAmount = 0;

	for (int x = 0; x < 8; ++x)
	{
		for (int y = 0; y < 8; ++y)
		{
			if (!m_board[x][y]) continue;
			// 指定した色と一緒なら加算
			if (m_board[x][y]->GetColor() == color)
			{
				discAmount++;
			}
		}
	}
	return discAmount;
}