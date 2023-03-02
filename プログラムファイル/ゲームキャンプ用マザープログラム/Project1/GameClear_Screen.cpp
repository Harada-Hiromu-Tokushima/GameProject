//gameclear_screen.cpp
//----------------------------

#include "GameClear_Screen.h"
#include "GameTitle_screen.h"

//�R���X�g���N�^
CGameClearScreen::CGameClearScreen()
{
	m_state = GAMECLEAR_SCREEN;
	m_timer = 0;
	TaskEx::InitTaskList(); //�^�X�N�V�X�e��������
	if (GAMESTAGE == 1) {
		m_image = LoadGraph("media\\img\\gameclear2.png");
	}
	else {
		m_image = LoadGraph("media\\img\\loading.png");
	}
}

//�f�X�g���N�^
CGameClearScreen::~CGameClearScreen()
{
	DeleteGraph(m_image);
}

//���s����
void CGameClearScreen::Update()
{
	switch (GAMESTAGE)
	{
	case 0:
		if (m_timer++ >= MAX_FPS * 3) { GAMESTAGE = 1; m_state = GAME_SCREEN; }
		break;
	case 1:
		if (m_timer++ >= MAX_FPS * 3) { GAMESTAGE = 0; m_state = TITLE_SCREEN; }
		break;
	default:
		break;
	}

#if defined(_DEBUG)|defined(DEBUG)
	if (CheckHitKey(KEY_INPUT_F))m_state = TITLE_SCREEN;
#endif
}

//�`��
void CGameClearScreen::Draw() const
{
	ClearDrawScreen();

	DrawGraph(0, 0, m_image, false);

#if defined(_DEBUG)|defined(DEBUG)
	clsDx();
	DrawString(10, 200, "GameOver Screen Hit F key to Title Screen", GetColor(255, 255, 255));
#endif
}