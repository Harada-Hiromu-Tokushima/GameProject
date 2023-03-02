//-----
//Title.h
//-----
#ifndef _TITLE_
#define _TITLE_
#pragma once

#include "MyLib.h"
#include "TaskSystemEx.h"

//enum PHASE{PHASE_START, PHASE_PLAY, PHASE_END};


//タイトルロゴ表示用クラス
class Ctitle :public TaskEx {
private:
	int       m_alpha;
	DWORD   m_timer;
	PHASE   m_phase;
public:
	Ctitle(float _priority = 0.5f);
	~Ctitle();
	void Update(void);
	void Draw(void) const;
};

//タイトル用メニュークラス
//暫定的に文字表示で代用している
class Cmenu : public TaskEx {
private:
	int     m_item;
	int     m_selectMenu;
	bool    m_isDecide;     //決定キーが押されたかどうか
	const   char*   menuItem[2] = { "GameSelect Screen","Exit Game" };
public:
	Cmenu(float _priority = 0.5f);
	~Cmenu();
	void Update(void);
	void Draw(void) const;
};


#endif _TITLE_