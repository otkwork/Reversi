#pragma once
#include "Node.h"
#include "Vector2.h"
#include "Disc.h"
#include <vector>

class Stage;

class PlayerBase : public Node
{
public:
	virtual bool Play() = 0;		// プレイ関数
	virtual bool CanPutList() = 0;	// 置けるマスがあるかどうかを取得
};
