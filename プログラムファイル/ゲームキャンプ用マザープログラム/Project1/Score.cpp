//-----
//Score.cpp
//-----
#include "Task.h"
#include "MyLib.h"

const int DIGI_W = 15;
const int DIGI_H = 20;

const int DIGITS = 10;     //”š‚ÌŒÂ”

const int DRAW_RIGHT = 760;
const int DRAW_TOP = 20;

const int MIN_FIGURE = 4;     //0‚ğ’Ç‰Á‚·‚éŒÂ”

CScore::CScore(float _priority) {
	m_id = SCORE;
	m_score = 0;
	m_priority = _priority;
	m_isActive = true;
	LoadDivGraph("media\\img\\digit20pt.png", DIGITS, DIGITS, 1, DIGI_W, DIGI_H, m_images);
}

CScore::~CScore() {
	for (int i = 0; i < DIGITS; i++) {
		DeleteGraph(m_images[i]);
	}
}

void CScore::Update() {}

void CScore::Draw() const {
	for (int i = 0; i < MIN_FIGURE || m_score / (DWORD)pow(10, i); i++) {
		BYTE digit = (BYTE)(m_score / (DWORD)pow(10, i)) % 10;
		DrawGraph((DRAW_RIGHT - DIGI_W * i), DRAW_TOP, m_images[digit], TRUE);
	}
}

void CScore::Add(DWORD _score) {
	m_score += _score;
}