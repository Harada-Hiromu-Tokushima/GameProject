//-----
//TaskSystemEx.cpp
//-----
#include "TaskSystemEx.h"

list<Task *> m_TaskList;

//タスクの初期値設定
TaskEx::TaskEx() {
	m_id = NONE;
	m_cx = 0; m_cy = 0;
	m_speed = 0;
	m_life = 0; m_maxLife = 0;
	m_rot = 0;
}

//タスクリストを空にする
TaskEx::~TaskEx() {
	InitTaskList();
}

//タスクリストの初期化
void TaskEx::InitTaskList(void) {
	if (!m_TaskList.empty()) {
		m_TaskList.clear();
	}
}

//タスクをタスクリストに追加する
//p_task:タスク
void TaskEx::AddTask(Task* _ptask)
{
	auto it = m_TaskList.begin();
	for (; it != m_TaskList.end(); ++it) {
		Task* _task = *it;
		//自分より大きいpriorityのタスクがあったら
		if (_task->m_priority > _ptask->m_priority)
			break;
	}
	m_TaskList.insert(it, _ptask);
}


//死亡したすべてのタスクを消去する
//タスクリスト操作中は、使用禁止
void TaskEx::DleteDeathTask(void)
{
	for (auto it = m_TaskList.begin(); it != m_TaskList.end();) {
		Task* _task = *it;
		if (!_task->m_isActive) {
			it = m_TaskList.erase(it);
			continue;
		}
		it++;
	}
}


//指定したグループ(id)のタスクを削除
//タスクリスト使用中は、使用禁止
//特殊攻撃で一網打尽に使用可能
void TaskEx::EraseTask(CAST _id) {
	for (auto it = m_TaskList.begin(); it != m_TaskList.end();) {
		Task* p_task = *it;
		if (p_task->m_id == _id) {
			it = m_TaskList.erase(it);
			continue;
		}
		it++;
	}
}

//生きているすべてのタスクを実行する
void TaskEx::RunTask(void)
{
	for (auto task : m_TaskList) {
		if (task->m_isActive) task->Update();
	}
}

//生きているすべてのタスクを描画する
void TaskEx::DrawTask(void)
{
	for (auto task : m_TaskList) {
		if (task->m_isActive) task->Draw();
	}
}

//指定したグループ(id)のタスクだけを描画する
void TaskEx::DrawTask(CAST _id) {
	for (auto task : m_TaskList) {
		if (task->m_id == _id) task->Draw();
	}
}

//指定したグループ(id)のタスク数を返す
DWORD TaskEx::GetCount(CAST _id) {
	DWORD count = 0;
	for (auto task : m_TaskList) {
		if (task->m_id == _id) count++;
	}
	return count;
}

//指定したグループ(id)を持ち、指定した番号のタスクを返す
//同じグループ(id)のものが複数いる場合は、number=0から付番されている
void* TaskEx::GetTask(CAST _id, DWORD _number) {
	int count = 0;
	for (auto task : m_TaskList) {
		if (task->m_id == _id && count++ == _number) return task;
	}
	return nullptr;
}

//自分のデータを取得
void TaskEx::GetData(DATA* _pdata) const {

	if (!_pdata) return;

	_pdata->cx = m_cx;
	_pdata->cy = m_cy;
	_pdata->life = m_life;
	_pdata->maxLife = m_maxLife;
}