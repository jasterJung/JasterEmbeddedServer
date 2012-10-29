#include "CEvent.h"

CEvent::CEvent(void)
:m_bCreated(TRUE)
{
	pthread_mutexattr_t mattr;
	
	pthread_mutexattr_init(&mattr);
	pthread_mutex_init(&m_lock,&mattr);
	pthread_cond_init(&m_ready,NULL);

}

CEvent::~CEvent(void)
{
	pthread_cond_destroy(&m_ready);
	//
	pthread_mutex_destroy(&m_lock);
}


/**
 *
 * Set
 * set an event to signaled
 *
 **/
void
CEvent::Set()
{
	pthread_mutex_lock(&m_lock);
	pthread_mutex_unlock(&m_lock);
	pthread_cond_signal(&m_ready);
}

/**
 *
 * Wait
 * wait for an event -- wait for an event object
 * to be set to signaled
 *
 **/
BOOL
CEvent::Wait()
{
	pthread_mutex_lock(&m_lock);
	pthread_cond_wait(&m_ready,&m_lock);
	return TRUE;
}

/**
 *
 * Reset
 * reset an event flag to unsignaled
 *
 **/
void
CEvent::Reset()
{
	pthread_mutex_unlock(&m_lock);
}

