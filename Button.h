#pragma once
#include "Vector2.h"
#include <functional>	// std::function���g���̂ɕK�v

class Button
{
private:
	Vector2 m_size;
	int m_mouseButton;	// �}�E�X�̂ǂ̃{�^���ɔ������邩
	bool m_isClickDown;	// ���̃{�^����������Ă��邩
	std::function<void()> m_callbackFunction;	// �{�^���������ꂽ�Ƃ��Ɏ��s����֐�

	// �}�E�X���{�^���͈͓̔��ɂ��邩�ǂ���
	bool IsMouseContain(const Vector2& position);

public:
	 // �R���X�g���N�^
	Button(const Vector2& size, int mouseButton, std::function<void()> callbackFunction);

	void Update(const Vector2& position);	// �X�V
	void Draw(const Vector2& position);		// �`��
};
