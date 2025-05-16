#pragma once
#include "Node.h"
#include "Vector2.h"
#include "Disc.h"
#include <vector>

class Stage;

class PlayerBase : public Node
{
public:
	virtual bool Play() = 0;		// �v���C�֐�
	virtual bool CanPutList() = 0;	// �u����}�X�����邩�ǂ������擾
};
