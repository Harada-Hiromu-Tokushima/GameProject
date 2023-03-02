//-----
//Title.h
//-----
#ifndef _TITLE_
#define _TITLE_
#pragma once

#include "MyLib.h"
#include "TaskSystemEx.h"

//enum PHASE{PHASE_START, PHASE_PLAY, PHASE_END};


//�^�C�g�����S�\���p�N���X
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

//�^�C�g���p���j���[�N���X
//�b��I�ɕ����\���ő�p���Ă���
class Cmenu : public TaskEx {
private:
	int     m_item;
	int     m_selectMenu;
	bool    m_isDecide;     //����L�[�������ꂽ���ǂ���
	const   char*   menuItem[2] = { "GameSelect Screen","Exit Game" };
public:
	Cmenu(float _priority = 0.5f);
	~Cmenu();
	void Update(void);
	void Draw(void) const;
};


#endif _TITLE_