//-----
//GameSelect_Screen.h
//-----
#ifndef __GAMESELECT_SCREEN_H__
#define __GAMESELECT_SCREEN_H__
#pragma once

//�w�b�_�[�t�@�C��
#include "MyLib.h"
#include "TaskSystemEx.h"
#include "screen.h"

//�Q�[���Z���N�g�X�N���[���N���X
class CGameSelectScreen : public CScreen
{
private:
	DWORD   m_timer;
	int     m_image;
public:
	CGameSelectScreen();
	~CGameSelectScreen();
	void    Update();
	void    Draw() const;
};

//�^�C�g�����S�\���p�N���X
class Cselect :public TaskEx {
private:
	int       m_alpha;
	DWORD   m_timer;
	PHASE   m_phase;
public:
	Cselect(float _priority = 0.5f);
	~Cselect();
	void Update(void);
	void Draw(void) const;
};

//�^�C�g���p���j���[�N���X
//�b��I�ɕ����\���ő�p���Ă���
class Cselectmenu : public TaskEx {
private:
	int     m_item;
	int     m_selectMenu;
	bool    m_isDecide;     //����L�[�������ꂽ���ǂ���
	const   char*   menuItem[3] = { "Game Right","Game Senter", "Game Left" };
	int		m_cursor;
public:
	Cselectmenu(float _priority = 0.5f);
	~Cselectmenu();
	void Update(void);
	void Draw(void) const;
};
#endif __GAMESELECT_SCREEN_H__
