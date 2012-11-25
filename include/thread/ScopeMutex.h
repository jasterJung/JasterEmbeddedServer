#ifndef _SCOPE_MUTEX_H_
#define _SCOPE_MUTEX_H_


#include <pthread.h>

namespace jThread
{


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
    pthread_mutex_t* getMutex(){return &m_pmutex; };

private:
    pthread_mutex_t       m_pmutex;
    bool                  m_isOwner;

};

class CriticalSection {
public:
  CriticalSection ( ScopeMutex & M  );
  virtual ~CriticalSection();

protected:
  ScopeMutex*	mMutex;
};

}

#endif // _MUTEX_H_
