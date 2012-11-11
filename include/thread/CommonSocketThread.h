/*
 * CommonSocketThread.h
 *
 *  Created on: 2012. 9. 12.
 *      Author: root
 */

#ifndef COMMONSOCKETTHREAD_H_
#define COMMONSOCKETTHREAD_H_

#include "./Thread.h"
#include "./ScopeMutex.h"


class CommonSocketThread: public jThread::Thread {
public:
	CommonSocketThread();
	virtual ~CommonSocketThread();

	virtual void Run();
};

#endif /* COMMONSOCKETTHREAD_H_ */
