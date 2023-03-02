//-----
//GameSelect_Screen.cpp
//-----

#include "GameSelect_Screen.h"
#include "TaskSystemEx.h"
#include "Task.h"

int getitem;

CGameSelectScreen::CGameSelectScreen()
{
	m_state = GAMESELECT_SCREEN;
	m_timer = 0;
	TaskEx::AddTask(new Cselect(0.6f));
	TaskEx::AddTask(new CBgm(2, 240, 0.8f));
	m_image = LoadGraph("media_\\img\\SelectImage.png");

}

CGameSelectScreen::~CGameSelectScreen(){
	clsDx();
}

void CGameSelectScreen::Update()
{
	try {
		TaskEx::RunTask();
	}
	catch (int select) {
		switch (getitem)
		{
		case 0:
			GAMESTAGE = CoinGame;
			m_state = GAME_SCREEN;
			break;
		case 1:
			GAMESTAGE = DiseGame;
			m_state = GAME_SCREEN;
			break;
		case 2:
			GAMESTAGE = StopWatchGame;
			m_state = GAME_SCREEN;
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
void CGameSelectScreen::Draw() const
{
	ClearDrawScreen();
	TaskEx::DrawTask();
	//DrawGraph(0, 0, m_image, false);

#if defined(_DEBUG)|defined(DEBUG)
	DrawString(10, 100, "TiTLE Screen Hit A? key to Game Screen", GetColor(255, 255, 255));
#endif
}

//-----------------

Cselect::Cselect(float _priority) {
	m_id = SELECT;
	m_image = LoadGraph("media_\\img\\SelectImage.png");
	m_alpha = 0;
	m_timer = 0;
	m_priority = _priority;
	m_isActive = true;
	m_phase = PHASE_START;
}

Cselect::~Cselect() {}

void Cselect::Update(void) {
	const int alphaMax = 255;
	const int alphaStep = 9;
	int key;

	m_timer++;
	switch (m_phase)
	{
	case PHASE_START:
		m_alpha = m_timer * alphaStep;
		key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		if (key || m_alpha >= alphaMax) {
			m_phase = PHASE_PLAY;
			m_alpha = alphaMax;
		}
		break;
	case PHASE_PLAY:
		TaskEx::AddTask(new Cselectmenu(0.6f));      //Menu起動
		m_phase = PHASE_END;
		break;
	case PHASE_END:
		if (!GetCount(SELECTMENU)) {
			m_isActive = false;
			DeleteGraph(m_image);
		}
		break;
	default:
		assert(false);
	}
}

void Cselect::Draw(void) const {
	const int alphaMax = 255;
	SetDrawBright(m_alpha, m_alpha, m_alpha);
	DrawGraph(0, 0, m_image, false);
	SetDrawBright(alphaMax, alphaMax, alphaMax);
}

Cselectmenu::Cselectmenu(float _priority) {
	m_priority = _priority;
	m_id = SELECTMENU;
	m_item = 0;
	m_isDecide = false;     //false=未決定
	m_isActive = true;
	m_cursor = LoadGraph("media_\\img\\UI_SelectWindow.png");
}

Cselectmenu::~Cselectmenu() {
	clsDx();
	m_isActive = false;
}

void Cselectmenu::Update(void) {
	const int MENU_MIN = 0;
	const int MENU_MAX = 2;
	const int SE_MENU_CHANGE = 0;
	const int SE_MENU_SELECT = 1;

	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (!m_isDecide && IsKeyTrigger(key, PAD_INPUT_LEFT)) {
		m_item--;
		TaskEx::AddTask(new Cse(SE_MENU_CHANGE));  //メニュー変更SE再生
	}
	if (!m_isDecide && IsKeyTrigger(key, PAD_INPUT_RIGHT)) {
		m_item++;
		TaskEx::AddTask(new Cse(SE_MENU_CHANGE));   //メニュー変更SE再生
	}
	if (m_item < MENU_MIN) m_item = MENU_MAX;
	if (m_item > MENU_MAX) m_item = MENU_MIN;

	if (!m_isDecide && IsKeyTrigger(key, PAD_INPUT_A)) {
		TaskEx::AddTask(new Cse(SE_MENU_SELECT));   //メニュー決定SE再生
		CBgm * task = (CBgm *)GetTask(BGM);
		task->ChangePhase(PHASE_END);           //BGMフェードアウト指示
		m_selectMenu = m_item;
		getitem = m_item;
		m_isDecide = true;
	}
	if (!GetCount(BGM)) {    //BGMが止んだら、選んだメニュー番号を送信
		throw(m_selectMenu);
		m_isActive = false;
	}
}

void Cselectmenu::Draw(void) const {
	const int MENU = 3;
	clsDx();
	//DrawGraph(0, 0, m_image, false);
	/*printfDx("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	for (int i = 0; i < MENU; i++) {
		if (i == m_item)
			printfDx("\t\t\t\t\t\t\t\t★");
		else
			printfDx("\t\t\t\t\t\t\t\t　");

		printfDx("%s\n", menuItem[i]);
	}*/
	switch (m_item)
	{
	case 0:
		DrawGraph(0, 87, m_cursor, true);
		break;
	case 1:
		DrawGraph(464, 87, m_cursor, true);
		break;
	case 2:
		DrawGraph(926, 87, m_cursor, true);
		break;
	default:
		break;
	}
}
