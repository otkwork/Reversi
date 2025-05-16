#pragma once
#include "Actor.h"
#include "Sprite.h"
#include "Disc.h"
#include "CanPut.h"
#include <vector>

class Stage : public Actor
{
private:
	enum class Direction
	{
		Right,
		UnderRight,
		Under,
		UnderLeft,
		Left,
		UpperLeft,
		Upper,
		UpperRight,

		Length,
	};
		
	static constexpr int Column = 8;	// 横のマス数(列)
	static constexpr int Row = 8;		// 縦のマス数(行)0
	static constexpr int FlipCount = 1;	// 石がひっくり返る連結数

	static constexpr Vector2 TopLeft = Vector2(160, 80);	// 盤面の左上座標

	Disc* m_board[Column][Row];	// 盤面

	std::list<Vector2> m_canPutList;
	Disc::Color m_color;

	// 石をひっくり返す再起関数
	bool CheckFlip(int x, int y, Disc::Color color, std::list<Disc*>& flipList, const Vector2& direction);

	// 別の色で挟んだ時の関数
	bool SandFlip(int x, int y, std::list<Disc*>& flipList);

public:
	Stage();

	// 指定された座標が盤面の中かどうか
	static const bool IsOnBoard(const Vector2& screenPos);

	// マス目から描画座標への変換
	static const Vector2 BoardToScreen(const Vector2& boardPos);

	// 描画座標からマス目への変換
	static const Vector2 ScreenToBoard(const Vector2& screenPos);

	// プレイヤーの操作が終了したぷよを盤面に配置する
	bool FixPlay(const Vector2& boardPos, Disc::Color color);

	// 置ける場所に半透明の石を表示する
	void ChangeTurn(Disc::Color color);
	
	// プレイヤーが置いた石から八方向に関数を飛ばす関数
	void ParentCheckFlip(int x, int y, Disc::Color color, std::list<Disc*>& flipList);

	// Listの石をひっくり返す
	void FlipDisc(int x, int y, Disc::Color color);

	// 指定したマスが空いているかどうか
	bool IsEmpty(const Vector2& boardPos);

	// 置けるマスのリストを取得
	std::vector<Vector2> GetCanPutList(Disc::Color color);

	Disc::Color GetColor() { return m_color; }

	int GetDiscAmount(Disc::Color color);
};
