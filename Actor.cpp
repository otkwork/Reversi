
#include "Actor.h"

// コンストラクタ
Actor::Actor(const char* name, const char* textureName, const Vector2& position) :
	m_name(name),
	m_sprite(nullptr)
{
	m_transform.position = position;

	// 画像が設定されていればSpriteを起動
	if (textureName)
	{
		m_sprite = new Sprite();
		m_sprite->Register(textureName);
	}
}

// リソースの読み込み
void Actor::Load()
{
	if (m_sprite)
	{
		m_sprite->Load();
	}
}

// リソースの解放
void Actor::Release()
{
	if (m_sprite)
	{
		delete m_sprite;
		m_sprite = nullptr;
	}
}

// 描画
void Actor::Draw()
{
	if (m_sprite)
	{
		m_sprite->Draw(m_transform);
	}
}

// 子ノードを含む更新
void Actor::TreeUpdate()
{
	// Node本来のTreeUpdateを実行
	Node::TreeUpdate();

	// スプライトの更新
	if (m_sprite)
	{
		m_sprite->Update();
	}
}
