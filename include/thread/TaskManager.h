/*
 * TaskManager.h
 *
 *  Created on: 2012. 9. 19.
 *      Author: root
 */

#ifndef TASKMANAGER_H_
#define TASKMANAGER_H_

#include "Task.h"
#include "ThreadPool.h"

namespace jThread {

class TaskManager {
public:
	TaskManager();
	virtual ~TaskManager();
	int openingPreparation(int howManyworkerDoyouwant){m_nomOfThread = howManyworkerDoyouwant;};
	int open();

	//it shall run process with a suitable Task.
	int doTesk(const Task& task);

	static TaskManager* m_instanceTaskManager;
	static TaskManager* getInstance();

private:
	// parameter for the Thread- Pool
	jThread::ThreadPool* th_pool;
	int m_nomOfThread;

};



} /* namespace Thread */
#endif /* TASKMANAGER_H_ */
