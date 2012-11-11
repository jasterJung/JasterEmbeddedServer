#include "./ThreadPool.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "./ScopeMutex.h"
#include "./condition.h"

#include <time.h>
#include <unistd.h>

ThreadPool* ThreadPool::m_instance = 0;
//pthread_mutex_t ThreadPool::m_init 	 	=  PTHREAD_MUTEX_INITIALIZER;
//pthread_mutex_t ThreadPool::m_watting  	=  PTHREAD_MUTEX_INITIALIZER;

using namespace std;

//static
ThreadPool* ThreadPool::getInstance()
{
	if(!m_instance)
	{
		m_instance = new ThreadPool();
	}
	return m_instance;
}


ThreadPool::ThreadPool():m_maxThreadsNumber(MAX_THREADS_NUM)
{

}

int ThreadPool::getMaxThreadsNumber() const {
	return m_maxThreadsNumber;
}

void ThreadPool::setMaxThreadsNumber(int maxThreadsNumber) {
	m_maxThreadsNumber = maxThreadsNumber;
}

int ThreadPool::CreateThreadPool()
{
	
	for(int i = 0; i<getMaxThreadsNumber(); i++)
	{
		int rc = 0;
		//init lock
		Thread* th = static_cast< Thread* >(new CommonSocketThread());
		/// used to
		th->setInitLocker(	&m_initThread	);
		th->setLocker(	&m_worksLock	);
		th->setThreadId(i);

		m_initThread.lock();
		rc = th->Start();
		th->getCondition().wait(&m_initThread);
		m_initThread.unlock();

		assert(rc == 0);
		m_threadMap.insert( make_pair(i, th) );



	}

	return 0;
}
jThread::Thread* ThreadPool::GetFreeThread()
{
	jThread::Thread* th = 0;
	map< int, Thread* >::iterator mi;
	mi = m_threadMap.begin();
	while(mi != m_threadMap.end())
	{
		if(1 == mi->second->getStatusCanWork())
		{
			th = mi->second;
			break;
		}
			//get free Thread.
	}
	return th;
}
void ThreadPool::DestroyThreadPool()
{
 	map< int, Thread* >::iterator mi;

    mi = m_threadMap.begin();
    //cout << "size " << m_threadMap.size() << endl;
    printf("%d\n",m_threadMap.size());

    while(mi != m_threadMap.end())
    {
    	printf("wait %d\n",m_threadMap.size());
        //     << " : " << mi->second.sockfd << endl;
    	mi->second->Wait();
    	delete mi->second;
       mi ++;
    }

    m_threadMap.clear();
	pthread_exit(NULL);
}
