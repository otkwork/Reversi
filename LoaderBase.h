#pragma once
#include <map>
#include "LoadData.h"

// ���\�[�X�̊�ꃍ�[�_�[�N���X
class LoaderBase
{
private:
	const char* RootPath = "Resource/";

	std::map<const char*, LoadData> m_dataList;	// ���\�[�X�ꗗ

#ifdef _DEBUG
	static const int FontSize = 10;
	static const int FontThick = 3;
	static const int FontMargin= 2;
	int m_fontHandle;
#endif

protected:
	LoaderBase();
	virtual ~LoaderBase();

	virtual int LoadResource(const char* path) = 0;	// ���\�[�X�̓ǂݍ���
	virtual void DeleteResource(int id) = 0;		// ���\�[�X�̔j��

public:
	int Load(const char* path);		// ���\�[�X�̓ǂݍ���
	void Delete(const char* path);	// ���\�[�X�̔j��

#ifdef _DEBUG
	void Draw();
#endif
};