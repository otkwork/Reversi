#include "Sprite.h"
#include "Time.h"
#include "ImageLoader.h"
#include "DxLib.h"

// �f�X�g���N�^
Sprite::~Sprite()
{
	Release();
}

// ���\�[�X�̓ǂݍ���
void Sprite::Load()
{
	int firstTexture = 0;
	for (auto& pair : m_animationList)
	{
		// ���X�g����<�A�j���[�V������ : �A�j���[�V�����f�[�^>�̃y�A�����o��
		// pair. first : �A�j���[�V������
		// pair.second : �A�j���[�V�����f�[�^

		// �A�j���[�V�����f�[�^����摜�p�X�����o���ēǂݍ���
		pair.second.textureId = ImageLoader::GetInstance()->Load(pair.second.textureName);

		if (!firstTexture)
		{
			firstTexture = pair.second.textureId;
		}
	}

	// �O���b�h�T�C�Y���w�肵�Ȃ������ꍇ�́A�摜����T�C�Y���擾����
	if (gridSize.IsZero())
	{
		int w, h;
		GetGraphSize(firstTexture, &w, &h);
		gridSize = Vector2(w, h);
	}
}

// ���\�[�X�̉��
void Sprite::Release()
{
	for (auto& pair : m_animationList)
	{
		ImageLoader::GetInstance()->Delete(pair.second.textureName);
	}
	m_animationList.clear();
	m_runningAnime = nullptr;
}

//�X�V
void Sprite::Update()
{
	// �A�j���[�V�������I�����ĂȂ���
	if (IsFinishAnime()) return;

	// �o�ߎ��Ԃ̉��Z
	m_elapsedTime += Time::GetInstance()->GetDeltaTime();

	// �o�ߎ��Ԃ����A�j���[�V�������Ԃ𒴂����烋�[�v����
	if (IsFinishAnime() && m_runningAnime->loopFlag)
	{
		// �ŏ��̃R�}�ɖ߂�
		m_elapsedTime = 0;
	}
}

// �`��
void Sprite::Draw(const Transform& transform)
{
	// �Đ�����A�j���[�V�������Ȃ���Ή������Ȃ�
	if (!m_runningAnime) return;

	// �`�悷��R�}���v�Z
	int gridIndex;
	if (IsFinishAnime())
	{
		// �A�j���[�V�������I�����Ă�����A�Ō�̃R�}�ԍ�
		gridIndex = m_runningAnime->gridAmount - 1;
	}
	else
	{
		// �o�ߎ��Ԃɉ������R�}�ԍ�
		gridIndex = static_cast<int>(m_elapsedTime / GetFrameTime());
	}

	// �`��
	DrawRectRotaGraph(
		static_cast<int>(transform.position.x), static_cast<int>(transform.position.y),
		static_cast<int>(gridSize.x) * gridIndex, 0,
		static_cast<int>(gridSize.x), static_cast<int>(gridSize.y),
		transform.scale,
		transform.angle,
		m_runningAnime->textureId,
		true,
		flipX, flipY
	);
#ifdef _DEBUG
	// Grid�g�̕\��
	DrawBox(
		static_cast<int>(transform.position.x - gridSize.x * transform.scale / 2),
		static_cast<int>(transform.position.y - gridSize.y * transform.scale / 2),
		static_cast<int>(transform.position.x + gridSize.x * transform.scale / 2),
		static_cast<int>(transform.position.y + gridSize.y * transform.scale / 2),
		GetColor(255, 0, 0), false
	);
#endif
}

// �A�j���[�V�����o�^
void Sprite::Register(const char* textureName)
{
	Register("-", Animation(textureName, 1, 0, false));
}

void Sprite::Register(const char* animeName, const Animation& animation)
{
	// ���X�g�ɓo�^
	m_animationList.emplace(animeName, animation);

	// �ŏ��ɓo�^���ꂽ�A�j���[�V�������Đ����A�j���[�V�����Ƃ���
	if (!m_runningAnime)
	{
		m_runningAnime = &m_animationList.begin()->second;
	}
}

// �A�j���[�V�����̍Đ�
void Sprite::Play(const char* animeName)
{
	// �w�肳�ꂽ�A�j���[�V���������X�g����擾
	const auto& pair = m_animationList.find(animeName);

	// ���o�^�̃A�j���[�V������
	if (pair == m_animationList.end()) return;

	// ���ݍĐ����̃A�j���[�V�����Ɠ���
	if (m_runningAnime == &pair->second) return;

	// �A�j���[�V�����̐؂�ւ�
	m_runningAnime = &pair->second;
	m_elapsedTime = 0;
}
