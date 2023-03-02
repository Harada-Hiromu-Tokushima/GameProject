//-----
//Title.cpp
//-----
#include "Title.h"
#include "Task.h"

//-----------------

Ctitle::Ctitle(float _priority) {
	m_id = TITLE;
	m_image = LoadGraph("media_\\img\\GameTitle.png");
	m_alpha = 0;
	m_timer = 0;
	m_priority = _priority;
	m_isActive = true;
	m_phase = PHASE_START;
}

Ctitle::~Ctitle() {}

void Ctitle::Update(void) {
	const int alphaMax = 255;
	const int alphaStep = 3;
	int key;

	m_timer++;
	switch (m_phase)
	{
	case PHASE_START:
		m_alpha = m_timer * alphaStep;
		key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		if (key || m_alpha >= alphaMax) {
			m_phase = PHASE_PLAY;
			m_alpha = alphaMax;
		}
		break;
	case PHASE_PLAY:
		TaskEx::AddTask(new Cmenu(0.6f));      //Menu起動
		m_phase = PHASE_END;
		break;
	case PHASE_END:
		if (!GetCount(MENU)) {
			m_isActive = false;
			DeleteGraph(m_image);
		}
		break;
	default:
		assert(false);
	}
}

void Ctitle::Draw(void) const {
	const int alphaMax = 255;
	SetDrawBright(m_alpha, m_alpha, m_alpha);
	DrawGraph(0, 0, m_image, false);
	SetDrawBright(alphaMax, alphaMax, alphaMax);
}

//---------------------

Cmenu::Cmenu(float _priority) {
	m_priority = _priority;
	m_id = MENU;
	m_item = 0;
	m_isDecide = false;     //false=未決定
	m_isActive = true;
}

Cmenu::~Cmenu() {
	clsDx();
	m_isActive = false;
}

void Cmenu::Update(void) {
	const int MENU_MIN = 0;
	const int MENU_MAX = 1;
	const int SE_MENU_CHANGE = 0;
	const int SE_MENU_SELECT = 1;

	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (!m_isDecide && IsKeyTrigger(key, PAD_INPUT_UP)) {
		m_item--;
		TaskEx::AddTask(new Cse(SE_MENU_CHANGE));  //メニュー変更SE再生
	}
	if (!m_isDecide && IsKeyTrigger(key, PAD_INPUT_DOWN)) {
		m_item++;
		TaskEx::AddTask(new Cse(SE_MENU_CHANGE));   //メニュー変更SE再生
	}
	if (m_item < MENU_MIN) m_item = MENU_MAX;
	if (m_item > MENU_MAX) m_item = MENU_MIN;

	if (!m_isDecide && IsKeyTrigger(key, PAD_INPUT_A)) {
		TaskEx::AddTask(new Cse(SE_MENU_SELECT));   //メニュー決定SE再生
		CBgm * task = (CBgm *)GetTask(BGM);
		task->ChangePhase(PHASE_END);           //BGMフェードアウト指示
		m_selectMenu = m_item;
		m_isDecide = true;
	}
	if (!GetCount(BGM)) {    //BGMが止んだら、選んだメニュー番号を送信
		throw(m_selectMenu);
		m_isActive = false;
	}
}

void Cmenu::Draw(void) const {
	const int MENU = 2;
	clsDx();
	printfDx("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	for (int i = 0; i < MENU; i++) {
		if (i == m_item)
			printfDx("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t★");
		else
			printfDx("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t　");

		printfDx("%s\n", menuItem[i]);
	}
}
//---------------------
Cse::Cse(int _number, int _playtype, float _priority) {
	m_id   = SE;
	m_seNo = _number;
	m_priority = _priority;
	m_se[m_seNo] = LoadSoundMem(seItem[m_seNo]);
	ChangeVolumeSoundMem(150, m_se[m_seNo]);
	PlaySoundMem(m_se[m_seNo], _playtype);
	m_isActive = true;
}

Cse::~Cse(){}

void Cse::Update(void) {
	if (!CheckSoundMem(m_se[m_seNo])) {
		m_isActive = false;
		DeleteSoundMem(m_se[m_seNo]);
	}
}
//---------------------
CBgm::CBgm(int _track, int _volume,float _prioity) {
	m_id = BGM;
	m_track = _track;
	m_phase = PHASE_START;
	m_timer = _volume;
	m_priority = _prioity;
	m_isActive = true;
	m_bgm = LoadSoundMem(m_bgmItem[m_track]);
	ChangeVolumeSoundMem(m_timer, m_bgm);
}

CBgm::~CBgm(){}

void CBgm::Update(void) {
	const int volumeStep = 3;
	switch (m_phase)
	{
	case PHASE_START:
		PlaySoundMem(m_bgm, DX_PLAYTYPE_LOOP);
		m_phase = PHASE_PLAY;
		break;
	case PHASE_PLAY:
		break;
	case PHASE_END:
		m_timer -= volumeStep;
		ChangeVolumeSoundMem(m_timer, m_bgm);
		if (m_timer <= 0) {
			m_isActive = false;
			DeleteSoundMem(m_bgm);
		}
		break;
	default:
		assert(false);
	}
}

void CBgm::ChangePhase(PHASE _phase) {
	m_phase = _phase;
}