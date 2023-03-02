//-----
//Task.h
//-----
#ifndef __TASK_H__
#define __TASK_H__
#pragma once

#include "TaskSystemEx.h"

//�����A�j���[�V�����N���X
//���@�A�G�@��萶�������
class CExplosion : public TaskEx
{
	BYTE     m_texIdx;
	DWORD    m_timer;
	int      m_images[10];     //10�͎b��[�u
public:
	CExplosion(float _cx, float _cy, float _priority = 0.5f);
	~CExplosion(void);
	void Draw()const;
	void Update(void);
};

//�q�b�g�A�j���[�V�����N���X
//���@��萶�������
class CHit : public TaskEx
{
	BYTE     m_texIdx;
	DWORD    m_timer;
	int      m_images[10];     //10�͎b��[�u
public:
	CHit(float _cx, float _cy, float _priority = 0.5f);
	~CHit(void);
	void Draw()const;
	void Update(void);
};

//�X�R�A�Ǘ��p�N���X
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

//�^�C�g����ʐ�p�X�N���[���N���X
//�b��I��SE�́A�^�C�g�������Ŏg�p��
//�S�̂Ŏg�p����ꍇ�́ATask.h�ֈړ��̎�
class Cse : public TaskEx {
private:
	int     m_seNo;
	int     m_se[2];
	const   char * seItem[3] = { "media\\se\\menuchange.mp3","media\\se\\menuselect.mp3", "media\\se\\�����̖���1.mp3"};
public:
	Cse() {}
	Cse(int _number = 0, int _playtype = DX_PLAYTYPE_BACK, float _priority = 0.5f);
	~Cse();
	void Update(void);
	void Draw(void) const {}
};

//�^�C�g����pBGM�N���X
//�b��I��BGM�́A�^�C�g�������Ŏg�p��
//�S�̂Ŏg�p����ꍇ�́ATask.h�ֈړ��̎�
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

