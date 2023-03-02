//-----
//MainGameSistem.h
//-----
#ifndef __MAINGAMESISTEM_H__
#define __MAINGAMESISTEM_H__
#pragma once

#include "TaskSystemEx.h"

class CMainSistem : public TaskEx
{
	enum GAMESTEP			//�Q�[���i���Ǘ��p
	{
		STATESTEP,MAINSTEP,BATTLESTEP,DAMAGESTEP,ENDSTEP
	};

	GAMESTEP GameStep = STATESTEP;	//�Q�[���i���Ǘ��p�ϐ�
	int TurnCount = 0;		//�Q�[���̃^�[����
	float GameTime;			//�Q�[�������ԃJ�E���g�p�ϐ�

	//�v���C���[�v�f
	int p_image;			//�v���C���[�̉摜
	int p_icon;				//�v���C���[�̃A�C�R��
	int p_life;				//�v���C���[�̗̑�
	float   p_ratio;		//
	int p_posx;				//�v���C���[���WX
	int p_posy;				//�v���C���[���WY
	int p_num;				//�v���C���[���l(�^�C�}�[�Ƃ��̒l)

	//�G�v�f
	int e_image;			//�G�̉摜
	int e_icon;				//�G�̃A�C�R��
	int e_life;				//�G�̗̑�
	float	e_ratio;		//
	int e_posx;				//�G���WX
	int e_posy;				//�G���WY
	int e_num;				//�G���l

	//UI�v�f
	int UI_Number[11];		//�ł����^�[���\��
	int UI_TurnWindow[5];	//�^�[���\���E�C���h�E
	int UI_LifeWindow;		//�̗̓o�[�̘g
	int UI_LifeBer;			//�̗̓o�[
	int UI_IconWindow;		//�A�C�R���̘g
	int UI_ItemWindow;		//�A�C�e���g

	//���̑�
	int c_num;				//�G���Ȑ��l(��̐��l�ȂǂɎg�p)


public:
	CMainSistem(float _priority);
	~CMainSistem();
	void Update();
	void Draw() const;
};

#endif  __MAINGAMESISTEM_H__
