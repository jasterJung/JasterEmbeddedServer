
#include "thread/Thread.h"
#include <iostream>
#include <assert.h>
#include <stdio.h>
#include "thread/ThreadPool.h"
#include "common/CommonNet.h"

using namespace std;
using namespace jThread;


Thread::Thread():_running(false),
		_threadId(0),
		_thread(0),
	 	_runnable(0),
	 	_thPool(0)
{

}

//Thread::Thread( Runnable* pRunnable ):_thread(0),_runnable( pRunnable ){}
Thread::~Thread(){

	cout << "~~~~~~~~~~~~~~~~~~~Thread() "<< endl;

	//if you create with Runnalbe
	if(_runnable != 0)
	{
		printf ("deleted runnable\n");
		delete _runnable;
	}
}

//ignored this functions
void Thread::Run()
{
	cout << "CALLed the parents thread  :::::::::;->";

	/*
	if (_runnable != 0) 
	{
		_runnable->Run();	
	}
	*/

}

int Thread::Start()
{
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
		//exit(0);
	}

	return 0;

}


bool Thread::Join ( void **value_ptr  )
{
	bool rt = false;
	if(_running)
	{
		rt = common::Net::Pthread_join ( _thread, value_ptr );
		_running = false;
	}

	return rt ? false : true;
}


//static
void* Thread::Main(void* pInst)
{
  Thread* pt = static_cast< Thread* >(pInst);
  pt->Run(); //bottom and top flow ,
}



