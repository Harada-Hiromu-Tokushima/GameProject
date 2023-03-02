//-----
//GameSelect_Screen.h
//-----
#ifndef __GAMESELECT_SCREEN_H__
#define __GAMESELECT_SCREEN_H__
#pragma once

//ヘッダーファイル
#include "MyLib.h"
#include "TaskSystemEx.h"
#include "screen.h"

//ゲームセレクトスクリーンクラス
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

//タイトルロゴ表示用クラス
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

//タイトル用メニュークラス
//暫定的に文字表示で代用している
class Cselectmenu : public TaskEx {
private:
	int     m_item;
	int     m_selectMenu;
	bool    m_isDecide;     //決定キーが押されたかどうか
	const   char*   menuItem[3] = { "Game Right","Game Senter", "Game Left" };
	int		m_cursor;
public:
	Cselectmenu(float _priority = 0.5f);
	~Cselectmenu();
	void Update(void);
	void Draw(void) const;
};
#endif __GAMESELECT_SCREEN_H__
