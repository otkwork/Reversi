#pragma once

struct LoadData
{
public:
	const int id;	// ���[�h�������\�[�X�n���h��
	int count;		// id�����p����Ă����

	LoadData(int id) :
		id(id),
		count(0) {}
};
