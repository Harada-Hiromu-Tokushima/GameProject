//-----
//game.cpp
//-----
#include "screen.h"
#include "GameTitle_screen.h"
#include "GameSelect_Screen.h"
#include "Game_Screen.h"
#include "GameOver_screen.h"
#include "GameClear_Screen.h"
#include "Game.h"

CGame::CGame() {
	m_now_screen = TITLE_SCREEN;
	m_pScreen = NULL;
}

CGame::~CGame() {
	if (m_pScreen) {
		delete m_pScreen;
		m_pScreen = NULL;
	}
}

void CGame::Update()
{
	if (!m_pScreen) {
		switch (m_now_screen)
		{
		case TITLE_SCREEN:
			m_pScreen = new CTitleScreen();
			break;
		case GAMESELECT_SCREEN:
			m_pScreen = new CGameSelectScreen();
			break;
		case GAME_SCREEN:
			m_pScreen = new CGameScreen();
			break;
		case GAMEOVER_SCREEN:
			m_pScreen = new CGameOverScreen();
			break;
		case GAMECLEAR_SCREEN:
			m_pScreen = new CGameClearScreen();
			break;
		default:
			assert(false);
		}
	}
	else {
		m_pScreen->Update();

		if (m_now_screen != m_pScreen->GetNextScreen()) {
			m_now_screen = m_pScreen->GetNextScreen();
			delete m_pScreen;
			m_pScreen = NULL;
		}
	}
}

void CGame::Draw() const
{
	if (m_pScreen) {
		m_pScreen->Draw();
	}
}