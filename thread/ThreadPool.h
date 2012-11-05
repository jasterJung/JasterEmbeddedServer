#ifndef __THREADPOOL_H__
#define __THREADPOOL_H__

#include "./CommonSocketThread.h"
#include <map>
#include <pthread.h>

using namespace std;

#define MAX_THREADS_NUM 10


class ThreadPool
{
private:
	ThreadPool();
	static ThreadPool* m_instance;
	int 	m_maxThreadsNumber;
	map< int, Thread* > m_threadMap;

	//for sync beetwenn pool and Thread.
	ScopeMutex		m_initThread;
	ScopeMutex		m_worksLock;

	//none copiable
	//static pthread_mutex_t m_init;
	//static pthread_mutex_t m_watting;
	
public:
	virtual ~ThreadPool(){};
	static ThreadPool* getInstance();
	int getMaxThreadsNumber() const;
	const Thread* GetFreeThread();

	void setMaxThreadsNumber(int maxThreadsNumber);

	int CreateThreadPool();

	void DestroyThreadPool();

};


#endif
