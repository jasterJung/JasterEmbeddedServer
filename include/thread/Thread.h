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


class Thread: public Runnable { // Runnable
public:
	Thread();
	//Thread& operator=(const Thread&);
	//Thread(Runnable* pRunnable);
	virtual ~Thread();
	int Start();
	int Wait();
	virtual void Run();          //
	const int getThreadId(){return _threadId;};
	void setThreadId(const int id){_threadId = id;};
	
	ScopeMutex* getInitLocker(){return _init_singnal_Mutex;};
	void setInitLocker(ScopeMutex* event){_init_singnal_Mutex = event;};
	ScopeMutex* getLocker(){return _wait_singnal_Mutex;};
	void setLocker(ScopeMutex* event){_wait_singnal_Mutex = event;};
	Condition& getCondition(){return _singnal_Condition;};
	bool getClosedSignalFlg() {
		return _being_closed_signal;
	};
	int getStatusCanWork() const {
		return _status_canWork;
	};

	void setStatusCanWork(int statusCanWork) {
		_status_canWork = statusCanWork;
	};
	
	
	
private:
	jThread::Task				_task;
	int             	_threadId;    // opt. number of thread
	pthread_t 			_thread;
	Runnable* 			_runnable;
	pthread_attr_t  	_thread_attr;  // thread attributes
 	bool            	_running;      // true if thread is running
 	int 			    _status_canWork;      //The status of thread is it waiting,thead ready for work.
 	bool 				_being_closed_signal; //Thread should be close.
	
	/// Event is recived from mainStack .
 	ScopeMutex	*		_init_singnal_Mutex;
 	ScopeMutex	*		_wait_singnal_Mutex;
	Condition 			_singnal_Condition;
	
	static void* Main(void* pInst);

};

}
#endif
