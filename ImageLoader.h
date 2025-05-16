#pragma once
#include "LoaderBase.h"

// �摜���[�_�[�N���X
class ImageLoader : public LoaderBase
{
private:
	ImageLoader() {}

protected:
	virtual int LoadResource(const char* path) override;
	virtual void DeleteResource(int id) override;

public:
	static ImageLoader* GetInstance()
	{
		static ImageLoader instance;
		return &instance;
	}
};
