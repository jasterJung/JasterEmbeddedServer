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
#include "ThreadPool.h"
#include "Task.h"
#include "common/CommonNet.h"

using namespace std;
using namespace jThread;


CommonSocketThread::CommonSocketThread()
{

}
CommonSocketThread::~CommonSocketThread() {
	//cout << "~CommonSocketThread() "<< endl;
}

void CommonSocketThread::Run() {

	//control task with thread pool
	ThreadPool* thPool = Thread::getThreadPoolObj();
	 while(1)
	 {
		  jThread::Task task;

		  {
			jThread::CriticalSection criticalLock(thPool->m_worksLock);

			Thread::_running = false;

			 while(false == thPool->getClosedSignalFlg() && HAS_NO_TASK == thPool->getTask(task))
			 {
				 printf("WAIT_FOR_A_WORK = ThreadID %d \n " , Thread::getThreadId());
				 thPool->m_workscondition.wait( thPool->m_worksLock );
			 }

			 if(thPool->getClosedSignalFlg())
			 {
				 printf("Get out due to out flag [%d] \n",Thread::getThreadId());
				 break;
			 }
			 Thread::_running = true;
		  }
		  //do logic
		 for (int i = 0; i<10; i++)
		 {
			 common::Net::Sleep(1);
			 printf("Thread work %d [ %d ] %d\n",i,Thread::getThreadId(),task.getTemp());
		 }

	 }
	printf("this thread should be join %d",Thread::getThreadId());
}
