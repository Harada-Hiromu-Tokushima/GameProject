//-----
//gameselect_screen.cpp
//-----

//�w�b�_�[�t�@�C��
#include "Game_Screen.h"
#include "MainGameSistem.h"
#include "Task.h"

//�R���X�g���N�^
CGameScreen::CGameScreen()
{
	m_state = GAME_SCREEN;
	m_timer = 0;
	TaskEx::InitTaskList();     //�^�X�N�V�X�e��������
	//TaskEx::AddTask(new CMainSistem(0.2f));
	TaskEx::AddTask(new CBgm(1,150,0.8f));
	m_image = LoadGraph("media_\\img\\GameStage.png");
	//clsDx();
}

//�f�X�g���N�^
CGameScreen::~CGameScreen(){}

//���s����
void CGameScreen::Update()
{
	m_timer++;
	try {
		TaskEx::RunTask();     //�^�X�N�̍X�V
	}
	catch (CAST menu) {
		if (menu == GAMECLEAR) { m_state = GAMECLEAR_SCREEN;}
		if (menu == GAMEOVER) { m_state = GAMEOVER_SCREEN; }
	}
	if (m_timer % MAX_FPS == 0) TaskEx::DleteDeathTask();//�s�v�^�X�N�̍폜

#if defined(_DEBUG)|defined(DEBUG)
	//if (CheckHitKey(KEY_INPUT_C)) m_state = TITLE_SCREEN;
	if (CheckHitKey(KEY_INPUT_D)) m_state = GAMEOVER_SCREEN;
	if (CheckHitKey(KEY_INPUT_E)) m_state = GAMECLEAR_SCREEN;
#endif
}

//�`��
void CGameScreen::Draw() const
{
	ClearDrawScreen();
	DrawGraph(0, 0, m_image, false);
	TaskEx::DrawTask();     //�^�X�N�̕`��

#if defined(_DEBUG) | defined(DEBUG)
	clsDx();
	DrawString(10, 100, "SELECT Screen Hit C key to Title Screen", GetColor(255, 255, 255));
	DrawString(10, 120, "              Hit D key to GameOver Screen", GetColor(255, 255, 255));
	DrawString(10, 140, "              Hit E key to GameClear Screen", GetColor(255, 255, 255));
#endif
}