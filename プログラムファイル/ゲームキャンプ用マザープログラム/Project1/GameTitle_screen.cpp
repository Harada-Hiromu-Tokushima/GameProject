//-----
//gametitle_screen.cpp
//-----


//ヘッダーファイル
#include "GameTitle_screen.h"
#include "Title.h"
#include "TaskSystemEx.h"

//コンストラクタ
CTitleScreen::CTitleScreen()
{
	m_state = TITLE_SCREEN;
	m_timer = 0;
	TaskEx::InitTaskList();
	TaskEx::AddTask(new Ctitle(0.6f));
	TaskEx::AddTask(new CBgm(0,150,0.8f));
}

//デストラクタ
CTitleScreen::~CTitleScreen(){
	clsDx();
}

//実行処理
void CTitleScreen::Update()
{
	try {
		TaskEx::RunTask();
	}
	catch (int menu) {
		switch (menu)
		{
		case 0:
			m_state = GAMESELECT_SCREEN;
			break;
		case 1:     //強制終了
			exit(0);
			break;
		default:
			assert(false);
		}
	}
	if (m_timer++ % MAX_FPS == 0) TaskEx::DleteDeathTask();//不要タスクの消去

#if defined(_DEBUG) | defined(DEBUG)
	if (CheckHitKey(KEY_INPUT_A))m_state = GAME_SCREEN;
#endif
}

//描画
void CTitleScreen::Draw() const
{
	ClearDrawScreen();
	TaskEx::DrawTask();

#if defined(_DEBUG)|defined(DEBUG)
	DrawString(10, 100, "TiTLE Screen Hit A key to Game Screen", GetColor(255, 255, 255));
#endif
}