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
	//�R���X�g���N�^
	TaskEx();

	//�f�X�g���N�^
	~TaskEx();
	
	//�^�X�N�V�X�e��������
	static void InitTaskList(void);

	//�^�X�N���^�X�N���X�g�ɒǉ�����
	static void AddTask(Task* p_task);

	//�w�肵���O���[�v�̃^�X�N���폜
	void EraseTask(CAST id);

	//���S�����^�X�N�������폜
	static void DleteDeathTask(void);

	//���ׂẴ^�X�N�����s(�X�V)����
	static void RunTask(void);

	//���ׂẴ^�X�N��`�悷��
	static void DrawTask(void);

	//�w�肵��id�̃^�X�N������`�悷��
	void DrawTask(CAST _id);

	//�w�肵���O���[�v�̃^�X�N����Ԃ�
	DWORD GetCount(CAST _id);

	//�w�肵��id�������A�w�肵���ԍ��̃^�X�N��Ԃ�
	void* GetTask(CAST _id, DWORD _number = 0);

	//�����̃f�[�^���擾
	void GetData(DATA *_pdata) const;
};

#endif __TASKEX_H__
