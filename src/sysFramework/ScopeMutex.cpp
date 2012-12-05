#include <cerrno>
#include "thread/ScopeMutex.h"

jThread::ScopeMutex::ScopeMutex()
:m_isOwner(true)
{
    if (pthread_mutex_init( (pthread_mutex_t * ) &m_pmutex, 0) == 0)
    {

    }

}

jThread::ScopeMutex::~ScopeMutex()
{
    if (m_isOwner)
    {
        if (pthread_mutex_destroy(&m_pmutex) == EBUSY)
        {
            unlock();
            pthread_mutex_destroy(&m_pmutex);
        }
    }
}

jThread::ScopeMutex::ScopeMutex(const ScopeMutex& copy)
{
    m_pmutex = copy.m_pmutex;
    m_isOwner = false;
}

bool jThread::ScopeMutex::lock()
{
#if 0
	  int ret=0;

	  do {
	    errno = 0;
	    ret = pthread_mutex_lock( &m_pmutex);
	  } while ( ret == -1 && errno == EINTR );

	  if(0 != ret) return false;
	  return true;
#endif

#if 1
    if (pthread_mutex_lock(&m_pmutex) == 0)
        return true;
    return false;
#endif
}

bool jThread::ScopeMutex::unlock()
{
#if 0
	  int ret=0;

	  do {
	    errno = 0;
	    ret = pthread_mutex_lock( &m_pmutex );
	  } while ( ret == -1 && errno == EINTR );

	  if(0 != ret) return false;
	  return true;
#endif
#if 1
    if (pthread_mutex_unlock(&m_pmutex) == 0)
        return true;
    return false;
#endif
}

bool jThread::ScopeMutex::tryLock()
{
    if (pthread_mutex_trylock(&m_pmutex) == 0)
        return true;
    return false;
}



jThread::CriticalSection::CriticalSection ( jThread::ScopeMutex & M )
{
  mMutex = &M;



  mMutex->lock();

 }

jThread::CriticalSection::~CriticalSection (  )
{
  mMutex->unlock();
}

