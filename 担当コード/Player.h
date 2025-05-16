#pragma once
#include "PlayerBase.h" 
#include "Vector2.h"
#include "Disc.h"

class Stage;

class Player : public PlayerBase
{
public:
	enum class PlayerType
	{
		Player,
		CPU,
		Length
	};

private:
	static constexpr float LandingSuspendedTime = 0.5f;

	Stage* const m_stageNode;	// SceneGame上のStageノード
	
	PlayerType m_type;
	Vector2 m_position;	// 座標
	int m_playCount;	// ターン数
	bool m_isWhite;		// 今白かどうか
	float m_landingSuspendedTime;
	Disc::Color m_color;
	std::vector<Vector2> m_canPutList;

public:
	Player(Stage* const stageNode, Disc::Color color, Player::PlayerType type) :
		m_stageNode(stageNode),
		m_type(type),
		m_playCount(0),
		m_isWhite(false),
		m_landingSuspendedTime(0),
		m_color(color){}

	virtual bool Play() override;
	virtual bool CanPutList() override;
	
	bool GetIsWhite() { return m_isWhite; }
	std::vector<Vector2> GetCanPutList() { return m_canPutList; }
	PlayerType GetPlayerType() { return m_type; }
};
