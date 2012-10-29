
#include "Thread.h"
#include <iostream>
#include <assert.h>
using namespace std;

Thread::Thread():_running(true),
		_being_closed_signal(false),
	 	_status_canWork(0),
		_threadId(0),
		_thread(0),
	 	_init_singnal_Mutex(0),
	 	_wait_singnal_Mutex(0),
	 	_runnable(0)
{
}

Thread::Thread( Runnable* pRunnable ):_thread(0),_runnable( pRunnable )
{

}
Thread::~Thread(){

	cout << "~~~~~~~~~~~~~~~~~~~Thread() "<< endl;
	//delete _runnable
	if(_runnable != 0)
		delete _runnable;
}

void Thread::Run()
{
	cout << "CALLed the parents thread  :::::::::;->";
	if (_runnable != 0) 
	{
		_runnable->Run();	
	}

}

int Thread::Start() {

	int		rc;
	//pthread_attr_t threadAtt;
	rc = pthread_attr_init(&_thread_attr);
    //size_t stacksize;
    //pthread_attr_getstacksize(&m_attr, &stacksize);
    //stacksize *= 2;
    //pthread_attr_setstacksize(&m_attr, stacksize);
    //fprintf(stderr, "Thread#%d stack size %d\n", m_threadid, stacksize);
	
	rc = pthread_create(&_thread,
				&_thread_attr,
				&Thread::Main,
				this);

	assert(rc == 0);

	if(rc < 0 )
	{
		perror("thread Create error : ");
		exit(0);
	}

}


int Thread::Wait() {
  void* pData;

  _being_closed_signal = true;

  getInitLocker()->lock();
  getCondition().notify();
  getInitLocker()->unlock();

  int nr = pthread_join(_thread, &pData);
  return (nr == 0);
}

//static
void* Thread::Main(void* pInst)
{
  //cout << "Thread::Main() called" << endl;
  Thread* pt = static_cast< Thread* >(pInst);
  pt->Run(); //bottom and top flow , imple
}



