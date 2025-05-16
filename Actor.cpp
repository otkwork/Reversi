
#include "Actor.h"

// �R���X�g���N�^
Actor::Actor(const char* name, const char* textureName, const Vector2& position) :
	m_name(name),
	m_sprite(nullptr)
{
	m_transform.position = position;

	// �摜���ݒ肳��Ă����Sprite���N��
	if (textureName)
	{
		m_sprite = new Sprite();
		m_sprite->Register(textureName);
	}
}

// ���\�[�X�̓ǂݍ���
void Actor::Load()
{
	if (m_sprite)
	{
		m_sprite->Load();
	}
}

// ���\�[�X�̉��
void Actor::Release()
{
	if (m_sprite)
	{
		delete m_sprite;
		m_sprite = nullptr;
	}
}

// �`��
void Actor::Draw()
{
	if (m_sprite)
	{
		m_sprite->Draw(m_transform);
	}
}

// �q�m�[�h���܂ލX�V
void Actor::TreeUpdate()
{
	// Node�{����TreeUpdate�����s
	Node::TreeUpdate();

	// �X�v���C�g�̍X�V
	if (m_sprite)
	{
		m_sprite->Update();
	}
}
