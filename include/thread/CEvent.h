#ifndef _CEVENT_H_
#define _CEVENT_H_


#include <pthread.h>

class CEvent
{

private:
	pthread_cond_t m_ready;
	pthread_mutex_t m_lock;
	BOOL m_bCreated;

public:
	void Set();
	BOOL Wait();
	void Reset();
	CEvent(void);
	CEvent(const pthread_mutex_t& lock);
	~CEvent(void);
};

#endif

