//-----
//TaskSystemEx.cpp
//-----
#include "TaskSystemEx.h"

list<Task *> m_TaskList;

//�^�X�N�̏����l�ݒ�
TaskEx::TaskEx() {
	m_id = NONE;
	m_cx = 0; m_cy = 0;
	m_speed = 0;
	m_life = 0; m_maxLife = 0;
	m_rot = 0;
}

//�^�X�N���X�g����ɂ���
TaskEx::~TaskEx() {
	InitTaskList();
}

//�^�X�N���X�g�̏�����
void TaskEx::InitTaskList(void) {
	if (!m_TaskList.empty()) {
		m_TaskList.clear();
	}
}

//�^�X�N���^�X�N���X�g�ɒǉ�����
//p_task:�^�X�N
void TaskEx::AddTask(Task* _ptask)
{
	auto it = m_TaskList.begin();
	for (; it != m_TaskList.end(); ++it) {
		Task* _task = *it;
		//�������傫��priority�̃^�X�N����������
		if (_task->m_priority > _ptask->m_priority)
			break;
	}
	m_TaskList.insert(it, _ptask);
}


//���S�������ׂẴ^�X�N����������
//�^�X�N���X�g���쒆�́A�g�p�֎~
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


//�w�肵���O���[�v(id)�̃^�X�N���폜
//�^�X�N���X�g�g�p���́A�g�p�֎~
//����U���ň�ԑŐs�Ɏg�p�\
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

//�����Ă��邷�ׂẴ^�X�N�����s����
void TaskEx::RunTask(void)
{
	for (auto task : m_TaskList) {
		if (task->m_isActive) task->Update();
	}
}

//�����Ă��邷�ׂẴ^�X�N��`�悷��
void TaskEx::DrawTask(void)
{
	for (auto task : m_TaskList) {
		if (task->m_isActive) task->Draw();
	}
}

//�w�肵���O���[�v(id)�̃^�X�N������`�悷��
void TaskEx::DrawTask(CAST _id) {
	for (auto task : m_TaskList) {
		if (task->m_id == _id) task->Draw();
	}
}

//�w�肵���O���[�v(id)�̃^�X�N����Ԃ�
DWORD TaskEx::GetCount(CAST _id) {
	DWORD count = 0;
	for (auto task : m_TaskList) {
		if (task->m_id == _id) count++;
	}
	return count;
}

//�w�肵���O���[�v(id)�������A�w�肵���ԍ��̃^�X�N��Ԃ�
//�����O���[�v(id)�̂��̂���������ꍇ�́Anumber=0����t�Ԃ���Ă���
void* TaskEx::GetTask(CAST _id, DWORD _number) {
	int count = 0;
	for (auto task : m_TaskList) {
		if (task->m_id == _id && count++ == _number) return task;
	}
	return nullptr;
}

//�����̃f�[�^���擾
void TaskEx::GetData(DATA* _pdata) const {

	if (!_pdata) return;

	_pdata->cx = m_cx;
	_pdata->cy = m_cy;
	_pdata->life = m_life;
	_pdata->maxLife = m_maxLife;
}