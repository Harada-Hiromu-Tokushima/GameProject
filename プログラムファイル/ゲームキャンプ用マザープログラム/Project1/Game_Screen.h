//-----
//game_screen.h
//-----
#ifndef __GAME_SCREEN_H__
#define __GAME_SCREEN_H__
#pragma once

//ヘッダーファイル
#include "MyLib.h"
#include "screen.h"
#include "Task.h"
#include "TaskSystemEx.h"

//ゲームスクリーンクラス
class CGameScreen : public CScreen
{
private:
	DWORD   m_timer;
	int		m_image;
public:
	CGameScreen();
	~CGameScreen();
	void   Update();
	void   Draw() const;
};

#endif __GAME_SCREEN_H__