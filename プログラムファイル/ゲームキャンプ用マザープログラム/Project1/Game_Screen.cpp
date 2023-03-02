//-----
//gameselect_screen.cpp
//-----

//ヘッダーファイル
#include "Game_Screen.h"
#include "MainGameSistem.h"
#include "Task.h"

//コンストラクタ
CGameScreen::CGameScreen()
{
	m_state = GAME_SCREEN;
	m_timer = 0;
	TaskEx::InitTaskList();     //タスクシステム初期化
	//TaskEx::AddTask(new CMainSistem(0.2f));
	TaskEx::AddTask(new CBgm(1,150,0.8f));
	m_image = LoadGraph("media_\\img\\GameStage.png");
	//clsDx();
}

//デストラクタ
CGameScreen::~CGameScreen(){}

//実行処理
void CGameScreen::Update()
{
	m_timer++;
	try {
		TaskEx::RunTask();     //タスクの更新
	}
	catch (CAST menu) {
		if (menu == GAMECLEAR) { m_state = GAMECLEAR_SCREEN;}
		if (menu == GAMEOVER) { m_state = GAMEOVER_SCREEN; }
	}
	if (m_timer % MAX_FPS == 0) TaskEx::DleteDeathTask();//不要タスクの削除

#if defined(_DEBUG)|defined(DEBUG)
	//if (CheckHitKey(KEY_INPUT_C)) m_state = TITLE_SCREEN;
	if (CheckHitKey(KEY_INPUT_D)) m_state = GAMEOVER_SCREEN;
	if (CheckHitKey(KEY_INPUT_E)) m_state = GAMECLEAR_SCREEN;
#endif
}

//描画
void CGameScreen::Draw() const
{
	ClearDrawScreen();
	DrawGraph(0, 0, m_image, false);
	TaskEx::DrawTask();     //タスクの描画

#if defined(_DEBUG) | defined(DEBUG)
	clsDx();
	DrawString(10, 100, "SELECT Screen Hit C key to Title Screen", GetColor(255, 255, 255));
	DrawString(10, 120, "              Hit D key to GameOver Screen", GetColor(255, 255, 255));
	DrawString(10, 140, "              Hit E key to GameClear Screen", GetColor(255, 255, 255));
#endif
}