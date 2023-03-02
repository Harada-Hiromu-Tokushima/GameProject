//-----
//game.h
//-----
#ifndef __GAME_H__
#define __GAME_H__
#pragma once

//�w�b�_�[�t�@�C��
#include "MyLib.h"

//�v���g�^�C�v
enum SCREEN;
class CScreen;

//�Q�[���N���X
class CGame
{
private:
	CScreen*     m_pScreen;     //���݂̃X�N���[���N���X�ւ̃|�C���^
	SCREEN       m_now_screen;  //��ʏ��
public:
	CGame();
	~CGame();
	void   Update();
	void   Draw() const;
};

#endif __GAME_H__
