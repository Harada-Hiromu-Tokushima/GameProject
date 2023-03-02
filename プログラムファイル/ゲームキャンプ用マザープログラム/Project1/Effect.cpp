
#include"Effect.h"

CEffect01::CEffect01(float _priority) {
	m_id = CAST::EFFECT;
	m_priority = _priority;
	m_isActive = true;
	m_Timer = 0;
	m_Frame = 0;
    LoadDivGraph("media_\\img\\DiceRoll.png", WIDTH * HEIGHT, WIDTH, HEIGHT,
		          MAX_WIDHT,MAX_HEIGHT,m_Image);
}
CEffect01::~CEffect01() {
	for (int i = 0; i < WIDTH * HEIGHT; i++)
		DeleteGraph(m_Image[i]);
}
void CEffect01::Update() {
	const int FRAME_STEP = 5;
	const int FRAME_MAX = WIDTH * HEIGHT;

	m_Frame = m_Timer++ / FRAME_STEP;
	if (m_Frame >= 12) { m_Timer = 0; }

}
void CEffect01::Draw()const {

	DrawGraph(200,100, m_Image[m_Frame],TRUE);
} 
/*--------------cointoss------------------------------------*/
CEffect02::CEffect02(float _priority) {
	m_id = CAST::EFFECT;
	m_priority = _priority;
	m_isActive = true;
	m_Timer = 0;
	m_Frame = 0;
	LoadDivGraph("media_\\img\\CoinToss.png", WIDTH * HEIGHT, WIDTH, HEIGHT,MAX_WIDHT, MAX_HEIGHT, m_Image);
}
CEffect02::~CEffect02() {
	for (int i = 0; i < WIDTH * HEIGHT; i++)
		DeleteGraph(m_Image[i]);
}
void CEffect02::Update() {
	const float FRAME_STEP = 0.5f;
	const int FRAME_MAX = WIDTH * HEIGHT;

	m_Frame = m_Timer++ / FRAME_STEP;
	if (m_Frame >= 20.0f) { m_Timer = 0.0f; }

}
void CEffect02::Draw()const {

	DrawGraph(400, 100, m_Image[m_Frame], TRUE);
}
