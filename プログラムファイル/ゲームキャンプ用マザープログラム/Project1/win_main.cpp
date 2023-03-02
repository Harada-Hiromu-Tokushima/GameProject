//*****
//wim_main.cpp
//*****
#include "Mylib.h"
#include "resource.h"
#include "Game.h"

//-----
//���[�J���ϐ�
//-----
CGame*     g_pMain = NULL;

//-----
//���[�J���֐�
//-----
void       win_main_init();
void       win_main_loop();
void       win_main_dest();

//-----
//�E�B���h�E��ʂ̃��C��
//-----
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	double dNextTime = GetNowCount();
	win_main_init();

	while (!ProcessMessage()) {
		dNextTime += FRAMETIME_MS;           //60FPS����
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
//���C������������
//-----
void win_main_init()
{
	//DirectX�֌W

	ChangeWindowMode(WINDOW_SCREEN);
	if (WINDOW_SCREEN)
	{
		SetGraphMode(WINDOW_W, WINDOW_H, 32);
		//�A�C�R���t�@�C���̓ǂݍ���
		SetWindowIconID(IDI_ICON2);

		SetMainWindowText(_T("�Q�[���L�����v�p�v���W�F�N�g"));
	}
	if (DxLib_Init() == -1) //���C�u�����̏���������
		return;

	RANDMIZE();
	SetDrawScreen(DX_SCREEN_BACK);

	//GAME�֌W
	g_pMain = new CGame();
}

//-----
//���C�����[�v����
//-----
void win_main_loop()
{
	//���C������
	g_pMain->Update();
	g_pMain->Draw();
	ScreenFlip();
}

//-----
//���C���I������
//-----
void win_main_dest()
{
	delete g_pMain;
	g_pMain = NULL;
}