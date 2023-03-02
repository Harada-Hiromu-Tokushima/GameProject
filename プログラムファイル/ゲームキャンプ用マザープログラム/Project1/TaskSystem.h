//-----
//TaskSystem.h
//-----
#ifndef __TASKSYSTEM_H__
#define __TASKSYSTEM_H__
#pragma once

#include "DxLib.h"
#include "MyLib.h"
#include <list>
#include <algorithm>

using namespace std;

//タスクの識別子
enum CAST
{
	MAINSISTEM,SCORE,TITLE,SELECT,GAMEOVER,GAMECLEAR,SE,BGM,MENU,SELECTMENU,HIT,EXPLOSION, EFFECT,  NONE
};

//タスクの状態
enum  PHASE{ PHASE_START, PHASE_MOVE1, PHASE_MOVE2, PHASE_PLAY, PHASE_BOSS, PHASE_CLEAR, PHASE_END };

enum  STAGE{ CoinGame, DiseGame, StopWatchGame, Ex };

//タスククラス
//タスクシステムの元になるクラス
class Task
{
protected:
	float   m_cx, m_cy;
	float   m_speed;
	DWORD   m_life, m_maxLife;
	float   m_rot;
	int     m_image;
	Rect    m_rect;
	int     m_Point;
public:
	float   m_priority;     //優先度
	bool    m_isActive;     //タスクの生死　true=生　false=死
	CAST    m_id;           //グループ識別子

	Task(){}
	virtual ~Task(){}
	virtual void Update(){}
	virtual void Draw() const{}
};

//各クラスから情報を取り出すための構造体
struct  DATA
{
	float   cx, cy;
	float   hit_cw, hit_ch;
	DWORD   life, maxLife;
};

#endif __TASKSYSTEM_H__