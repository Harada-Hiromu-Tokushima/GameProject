//-----
//TaskSystemEx.h
//-----
#ifndef __TASKEX_H__
#define __TASKEX_H__
#pragma once

#include "TaskSystem.h"

class  TaskEx :public Task
{
private:
	;
public:
	//コンストラクタ
	TaskEx();

	//デストラクタ
	~TaskEx();
	
	//タスクシステム初期化
	static void InitTaskList(void);

	//タスクをタスクリストに追加する
	static void AddTask(Task* p_task);

	//指定したグループのタスクを削除
	void EraseTask(CAST id);

	//死亡したタスクだけを削除
	static void DleteDeathTask(void);

	//すべてのタスクを実行(更新)する
	static void RunTask(void);

	//すべてのタスクを描画する
	static void DrawTask(void);

	//指定したidのタスクだけを描画する
	void DrawTask(CAST _id);

	//指定したグループのタスク数を返す
	DWORD GetCount(CAST _id);

	//指定したidを持ち、指定した番号のタスクを返す
	void* GetTask(CAST _id, DWORD _number = 0);

	//自分のデータを取得
	void GetData(DATA *_pdata) const;
};

#endif __TASKEX_H__
