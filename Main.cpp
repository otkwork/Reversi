#include"GameMain.h"
#include "DxLib.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	//ゲームの起動
	GameMain gameMain;
	gameMain.Run();

	// ＤＸライブラリの後始末
	DxLib_End();

	return 0;
}