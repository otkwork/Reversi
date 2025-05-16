#pragma once
#include <list>

class Node
{
private:
	Node* m_parent;						// �e�̃|�C���^
	std::list<Node*> m_children;		// �q�̃|�C���^���X�g
	std::list<Node*> m_removeChildren;	// �폜����q�̃|�C���^���X�g
	bool m_isLoaded;					// Load�֐������s�������ǂ���
	bool m_isDestroyed;					// Destroy�֐������s�������ǂ���

protected:
	virtual void Load() {}		// ���\�[�X�̓ǂݍ���
	virtual void Release() {}	// ���\�[�X�̊J��
	virtual void Update() {}	// �X�V
	virtual void Draw() {}		// �`��

	void Destroy();	//���g�̍폜

	// �e��ݒ�
	void SetParent(Node* node)
	{
		m_parent = node;
	}

	// �e���擾
	Node* GetParent()
	{
		return m_parent;
	}

public:
	// �R���X�g���N�^
	Node() :
		m_parent(nullptr),				// ������������̂͊�{�^�iint, float, char, �ȂǂȂǁj
		m_isLoaded(false),
		m_isDestroyed(false) {}
	
	virtual ~Node();	// �f�X�g���N�^

	virtual void TreeLoad();	// �q�m�[�h���܂ރ��\�[�X�̓ǂݍ���
	virtual void TreeRelease();	// �q�m�[�h���܂ރ��\�[�X�̊J��
	virtual void TreeUpdate();	// �q�m�[�h���܂ލX�V
	virtual void TreeDraw();	// �q�m�[�h���܂ޕ`��

	void AddChild(Node* node);		// �q�m�[�h�̒ǉ�
	void RemoveChild(Node* node);	// �q�m�[�h�̍폜
};
