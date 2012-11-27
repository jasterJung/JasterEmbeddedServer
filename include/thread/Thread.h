#ifndef _THREAD_H              //
#define _THREAD_H

#include "Runnable.h"
#include "ScopeMutex.h"
#include "condition.h"
#include "Task.h"
#include <pthread.h>

///Boolean type
#ifndef BOOL
typedef enum BoolEnum{
	FALSE,
	TRUE
} BOOL;
#endif


//bool Join ( void ** valueptr = NULL );
//bool Detach();
//bool Terminate();

//Create Thread constructor be created firstly before child 
namespace jThread
{
const static int WAIT_FOR_WORK = 1; /// available resource.
const static int DOING_WORK    = 0; /// status of busy , you aren't able to this Thread.
class ThreadPool;

class Thread: public Runnable { // Runnable
public:
	Thread();
	//Thread& operator=(const Thread&);
	//Thread(Runnable* pRunnable);
	virtual ~Thread();
	int Start();
	bool Join ( void ** valueptr = NULL );
	virtual void Run();          //
	const int getThreadId(){return _threadId;};
	void setThreadId(const int id){_threadId = id;};

public:
	void setThreadPoolObj(ThreadPool* thPool){_thPool = thPool;	};
	ThreadPool* getThreadPoolObj(){return _thPool;};
	bool isRunning(){return _running;};

private:
	jThread::Task				_task;
	int             	_threadId;    // opt. number of thread
	pthread_t 			_thread;
	Runnable* 			_runnable;
	pthread_attr_t  	_thread_attr;  // thread attributes

protected:
 	bool            	_running;      // true if thread is running
	
	//Make sure divide to other class.
	ThreadPool* _thPool;

	static void* Main(void* pInst);

};

}
#endif
