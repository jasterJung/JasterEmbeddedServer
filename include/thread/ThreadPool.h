#ifndef __THREADPOOL_H__
#define __THREADPOOL_H__

#include "CommonSocketThread.h"
#include "Task.h"

#include <pthread.h>
#include <queue>
#include <vector>


using namespace std;

//#define MAX_THREADS_NUM 10
namespace jThread
{
typedef enum {
	OK						= 		1,
	FALSE					=		2,
	NOT_ENOUGH_THREAD,
	HAS_NO_TASK
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
	queue<Task> 			m_tasks;
	vector<Thread*>		m_threads;

#endif


	//for sync between pool and Thread.
	ScopeMutex				m_initThread;
	ScopeMutex				m_worksLock;
	//For critical section
	ScopeMutex				m_queueCriticalLock;
	
public:
	virtual ~ThreadPool(){};
	static ThreadPool* getInstance();
	int getMaxThreadsNumber() const;

#if 0
	jThread::POOL_STATUS	GetFreeThread(jThread::Thread* rTh);
#endif

	void setMaxThreadsNumber(int maxThreadsNumber);

	int CreateThreadPool();

	void DestroyThreadPool();

//Task Queue
	//m_queueCriticalLock;
	const POOL_STATUS getTask(Task& task);
	const POOL_STATUS setTask(Task& task);
};

}
#endif
