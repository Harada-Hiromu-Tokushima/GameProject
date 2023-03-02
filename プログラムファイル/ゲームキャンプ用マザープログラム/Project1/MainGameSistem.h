//-----
//MainGameSistem.h
//-----
#ifndef __MAINGAMESISTEM_H__
#define __MAINGAMESISTEM_H__
#pragma once

#include "TaskSystemEx.h"

class CMainSistem : public TaskEx
{
	enum GAMESTEP			//ゲーム進捗管理用
	{
		STATESTEP,MAINSTEP,BATTLESTEP,DAMAGESTEP,ENDSTEP
	};

	GAMESTEP GameStep = STATESTEP;	//ゲーム進捗管理用変数
	int TurnCount = 0;		//ゲームのターン数
	float GameTime;			//ゲーム内時間カウント用変数

	//プレイヤー要素
	int p_image;			//プレイヤーの画像
	int p_icon;				//プレイヤーのアイコン
	int p_life;				//プレイヤーの体力
	float   p_ratio;		//
	int p_posx;				//プレイヤー座標X
	int p_posy;				//プレイヤー座標Y
	int p_num;				//プレイヤー数値(タイマーとかの値)

	//敵要素
	int e_image;			//敵の画像
	int e_icon;				//敵のアイコン
	int e_life;				//敵の体力
	float	e_ratio;		//
	int e_posx;				//敵座標X
	int e_posy;				//敵座標Y
	int e_num;				//敵数値

	//UI要素
	int UI_Number[11];		//でかいターン表示
	int UI_TurnWindow[5];	//ターン表示ウインドウ
	int UI_LifeWindow;		//体力バーの枠
	int UI_LifeBer;			//体力バー
	int UI_IconWindow;		//アイコンの枠
	int UI_ItemWindow;		//アイテム枠

	//その他
	int c_num;				//雑多な数値(基準の数値などに使用)


public:
	CMainSistem(float _priority);
	~CMainSistem();
	void Update();
	void Draw() const;
};

#endif  __MAINGAMESISTEM_H__
