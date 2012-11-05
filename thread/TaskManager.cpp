/*
 * TaskManager.cpp
 *
 *  Created on: 2012. 9. 19.
 *      Author: root
 */

#include "TaskManager.h"

#include "ThreadPool.h"

TaskManager* TaskManager::m_instanceTaskManager = 0;

class Task;

TaskManager* TaskManager::getInstance()
{
	if(!m_instanceTaskManager)
	{
		m_instanceTaskManager = new TaskManager();
	}
	return m_instanceTaskManager;
}

TaskManager::TaskManager():th_pool(0)
{
	th_pool = ThreadPool::getInstance();
}

TaskManager::~TaskManager() {
	th_pool->DestroyThreadPool();
	delete th_pool;
}

int TaskManager::open()
{
	th_pool->setMaxThreadsNumber(m_nomOfThread);
	/// check is it possible number.
	th_pool->CreateThreadPool();

};
int TaskManager::doTesk(const Task& task)
{
	Thread* th;
	th = th_pool->GetFreeThread();

	return 0;
}

//} /* namespace Thread */
