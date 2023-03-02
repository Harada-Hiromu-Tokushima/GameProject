//-----
//MainGameSistem.cpp
//-----

#include "MainGameSistem.h"
#include "Task.h"

CMainSistem::CMainSistem(float _priority)
{
	m_id = MAINSISTEM;
	m_priority = _priority;
	m_isActive = true;

	GameStep = STATESTEP;
	GameTime = 0.0f;
	TurnCount = 0;

	p_life = 3;
	e_life = 2;

	p_posx = 50;
	p_posy = 150;
	e_posx = 850;
	e_posy = 150;

	p_image = LoadGraph("media_\\img\\C_Player.png");
	p_icon = LoadGraph("media_\\img\\C_PlayerIcon.png");

	//UIê›íË
	LoadDivGraph("media_\\img\\UI_Number.png", 10, 10, 1, 100, 200, UI_Number);
	LoadDivGraph("media_\\img\\UI_TurnWindow.png", 5, 5, 1, 190, 110, UI_TurnWindow);
	UI_ItemWindow = LoadGraph("media_\\img\\UI_Window.png");
	UI_LifeWindow = LoadGraph("media_\\img\\UI_LifeWindow.png");
	UI_LifeBer = LoadGraph("media_\\img\\UI_LifeBar.png");

}

CMainSistem::~CMainSistem(){}

void CMainSistem::Update()
{
	
}

void CMainSistem::Draw()const
{
	//ÉvÉåÉCÉÑÅ[ï`âÊ
	DrawExtendGraph(p_posx, p_posy, p_posx + 2650 / 5, p_posy + 2650 / 5, p_image, true);
	DrawRectGraph(110, 30, 0, 0, (int)(500 *p_ratio), 100, UI_LifeBer, TRUE);
	//ìGï`âÊ
	DrawExtendGraph(e_posx, e_posy, e_posx + 2650 / 5, e_posy + 2650 / 5, e_image, true);
	DrawRectGraph((WINDOW_W - (int)(500 * e_ratio) - 110), 30, 0, 0, (int)(500*e_ratio), 100, UI_LifeBer, TRUE , TRUE);

	//UIï`âÊ
	//è„ïî
	DrawGraph(WINDOW_W / 2 - 95, 30, UI_TurnWindow[TurnCount -1], true);
	DrawGraph(0, 0, p_icon, true);
	DrawGraph(WINDOW_W - 135, 0, e_icon, true);
	DrawGraph(110, 30, UI_LifeWindow, true);
	DrawTurnGraph(WINDOW_W - 500 - 110, 30, UI_LifeWindow, true);

	//â∫ïî
	DrawGraph(0, WINDOW_H - 340, UI_ItemWindow, true);
	DrawGraph(WINDOW_W - 340, WINDOW_H - 340, UI_ItemWindow, true);



	switch (GameStep)
	{
	case CMainSistem::STATESTEP:
		DrawGraph(WINDOW_W/2 - 50, WINDOW_H/2 - 150, UI_Number[TurnCount], true);
		break;
	case CMainSistem::MAINSTEP:
		DrawGraph(WINDOW_W / 2 - 50, WINDOW_H / 2 - 150, UI_Number[TurnCount], true);
		break;
	case CMainSistem::BATTLESTEP:
		DrawGraph(WINDOW_W / 2 - 50, WINDOW_H / 2 - 150, UI_Number[TurnCount], true);
		break;
	case CMainSistem::DAMAGESTEP:
		break;
	case CMainSistem::ENDSTEP:
		break;
	default:
		break;
	}
}