#include <sys/time.h>
#include <unistd.h>
#include <cerrno>

#include "condition.h"
#include "ScopeMutex.h"

Condition::Condition()
          :m_isOwner(true)
{
    m_pcond = new pthread_cond_t;
    if (pthread_cond_init(m_pcond, 0) == 0)
    {
        //ok
    }
}

Condition::~Condition()
{
    if (m_isOwner)
    {
        switch (pthread_cond_destroy(m_pcond))
        {
        case 0:
            break;

        case EBUSY:
            pthread_cond_broadcast(m_pcond);
            pthread_cond_destroy(m_pcond);
            break;
        }

        delete m_pcond;
    }
}

Condition::Condition(const Condition& copy)
{
    m_pcond = copy.m_pcond;
    m_isOwner = false;
}

void Condition::notify()
{
    if (pthread_cond_signal(m_pcond) == 0)
    {
        //ok
    }
}

void Condition::notifyAll()
{
    if (pthread_cond_broadcast(m_pcond) == 0)
    {
        //ok
    }
}

//void Condition::wait(ScopeMutex& mutex)
void Condition::wait(ScopeMutex* mutex)
{
    //if (pthread_cond_wait(m_pcond, mutex.m_pmutex) == 0)
	if (pthread_cond_wait(m_pcond, mutex->m_pmutex) == 0)
    {
        //ok
    }
}

bool Condition::wait(ScopeMutex& mutex, long msec)
{
    timespec  timeout;
    timeval   timenow;

    gettimeofday(&timenow, 0);
    timeout.tv_sec = timenow.tv_sec + msec*1000;

    if (pthread_cond_timedwait(m_pcond, mutex.m_pmutex, &timeout) == 0)
        return true;
    return false;
}
