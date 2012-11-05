#ifndef _SCOPE_MUTEX_H_
#define _SCOPE_MUTEX_H_


#include <pthread.h>


class ScopeMutex
{
public:
    friend class Condition;

    ScopeMutex();
    virtual ~ScopeMutex();
    ScopeMutex(const ScopeMutex& copy);

    bool lock();
    bool unlock();
    bool tryLock();


private:
    pthread_mutex_t      *m_pmutex;
    bool                  m_isOwner;

};

#endif // _MUTEX_H_