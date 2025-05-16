#pragma once
#include "Node.h"
#include "Transform.h"
#include "Sprite.h"
#include <string>

class Actor : public Node
{
protected:
	std::string m_name;		// �I�u�W�F�N�g��
	Transform m_transform;	// �p�����
	Sprite* m_sprite;		// 2D�摜

	virtual void Load() override;		// ���\�[�X�̓ǂݍ���
	virtual void Release() override;	// ���\�[�X�̉��
	virtual void Draw() override;		// �`��

public:
	// �R���X�g���N�^
	Actor(
		const char* name,
		const char* textureName = nullptr,
		const Vector2& position = Vector2()
	);

	// �q�m�[�h���܂ލX�V
	virtual void TreeUpdate() override;

	// �p���̎擾
	const Transform& GetTransform() const
	{
		return m_transform;
	}

	// ���W�̎擾
	const Vector2& GetPosition() const
	{
		return m_transform.position;
	}

	// ���W�̐ݒ�
	void SetPosition(const Vector2& pos)
	{
		m_transform.position = pos;
	}

	// ���O�̎擾
	const std::string& GetName() const
	{
		return m_name;
	}
};
