//-----
//screen.h
//-----
#ifndef __SCREEN_H__
#define __SCREEN_H__
#pragma once

//�Q�[���X�N���[���̎��
enum SCREEN {
	TITLE_SCREEN,
	GAMESELECT_SCREEN,
	GAME_SCREEN,
	GAMECLEAR_SCREEN,
	GAMEOVER_SCREEN
};

//�x�[�X�ƂȂ�Screen�N���X�̒�`
class CScreen
{
protected:
	SCREEN m_state;
public:
	CScreen(){}
	virtual ~CScreen(){}
	virtual void   Update(){}
	virtual void   Draw()const{}
	SCREEN GetNextScreen()const { return(m_state); }
};

#endif __SCREEN_H__