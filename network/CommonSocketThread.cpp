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
		 Thread::setStatusCanWork(1); //true
		 Thread::getCondition().wait( Thread::getLocker() );
		 Thread::getLocker()->unlock();

		 // it is not free thread anymore. thus set 0
		 Thread::setStatusCanWork(0); //false

		 if(Thread::getClosedSignalFlg())
			 break;


		 //Ended Lock
		 printf("Thread will run %d \n",Thread::getThreadId());

		 sleep(1);

		 for (int i = 0; i<5; i++)
			 printf("Thread runs %d  <========= %d\n",i,Thread::getThreadId());
	 }
}
