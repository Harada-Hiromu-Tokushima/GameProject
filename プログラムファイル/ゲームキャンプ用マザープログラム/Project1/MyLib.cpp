//-----
//myLib.cpp
//-----
#include "MyLib.h"

//キーリピートを無効化して、キー入力を行う
bool IsKeyTrigger(int key, int key_type) {
	static bool g_key_prev[256] = { false };
	if (key & key_type) {
		if (!g_key_prev[key_type]) {
			g_key_prev[key_type] = true;
			return true;
		}
	}
	else {
		g_key_prev[key_type] = false;
	}
	return false;
}

//矩形領域の当たり判定
bool IsHitBox(float _cx, float _cy, float _dx, float _dy, Rect _srcRect, Rect _destRect) {

	float al = _cx + _srcRect.TopX;
	float at = _cy + _srcRect.TopY;
	float ar = al + _srcRect.Width;
	float ab = at + _srcRect.Height;

	float bl = _dx + _destRect.TopX;
	float bt = _dy + _destRect.TopY;
	float br = bl + _destRect.Width;
	float bb = bt + _destRect.Height;

	if (al < br && bl < ar && at < bb && bt < ab) {
		return true;
	}
	else {
		return false;
	}
}
BYTE GAMESTAGE = 0;