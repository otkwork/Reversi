#include "LoaderBase.h"
#include "DxLib.h"
#include <string>

LoaderBase::LoaderBase()
{
#ifdef _DEBUG
	m_fontHandle = CreateFontToHandle(nullptr, FontSize, FontThick);
#endif
}

LoaderBase::~LoaderBase()
{
#ifdef _DEBUG
	DeleteFontToHandle(m_fontHandle);
#endif
}

// ���\�[�X�̓ǂݍ���
int LoaderBase::Load(const char* path)
{
	LoadData* loadData = nullptr;

	// ���łɓǂݍ���ł��邩���`�F�b�N
	auto data = m_dataList.find(path);
	if (data != m_dataList.end())
	{
		// �ǂݍ���ł����̂ŁA�ǂݍ��ݍς݂̃f�[�^�ŏ�������
		loadData = &data->second;
	}
	else
	{
		// �ǂݍ���ł��Ȃ������̂ŁA�V�K�Ƀ��[�h���ēo�^����

		// ���[�h
		std::string fullPath;
		fullPath += RootPath;
		fullPath += path;
		int id = LoadResource(fullPath.c_str());

		// �o�^
		auto result = m_dataList.emplace(path, LoadData(id));

		// �o�^�����f�[�^�ŏ�������
		loadData = &result.first->second;
	}

	// �ǂݍ��݃J�E���g�𑝂₷
	loadData->count++;

	return loadData->id;
}

// ���\�[�X�̔j��
void LoaderBase::Delete(const char* path)
{
	LoadData* loadData = nullptr;

	// �ǂݍ���ł��邩�`�F�b�N
	auto data = m_dataList.find(path);
	if (data == m_dataList.end())
	{
		// �ǂݍ���ł��Ȃ������̂ŉ������Ȃ�
		return;
	}
	loadData = &data->second;

	// �ǂݍ��݃J�E���g�����炷
	loadData->count--;

	// �ǂݍ��݃J�E���g��0�ɂȂ�����j������
	if (loadData->count <= 0)
	{
		// �j��
		DeleteResource(loadData->id);

		// �ꗗ������폜
		m_dataList.erase(path);
	}
}

#ifdef _DEBUG
#include "Screen.h"
void LoaderBase::Draw()
{
	int row = 0;
	for (auto data : m_dataList)
	{
		std::string str;
		str = data.first;
		str += " : ";
		str += std::to_string(data.second.count);

		int width = GetDrawStringWidthToHandle(
			str.c_str(),
			static_cast<int>(str.length()),
			m_fontHandle
		);
		width += FontMargin;

		DrawStringToHandle(
			Screen::Right - width, row * FontSize + FontMargin,
			str.c_str(),
			GetColor(255, 0, 255),
			m_fontHandle
		);
		row++;
	}
}
#endif
