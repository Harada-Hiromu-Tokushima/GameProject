//-----
//gametitle_screen.cpp
//-----


//�w�b�_�[�t�@�C��
#include "GameTitle_screen.h"
#include "Title.h"
#include "TaskSystemEx.h"

//�R���X�g���N�^
CTitleScreen::CTitleScreen()
{
	m_state = TITLE_SCREEN;
	m_timer = 0;
	TaskEx::InitTaskList();
	TaskEx::AddTask(new Ctitle(0.6f));
	TaskEx::AddTask(new CBgm(0,150,0.8f));
}

//�f�X�g���N�^
CTitleScreen::~CTitleScreen(){
	clsDx();
}

//���s����
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
		case 1:     //�����I��
			exit(0);
			break;
		default:
			assert(false);
		}
	}
	if (m_timer++ % MAX_FPS == 0) TaskEx::DleteDeathTask();//�s�v�^�X�N�̏���

#if defined(_DEBUG) | defined(DEBUG)
	if (CheckHitKey(KEY_INPUT_A))m_state = GAME_SCREEN;
#endif
}

//�`��
void CTitleScreen::Draw() const
{
	ClearDrawScreen();
	TaskEx::DrawTask();

#if defined(_DEBUG)|defined(DEBUG)
	DrawString(10, 100, "TiTLE Screen Hit A key to Game Screen", GetColor(255, 255, 255));
#endif
}