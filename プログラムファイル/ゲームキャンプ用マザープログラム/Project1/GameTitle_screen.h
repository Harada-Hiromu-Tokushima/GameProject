//-----
//title_screen.h
//-----
#ifndef __TITLE_SCREEN_H__
#define __TITLE_SCREEN_H__
#pragma once

//�w�b�_�[�t�@�C��
#include "MyLib.h"
#include "screen.h"
#include "Task.h"
#include "TaskSystemEx.h"
#include "Title.h"

//�^�C�g���X�N���[���N���X
class CTitleScreen : public CScreen
{
private:
	DWORD   m_timer;
public:
	CTitleScreen();
	~CTitleScreen();
	void    Update();
	void    Draw() const;
};

#endif __TITLE_SCREEN_H__
