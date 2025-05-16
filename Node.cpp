#include "Node.h"

// �f�X�g���N�^
Node::~Node()
{
	// �q�m�[�h�����ׂ�delete����
	for (Node* node : m_children)
	{
		delete node;
	}
	m_children.clear();
}

// ���g�̍폜
void Node::Destroy()
{
	// �e�����Ȃ���Ή������Ȃ�
	if (!m_parent) return;

	// ���ɍ폜�ς݂Ȃ牽�����Ȃ�
	if (m_isDestroyed) return;

	// �폜�t���O�𗧂Ă�
	m_isDestroyed = true;

	// �e�Ɏ��g���폜������
	m_parent->RemoveChild(this);
}

// �q�m�[�h���܂ރ��\�[�X�̓ǂݍ���
void Node::TreeLoad()
{
	// ���g
	if (!m_isLoaded)
	{
		Load();
		m_isLoaded = true;
	}

	// �q
	for (Node* node : m_children)
	{
		node->TreeLoad();
	}
}

// �q�m�[�h���܂ރ��\�[�X�̉��
void Node::TreeRelease()
{
	// ���g
	if (m_isLoaded)
	{
		Release();
		m_isLoaded = false;
	}

	// �q
	for (Node* node : m_children)
	{
		node->TreeRelease();
	}
}

// �q�m�[�h���܂ލX�V
void Node::TreeUpdate()
{
	// ���g
	Update();

	// �q
	for (Node* node : m_children)
	{
		node->TreeUpdate();
	}

	// �q�̍폜
	for (Node* node : m_removeChildren)
	{
		node->TreeRelease();
		m_children.remove(node);
		delete node;
	}
	m_removeChildren.clear();
}

// �q�m�[�h���܂ޕ`��
void Node::TreeDraw()
{
	// ���g
	Draw();

	// �q
	for (Node* node : m_children)
	{
		node->TreeDraw();
	}
}

// �q�m�[�h�̒ǉ�
void Node::AddChild(Node* node)
{
	// �q�ɑ΂��Đe��ݒ�
	node->SetParent(this);

	// �q��o�^
	m_children.push_back(node);

	// ���̃��\�[�X�ǂݍ���
	node->TreeLoad();
}

// �q�m�[�h�̍폜
void Node::RemoveChild(Node* node)
{
	m_removeChildren.push_back(node);
}
