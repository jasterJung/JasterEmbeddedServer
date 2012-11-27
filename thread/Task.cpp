/*
 * Task.cpp
 *
 *  Created on: 2012. 9. 27.
 *      Author: root
 */

#include "Task.h"
#include <cstdlib.h>

jThread::Task::Task() {
	// TODO Auto-generated constructor stub
}

jThread::Task::~Task() {
	// TODO Auto-generated destructor stub
}

int jThread::Task::getTemp()
{
	return 1+(rand() % 10);
}


