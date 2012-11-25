#ifndef _CONDITION_H_
#define _CONDITION_H_

#include <pthread.h>

#include "ScopeMutex.h"

namespace jThread
{



class Condition
{
public:
    Condition();
    virtual ~Condition();
    Condition(const Condition& copy);

    void   notify();
    void   notifyAll();

    void   wait(ScopeMutex& mutex);
    bool   wait(ScopeMutex& mutex, long msec);


private:
    pthread_cond_t      *m_pcond;
    bool                 m_isOwner;
};



}

#endif // _CONDITION_H_
