#include"GameMain.h"
#include "DxLib.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	//�Q�[���̋N��
	GameMain gameMain;
	gameMain.Run();

	// �c�w���C�u�����̌�n��
	DxLib_End();

	return 0;
}