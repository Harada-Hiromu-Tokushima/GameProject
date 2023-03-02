//-----
//muLib.h
//-----
#ifndef __MYLIB_H__
#define __MYLIB_H__
#pragma once

//�w�b�_�[�t�@�C��
#include "DxLib.h"
#include "assert.h"
#include <stdlib.h>
#include <time.h>

//�v���v���Z�b�T
#define ARRAY_SIZE(a)     (sizeof(a)/sizeof(a[0]))
#define RANDMIZE()        (srand((unsigned)time(NULL)))

const float FRAMETIME_S = 0.016666f;     //=(1.0f/MAX_FPS)
const float FRAMETIME_MS = 16.666f;      //=(1000ms/MAX_FPS)
const float DEG2RAD = 0.0174528f;        //=(2.0f*3.1415f/360.0f)
const float PI = 3.1415f;

const int WINDOW_W = 1422;
const int WINDOW_H = 800;
const int MAX_FPS = 60;     //��FPS
const float SPF = (WORD)(1000.0 / MAX_FPS + 0.5);   //1�t���[���̎���
const bool WINDOW_SCREEN = true;

struct Rect {
	int TopX; int TopY; int Width; int Height;
};

typedef unsigned char BYTE;
typedef unsigned long DWORD;

//�L�[���s�[�g�𖳌������āA�L�[���͂��s��
bool IsKeyTrigger(int key, int key_type);

//��`�̈�̓����蔻��
bool IsHitBox(float cx, float cy, float dx, float dy, Rect src_rect, Rect dest_rect);

//�O���[�o���ϐ�
extern BYTE GAMESTAGE;

#endif __MYLIB_H__