//*****
//wim_main.cpp
//*****
#include "Mylib.h"
#include "resource.h"
#include "Game.h"

//-----
//ローカル変数
//-----
CGame*     g_pMain = NULL;

//-----
//ローカル関数
//-----
void       win_main_init();
void       win_main_loop();
void       win_main_dest();

//-----
//ウィンドウ画面のメイン
//-----
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	double dNextTime = GetNowCount();
	win_main_init();

	while (!ProcessMessage()) {
		dNextTime += FRAMETIME_MS;           //60FPS処理
		if (dNextTime > GetNowCount()) {
			WaitTimer((int)dNextTime - GetNowCount());
		}
		win_main_loop();
#if defined(_DEBUG)|defined(DEBUG)
		if (CheckHitKey(KEY_INPUT_ESCAPE))break;
#endif
	}

	win_main_dest();
}

//-----
//メイン初期化処理
//-----
void win_main_init()
{
	//DirectX関係

	ChangeWindowMode(WINDOW_SCREEN);
	if (WINDOW_SCREEN)
	{
		SetGraphMode(WINDOW_W, WINDOW_H, 32);
		//アイコンファイルの読み込み
		SetWindowIconID(IDI_ICON2);

		SetMainWindowText(_T("ゲームキャンプ用プロジェクト"));
	}
	if (DxLib_Init() == -1) //ライブラリの初期化処理
		return;

	RANDMIZE();
	SetDrawScreen(DX_SCREEN_BACK);

	//GAME関係
	g_pMain = new CGame();
}

//-----
//メインループ処理
//-----
void win_main_loop()
{
	//メイン処理
	g_pMain->Update();
	g_pMain->Draw();
	ScreenFlip();
}

//-----
//メイン終了処理
//-----
void win_main_dest()
{
	delete g_pMain;
	g_pMain = NULL;
}