#include "ThreadPool.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "ScopeMutex.h"
#include "condition.h"

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

		m_threads[i]->setThreadPoolObj(this);

		m_threads[i]->setThreadId(i);


		{
			m_initThread.lock();

			rc = m_threads[i]->Start();

			m_initCondition.wait(m_initThread);

			m_initThread.unlock();
		}

		assert(rc == 0);

	}

	return 0;
}

#if 0
jThread::POOL_STATUS jThread::ThreadPool::GetFreeThread(jThread::Thread* rTh)
{
	POOL_STATUS rtn = NOT_ENOUGH_THREAD;
	vector<Thread*>::iterator iter;
	mi = m_threadMap.begin();


	for( mi = m_threads.begin(); mi != m_threads.end(); ++mi)
	{
		if(jThread::WAIT_FOR_WORK == mi->second->getStatusCanWork())
		{
			//printf("<<<<<<<<<<<<< TD %d FLAG %d \n ",mi->second->getThreadId() ,mi->second->getStatusCanWork());
			//get free Thread.
			//rTh = mi->second;
			rtn = OK;
			break;
		}
		else
		{
			printf("BUSY.. TD %d FLAG %d \n ",mi->second->getThreadId() ,mi->second->getStatusCanWork());
		}
	}

	return rtn;
}
#endif
void jThread::ThreadPool::DestroyThreadPool()
{

	m_being_closed_signal = true;

	//notify all for delete
	m_workscondition.notifyAll();

    for (unsigned int i = 0; i < m_threads.size(); i++)
    {
    	m_threads[i]->Join();
        delete m_threads[i];
    }

	pthread_exit(NULL);
}

const jThread::POOL_STATUS jThread::ThreadPool::getTask(Task& task)
{
	if(m_tasks.empty())
		return HAS_NO_TASK;
	task = m_tasks.front();
	m_tasks.pop();

	return OK;
}
const jThread::POOL_STATUS jThread::ThreadPool::setTask(const Task& task)
{
	{
		jThread::CriticalSection criticalLock(m_worksLock);
		m_tasks.push(task);
	}
	// Signal to all threads.
	this->getworksCondition().notifyAll();

	return OK;
}
