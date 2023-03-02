#pragma once
#include "TaskSystemEx.h"
class CEffect01 : public TaskEx {
private:
	const int WIDTH = 12;
	const int HEIGHT = 1;
	int m_Image[12];
	const int MAX_WIDHT = 200;
	const int MAX_HEIGHT = 200;
	int m_Timer;
	int m_Frame;
public:
	CEffect01(float _priority);
	~CEffect01();
	void Update();
	void Draw()const;
};
class CEffect02 : public TaskEx {
private:
	const int WIDTH = 20;
	const int HEIGHT = 1;
	int m_Image[20];
	const int MAX_WIDHT = 200;
	const int MAX_HEIGHT = 200;
	int m_Timer;
	int m_Frame;
public:
	CEffect02(float _priority);
	~CEffect02();
	void Update();
	void Draw()const;
};