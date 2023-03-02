//-----
//gameover_screen.h
//-----
#ifndef __GAMEOVER_SCREEN_H__
#define __GAMEOVER_SCREEN_H__
#pragma once

//ヘッダーファイル
#include "MyLib.h"
#include "screen.h"

//ゲームスクリーンクラス
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
