#pragma once
#include "Actor.h"
#include "Sprite.h"
#include "Disc.h"
#include "CanPut.h"
#include <vector>

class Stage : public Actor
{
private:
	enum class Direction
	{
		Right,
		UnderRight,
		Under,
		UnderLeft,
		Left,
		UpperLeft,
		Upper,
		UpperRight,

		Length,
	};
		
	static constexpr int Column = 8;	// ���̃}�X��(��)
	static constexpr int Row = 8;		// �c�̃}�X��(�s)0
	static constexpr int FlipCount = 1;	// �΂��Ђ�����Ԃ�A����

	static constexpr Vector2 TopLeft = Vector2(160, 80);	// �Ֆʂ̍�����W

	Disc* m_board[Column][Row];	// �Ֆ�

	std::list<Vector2> m_canPutList;
	Disc::Color m_color;

	// �΂��Ђ�����Ԃ��ċN�֐�
	bool CheckFlip(int x, int y, Disc::Color color, std::list<Disc*>& flipList, const Vector2& direction);

	// �ʂ̐F�ŋ��񂾎��̊֐�
	bool SandFlip(int x, int y, std::list<Disc*>& flipList);

public:
	Stage();

	// �w�肳�ꂽ���W���Ֆʂ̒����ǂ���
	static const bool IsOnBoard(const Vector2& screenPos);

	// �}�X�ڂ���`����W�ւ̕ϊ�
	static const Vector2 BoardToScreen(const Vector2& boardPos);

	// �`����W����}�X�ڂւ̕ϊ�
	static const Vector2 ScreenToBoard(const Vector2& screenPos);

	// �v���C���[�̑��삪�I�������Ղ��Ֆʂɔz�u����
	bool FixPlay(const Vector2& boardPos, Disc::Color color);

	// �u����ꏊ�ɔ������̐΂�\������
	void ChangeTurn(Disc::Color color);
	
	// �v���C���[���u�����΂��甪�����Ɋ֐����΂��֐�
	void ParentCheckFlip(int x, int y, Disc::Color color, std::list<Disc*>& flipList);

	// List�̐΂��Ђ�����Ԃ�
	void FlipDisc(int x, int y, Disc::Color color);

	// �w�肵���}�X���󂢂Ă��邩�ǂ���
	bool IsEmpty(const Vector2& boardPos);

	// �u����}�X�̃��X�g���擾
	std::vector<Vector2> GetCanPutList(Disc::Color color);

	Disc::Color GetColor() { return m_color; }

	int GetDiscAmount(Disc::Color color);
};
