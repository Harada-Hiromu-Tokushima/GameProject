//-----
//gameover_screen.h
//-----
#ifndef __GAMEOVER_SCREEN_H__
#define __GAMEOVER_SCREEN_H__
#pragma once

//�w�b�_�[�t�@�C��
#include "MyLib.h"
#include "screen.h"

//�Q�[���X�N���[���N���X
class CGameOverScreen : public CScreen
{
private:
	DWORD   m_timer;
	int     m_image;
public:
	CGameOverScreen();
	~CGameOverScreen();
	void    Update();
	void    Draw() const;
};
#endif __GAMEOVER_SCREEN_H__
