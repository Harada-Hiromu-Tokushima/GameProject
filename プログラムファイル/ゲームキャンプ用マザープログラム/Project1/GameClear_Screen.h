//gameclear_screen.h
//----------------------------

#ifndef  __GAMECLEAR_SCREEN__
#define  __GAMECLEAR_SCREEN__
#pragma once

//�w�b�_�[�t�@�C��
#include "MyLib.h"
#include "screen.h"

//�Q�[���X�N���[���N���X
class CGameClearScreen : public CScreen
{
private:
	DWORD m_timer;
	int m_image;
public:
	CGameClearScreen();
	~CGameClearScreen();
	void Update();
	void Draw()const;
};

#endif __GAMECLEAR_SCREEN_H__