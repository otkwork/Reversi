#pragma once
#include "Node.h"
#include "Button.h"
#include "Sprite.h"
#include <functional>	// std::function���g���̂ɕK�v
#include "DxLib.h"

class SceneTitle;

class TitleUi : public Node
{
private:
	static constexpr Vector2 Size = Vector2(100.0f, 60.0f);	// �{�^���̃T�C�Y
	static constexpr Vector2 TextOffset = Vector2(150, 140);	// ��������̋���

	Button m_button;	// �{�^��
	SceneTitle* m_sceneTitle;
	Transform m_transform;
	Sprite m_startImg;
	Sprite m_blackImg;
	Sprite m_whiteImg;

	Transform m_blackTransform;
	Transform m_whiteTransform;

protected:
	virtual void Load() override;
	virtual void Release() override;
	virtual void Update() override;
	virtual void Draw() override;

public:
	// �R���X�g���N�^
	TitleUi(const Vector2& position, SceneTitle* sceneTitle);

	// �{�^���������ꂽ�Ƃ��ɌĂ΂��R�[���o�b�N�֐�
	void OnClick();
};