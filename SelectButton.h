#pragma once
#include "Actor.h"
#include "Button.h"
#include "Player.h"
#include "Disc.h"
#include <functional>	// std::function���g���̂ɕK�v
#include "DxLib.h"

class SceneTitle;

class SelectButton : public Actor
{
private:
	static constexpr Vector2 Size = Vector2(80, 80);	// �{�^���̃T�C�Y

	Button m_button;	// �{�^��
	Player::PlayerType m_playerType;	// �v���C���[�̃^�C�v
	Disc::Color m_color;	// �F
	SceneTitle* m_sceneTitle;

protected:
	virtual void Update() override;
	virtual void Draw() override;

public:
	// �R���X�g���N�^
	SelectButton(Player::PlayerType playerType, Disc::Color color, const char* selectName, const Vector2& position, SceneTitle* sceneTitle);

	// �{�^���������ꂽ�Ƃ��ɌĂ΂��R�[���o�b�N�֐�
	void OnClick();	
};