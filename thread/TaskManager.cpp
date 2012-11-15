/*
 * TaskManager.cpp
 *
 *  Created on: 2012. 9. 19.
 *      Author: root
 */

#include "TaskManager.h"

jThread::TaskManager* jThread::TaskManager::m_instanceTaskManager = 0;

jThread::TaskManager* jThread::TaskManager::getInstance()
{
	if(!m_instanceTaskManager)
	{
		m_instanceTaskManager = new TaskManager();
	}
	return m_instanceTaskManager;
}

jThread::TaskManager::TaskManager():th_pool(0),m_nomOfThread(0)
{
	th_pool = ThreadPool::getInstance();
}

jThread::TaskManager::~TaskManager() {
	th_pool->DestroyThreadPool();
	delete th_pool;
}

int jThread::TaskManager::open()
{
	th_pool->setMaxThreadsNumber(m_nomOfThread);
	/// check is it possible number.
	return th_pool->CreateThreadPool();

};
int jThread::TaskManager::doTesk(const Task& task)
{
	jThread::Thread* th;

	th = th_pool->GetFreeThread();

	th->getCondition().notify();

	return 0;
}

//} /* namespace Thread */
