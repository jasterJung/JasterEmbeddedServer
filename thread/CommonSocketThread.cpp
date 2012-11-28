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

	{
		thPool->getInitMutex().lock();

		printf("Init-------threads =  %d \n " , Thread::getThreadId());

		thPool->getCondition().notify();

		thPool->getInitMutex().unlock();
	}

	 while(1)
	 {
		  jThread::Task task;

		 {
			 thPool->getWorkMutex().lock();

			Thread::_running = false;

			 printf("WAIT_FOR_A_WORK = ThreadID %d \n " , Thread::getThreadId());

			 while(false == thPool->getClosedSignalFlg() && HAS_NO_TASK == thPool->getTask(task))
			 {
				 thPool->getworksCondition().wait( thPool->getWorkMutex() );
			 }

			 if(thPool->getClosedSignalFlg())
				 break;

			 Thread::_running = true;

			 printf("Thread will run %d \n",Thread::getThreadId());

			 if(OK != thPool->getTask(task))
				 continue;


			 thPool->getWorkMutex().unlock();
		 }

		 for (int i = 0; i<80; i++)
		 {
			 common::Net::Sleep(1);
			 printf("Thread work %d %d %d\n",i,Thread::getThreadId(),task.getTemp());
		 }

		 //common::Net::Sleep(sleepTime);
	 }
}
