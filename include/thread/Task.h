/*
 * Task.h
 *
 *  Created on: 2012. 9. 27.
 *      Author: root
 */

#ifndef TASK_H_
#define TASK_H_

namespace jThread {

class Task {
public:
	Task();
	virtual ~Task();
	int testTest;

private:
	bool m_bStart;
};

} /* namespace Thread */
#endif /* TASK_H_ */
