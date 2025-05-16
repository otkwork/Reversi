#include "Button.h"
#include "Input.h"

// �R���X�g���N�^
Button::Button(const Vector2& size, int mouseButton, std::function<void()> callbackFunction) :
	m_size(size),
	m_mouseButton(mouseButton),
	m_isClickDown(false),
	m_callbackFunction(callbackFunction)
{
}

// �}�E�X���{�^���͈͓̔��̂��邩�ǂ���
bool Button::IsMouseContain(const Vector2& position)
{
	// ��`(�{�^��)�Ɠ_(�}�E�X)�̓����蔻��
	Vector2 mousePoint = Input::GetInstance()->GetMousePoint();
	if (position.x - m_size.x / 2 <= mousePoint.x && mousePoint.x <= position.x + m_size.x / 2
	 && position.y - m_size.y / 2 <= mousePoint.y && mousePoint.y <= position.y + m_size.y / 2)
	{
		return true;
	}
	return false;
}

// �X�V
void Button::Update(const Vector2& position)
{
	// �{�^����Ń}�E�X�{�^��������������ŁA�{�^����Ń}�E�X�{�^���𗣂�����A�{�^���������ꂽ���Ƃɂ���

	// �{�^����ŁA�w�肳�ꂽ�}�E�X�{�^���������ꂽ��
	if (Input::GetInstance()->IsMouseDown(m_mouseButton))
	{
		m_isClickDown = IsMouseContain(position);
	}

	// �{�^����ŁA�w�肳�ꂽ�}�E�X�{�^���������ꂽ��
	if (m_isClickDown && Input::GetInstance()->IsMouseUp(m_mouseButton))
	{
		m_isClickDown = false;
		if (IsMouseContain(position))
		{
			// �R�[���o�b�N�֐��̌Ăяo��
			m_callbackFunction();
		}
	}
}

// �`��
void Button::Draw(const Vector2& position)
{
#ifdef _DEBUG
	DrawBox(
		static_cast<int>(position.x - m_size.x / 2), static_cast<int>(position.y - m_size.y / 2),
		static_cast<int>(position.x + m_size.x / 2), static_cast<int>(position.y + m_size.y / 2),
		GetColor(0, 0, 255), 0
	);
#endif
}
