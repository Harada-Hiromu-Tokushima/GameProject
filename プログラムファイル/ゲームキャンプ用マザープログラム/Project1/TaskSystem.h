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

//�^�X�N�̎��ʎq
enum CAST
{
	MAINSISTEM,SCORE,TITLE,SELECT,GAMEOVER,GAMECLEAR,SE,BGM,MENU,SELECTMENU,HIT,EXPLOSION, EFFECT,  NONE
};

//�^�X�N�̏��
enum  PHASE{ PHASE_START, PHASE_MOVE1, PHASE_MOVE2, PHASE_PLAY, PHASE_BOSS, PHASE_CLEAR, PHASE_END };

enum  STAGE{ CoinGame, DiseGame, StopWatchGame, Ex };

//�^�X�N�N���X
//�^�X�N�V�X�e���̌��ɂȂ�N���X
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
	float   m_priority;     //�D��x
	bool    m_isActive;     //�^�X�N�̐����@true=���@false=��
	CAST    m_id;           //�O���[�v���ʎq

	Task(){}
	virtual ~Task(){}
	virtual void Update(){}
	virtual void Draw() const{}
};

//�e�N���X����������o�����߂̍\����
struct  DATA
{
	float   cx, cy;
	float   hit_cw, hit_ch;
	DWORD   life, maxLife;
};

#endif __TASKSYSTEM_H__