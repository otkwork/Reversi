#include "Input.h"
#include "DxLib.h"
#include <cstring>

// �X�V
void Input::Update()
{
	// �L�[�{�[�h

	// �O�t���[���̃L�[���͏�Ԃ�ۑ�
	std::memcpy(m_keyStatePost, m_keyState, sizeof(char) * KeyStateNum);

	// ���t���[���̃L�[���͏�Ԃ��擾
	GetHitKeyStateAll(m_keyState);

	// WASD�����͂��ꂽ��A�J�[�\���L�[�����͂��ꂽ���Ƃɂ���
	if (m_keyState[KEY_INPUT_W]) m_keyState[KEY_INPUT_UP] = 1;
	if (m_keyState[KEY_INPUT_A]) m_keyState[KEY_INPUT_LEFT] = 1;
	if (m_keyState[KEY_INPUT_S]) m_keyState[KEY_INPUT_DOWN] = 1;
	if (m_keyState[KEY_INPUT_D]) m_keyState[KEY_INPUT_RIGHT] = 1;


	// �}�E�X

	// �O�t���[���̃}�E�X�{�^�����͏�Ԃ�ۑ�
	m_mouseButtonPost = m_mouseButton;

	// ���݂̃}�E�X�{�^�����͏�Ԃ��擾
	m_mouseButton = DxLib::GetMouseInput();

	// �}�E�X�ʒu���擾
	int mouseX = 0;
	int mouseY = 0;
	DxLib::GetMousePoint(&mouseX, &mouseY);
	m_mousePoint = Vector2(mouseX, mouseY);

	// �}�E�X�z�C�[�����擾
	m_mouseWheel = DxLib::GetMouseWheelRotVol();

	//�}�E�X�̍��{�^�������͂��ꂽ��AZ�L�[�����͂��ꂽ���Ƃɂ���
	if (m_mouseButton & MOUSE_INPUT_LEFT) m_keyState[KEY_INPUT_Z] = 1;
}

// �����ꂩ�̃L�[�������ꂽ�u��
bool Input::IsAnyKeyDown()
{
	// �}�E�X
	if (m_mouseButton && (m_mouseButton ^ m_mouseButtonPost))
	{
		return true;
	}

	// �L�[�{�[�h
	// �z��̔�r
	if (std::memcmp(m_keyStatePost, m_keyState, sizeof(char) * KeyStateNum) == 0)
	{
		return false;
	}

	// �z�񂩂�1��T���o��
	return std::memchr(m_keyState, 1, sizeof(char) * KeyStateNum) != nullptr;
}