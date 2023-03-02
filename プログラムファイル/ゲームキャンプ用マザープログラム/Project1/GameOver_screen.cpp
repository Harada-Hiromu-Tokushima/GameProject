//-----
//gameover_screen.cpp
//-----

//ヘッダーファイル
#include "GameOver_screen.h"
//#include "Title.h"

//コンストラクタ
CGameOverScreen::CGameOverScreen()
{
	m_state = GAMEOVER_SCREEN;
	m_timer = 0;
	m_image = LoadGraph("media\\img\\gameover.png");
}

//デストラクタ
CGameOverScreen::~CGameOverScreen() {
	DeleteGraph(m_image);
}

//実行処理
void CGameOverScreen::Update()
{
	if (m_timer++ >= MAX_FPS * 3) m_state = TITLE_SCREEN;

#if defined(_DEBUG) | defined(DEBUG)
	if(CheckHitKey(KEY_INPUT_B))m_state = TITLE_SCREEN;
#endif
}

//描画
void CGameOverScreen::Draw() const
{
	ClearDrawScreen();

	DrawGraph(0, 0, m_image, false);

#if defined(_DEBUG)|defined(DEBUG)
	clsDx();
	DrawString(10, 200, "GameOver Screen Hit B key to Title Screen", GetColor(255, 255, 255));
#endif
}