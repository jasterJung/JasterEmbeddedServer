/*
 * CommonSocketThread.cpp
 *
 *  Created on: 2012. 9. 12.
 *      Author: root
 */

#include "CommonSocketThread.h"

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

CommonSocketThread::CommonSocketThread()
{
	//Thread::_singnal_Mutext(event);
	// TODO Auto-generated constructor stub
}

CommonSocketThread::~CommonSocketThread() {
	//cout << "~CommonSocketThread() "<< endl;
}

void CommonSocketThread::Run() {
	//Thread::Run();
    //cout << "TestThread::Run() called" <<  Thread::_thread_no << endl;

	 Thread::getInitLocker()->lock();
	 printf("Init-------threads =  %d \n " , Thread::getThreadId());
	 Thread::getCondition().notify();
	 Thread::getInitLocker()->unlock();

	 while(1)
	 {
		 /// Waiting
		 Thread::getLocker()->lock();

		 Thread::setStatusCanWork( jThread::WAIT_FOR_WORK ); //true

		 printf("WAIT_FOR_A_WORK = ThreadID %d , %d  \n " , Thread::getThreadId(), Thread::getStatusCanWork());

		 Thread::getCondition().wait( Thread::getLocker() );

		 Thread::getLocker()->unlock();

		 // it is not free thread anymore. thus set 0
		 Thread::setStatusCanWork( jThread::DOING_WORK ); //false

		 if(Thread::getClosedSignalFlg())
			 break;

		 printf("Thread will run %d \n",Thread::getThreadId());

		 sleep(1);

		 for (int i = 0; i<80; i++)
		 {
			 sleep(1);
			 printf("Thread work %d  <========= %d\n",i,Thread::getThreadId());
		 }
	 }
}
