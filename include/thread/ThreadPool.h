#ifndef __THREADPOOL_H__
#define __THREADPOOL_H__

#include "./CommonSocketThread.h"
#include <map>
#include <pthread.h>

using namespace std;

//#define MAX_THREADS_NUM 10
namespace jThread
{
typedef enum {
	OK						= 		1,
	FALSE					=		2,
	NOT_ENOUGH_THREAD
}POOL_STATUS;

const int MAX_THREADS_NUM = 10;


class ThreadPool
{
private:
	ThreadPool();
	static ThreadPool* m_instance;
	int 	m_maxThreadsNumber;
	map< int, Thread* > m_threadMap;

	//for sync between pool and Thread.
	ScopeMutex		m_initThread;
	ScopeMutex		m_worksLock;

	//none copiable
	//static pthread_mutex_t m_init;
	//static pthread_mutex_t m_watting;
	
public:
	virtual ~ThreadPool(){};
	static ThreadPool* getInstance();
	int getMaxThreadsNumber() const;

	jThread::POOL_STATUS	GetFreeThread(jThread::Thread* rTh);

	void setMaxThreadsNumber(int maxThreadsNumber);

	int CreateThreadPool();

	void DestroyThreadPool();


};

}
#endif
