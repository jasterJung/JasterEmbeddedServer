/*
 * Task.h
 *
 *  Created on: 2012. 9. 27.
 *      Author: root
 */

#ifndef TASK_H_
#define TASK_H_

//namespace Thread {

class Task {
public:
	Task();
	Task():testTest(0){};
	virtual ~Task(){};
	int testTest;

private:
	bool m_bStart;
};

//} /* namespace Thread */
#endif /* TASK_H_ */
