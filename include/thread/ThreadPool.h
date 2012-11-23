#ifndef __THREADPOOL_H__
#define __THREADPOOL_H__

#include "./CommonSocketThread.h"
#include <pthread.h>
#include <deque>

using namespace std;

//#define MAX_THREADS_NUM 10
namespace jThread
{
typedef enum {
	OK						= 		1,
	FALSE					=		2,
	NOT_ENOUGH_THREAD
}POOL_STATUS;

const int MAX_THREADS_NUM = 256;


class ThreadPool
{
private:
	ThreadPool();
	static ThreadPool* 	m_instance;
	int 					m_maxThreadsNumber;

#if 1

	//map of matched free threads.
	queue<int> 			m_threadsMap;
	Thread 				m_thread[MAX_THREADS_NUM];


#endif


	//for sync between pool and Thread.
	ScopeMutex				m_initThread;
	ScopeMutex				m_worksLock;

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
<<<<<<< HEAD


=======
>>>>>>> ce3d10ec1256b497d1cd28b908172546e8aa0012
};

}
#endif
