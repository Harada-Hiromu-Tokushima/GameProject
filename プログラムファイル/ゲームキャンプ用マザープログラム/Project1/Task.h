//-----
//Task.h
//-----
#ifndef __TASK_H__
#define __TASK_H__
#pragma once

#include "TaskSystemEx.h"

//爆発アニメーションクラス
//自機、敵機より生成される
class CExplosion : public TaskEx
{
	BYTE     m_texIdx;
	DWORD    m_timer;
	int      m_images[10];     //10は暫定措置
public:
	CExplosion(float _cx, float _cy, float _priority = 0.5f);
	~CExplosion(void);
	void Draw()const;
	void Update(void);
};

//ヒットアニメーションクラス
//自機より生成される
class CHit : public TaskEx
{
	BYTE     m_texIdx;
	DWORD    m_timer;
	int      m_images[10];     //10は暫定措置
public:
	CHit(float _cx, float _cy, float _priority = 0.5f);
	~CHit(void);
	void Draw()const;
	void Update(void);
};

//スコア管理用クラス
class CScore : public TaskEx
{
	DWORD   m_score;
	int     m_images[10];
public:
	CScore(float _priority = 0.9f);
	~CScore(void);
	void Draw() const;
	void Update(void);
	void Add(DWORD _score);
};

//タイトル画面専用スクリーンクラス
//暫定的にSEは、タイトルだけで使用中
//全体で使用する場合は、Task.hへ移動の事
class Cse : public TaskEx {
private:
	int     m_seNo;
	int     m_se[2];
	const   char * seItem[3] = { "media\\se\\menuchange.mp3","media\\se\\menuselect.mp3", "media\\se\\翼竜の鳴き声1.mp3"};
public:
	Cse() {}
	Cse(int _number = 0, int _playtype = DX_PLAYTYPE_BACK, float _priority = 0.5f);
	~Cse();
	void Update(void);
	void Draw(void) const {}
};

//タイトル専用BGMクラス
//暫定的にBGMは、タイトルだけで使用中
//全体で使用する場合は、Task.hへ移動の事
class CBgm : public TaskEx {
private:
	int     m_bgm;
	int     m_track;
	DWORD m_timer;
	PHASE  m_phase;
	const char * m_bgmItem[3] = { "media_\\bgm\\title.mp3","media\\bgm\\mp3.mp3", "media_\\bgm\\select.mp3" };
public:
	CBgm(int _bgm,int _volume,float _priority = 0.5f);
	~CBgm();
	void Update();
	void Draw() const {}
	void ChangePhase(PHASE _phase);
};

#endif __TASK_H__

