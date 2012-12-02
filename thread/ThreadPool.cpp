#include "ThreadPool.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "ScopeMutex.h"
#include "condition.h"
#include "common/CommonNet.h"

#include <time.h>
#include <unistd.h>

jThread::ThreadPool* jThread::ThreadPool::m_instance = 0;

using namespace std;

//static
jThread::ThreadPool* jThread::ThreadPool::getInstance()
{
	if(!m_instance)
	{
		m_instance = new ThreadPool();
	}
	return m_instance;
}


jThread::ThreadPool::ThreadPool():
		m_maxThreadsNumber(MAX_THREADS_NUM),
		m_being_closed_signal(false)
{

}

int jThread::ThreadPool::getMaxThreadsNumber() const {
	return m_maxThreadsNumber;
}

void jThread::ThreadPool::setMaxThreadsNumber(int maxThreadsNumber) {
	m_maxThreadsNumber = maxThreadsNumber;
}

int jThread::ThreadPool::CreateThreadPool()
{
	m_threads.resize(m_maxThreadsNumber);

	for(int i = 0; i<getMaxThreadsNumber(); i++)
	{
		int rc = 0;
		//init lock
		m_threads[i] = static_cast< Thread* >( new CommonSocketThread());
		assert(getInstance() != 0);
		m_threads[i]->setThreadPoolObj(getInstance());
		m_threads[i]->setThreadId(i);

#if 0
		{
			//getInitMutex().lock();
			rc = m_threads[i]->Start();
			//getInitCondition().wait(getInitMutex());
			//getInitMutex().unlock();
		}
#endif
#if 1
		rc = m_threads[i]->Start();
#endif
		//common::Net::Sleep(1);
		assert(rc == 0);

	}

	return 0;
}

void jThread::ThreadPool::DestroyThreadPool()
{
	m_worksLock.lock();

	m_being_closed_signal = true;

	m_workscondition.notifyAll();

	m_worksLock.unlock();

	//notify all for delete
	//getworksCondition().notifyAll();
	printf("notify All [ %d ] \n",m_threads.size());


    for (unsigned int i = 0; i < m_threads.size(); i++)
    {
    	//m_worksLock.lock();
    	m_workscondition.notify();
    	printf("Join [%d] =>%s \n",i,m_threads[i]->Join() ? "TRUE" : "FALSE");
    	//m_worksLock.unlock();
        delete m_threads[i];
    }

	//getWorkMutex().unlock();

	pthread_exit(NULL);
}

const jThread::POOL_STATUS jThread::ThreadPool::getTask(Task& task)
{

	if(m_tasks.empty())
		return HAS_NO_TASK;
	task = m_tasks.front();
	printf("size is %d\n",m_tasks.size());
	m_tasks.pop();

	return OK;
}
const jThread::POOL_STATUS jThread::ThreadPool::setTask(const Task& task)
{
	{
		jThread::CriticalSection criticalLock(m_worksLock);
		printf("setted Task------%d\n",m_tasks.size());
		m_tasks.push(task);
	}

	// Signal to all threads.
	m_workscondition.notifyAll();

	return OK;
}

