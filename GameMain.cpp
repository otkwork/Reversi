#include "GameMain.h"
#include "GameConfig.h"
#include "Screen.h"
#include "SceneManager.h"
#include "SceneGame.h"
#include "SceneTitle.h"
#include "Input.h"
#include "Time.h"
#include "Fade.h"
#include "ImageLoader.h"
#include "DxLib.h"

//デストラクタ
GameMain::~GameMain()
{
	// 自作スクリーンの破棄
	DeleteGraph(m_screen);

	// シーンの破棄
	delete m_sceneManager;
	m_sceneManager = nullptr;

	//DxLib 終了
	DxLib_End();
}

//メインループ実行
void GameMain::Run()
{
	SetMainWindowText(GameConfig::Title); //ウィンドウタイトル
	SetAlwaysRunFlag(GameConfig::AlwaysRunFlag);//非アクティブモードで動作する
	ChangeWindowMode(GameConfig::WindowMode);//ウィンドウモードで起動
	SetGraphMode(Screen::Width, Screen::Height, GameConfig::ColorBit);//ウィンドウサイズ

	//DXライブラリの初期化
	if (DxLib_Init())
	{
		throw - 1;
	}

	// シーン起動
	m_sceneManager = new SceneManager(new SceneTitle());

	// スクリーン作成
	m_screen = MakeScreen(Screen::Width, Screen::Height);

	//ゲームループ
	while (ProcessMessage() == 0)
	{
		// 入力システムの更新
		Input::GetInstance()->Update();

		// 時間の更新
		Time::GetInstance()->Update();

		//ESCキーが押されたら終了
		if (Input::GetInstance()->IsKeyDown(KEY_INPUT_ESCAPE))
		{
			break;
		}

		// シーンの更新
		m_sceneManager->Update();

		// 自作スクリーンに描画
		SetDrawScreen(m_screen);

		//画面に描かれているものを全部消す
		ClearDrawScreen();

		// シーンの描画
		m_sceneManager->Draw();
		
#ifdef _DEBUG
		// 画像ローダー
		ImageLoader::GetInstance()->Draw();
#endif

		// フェード
		Fade::GetInstance()->Update(m_screen);

		// 自作スクリーンを裏画面に描画
		SetDrawScreen(DX_SCREEN_BACK);
		ClearDrawScreen();
		DrawGraph(0, 0, m_screen, false);

		//裏画面と表画面をひっくり返す
		ScreenFlip();
	}
}
