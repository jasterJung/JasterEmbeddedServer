#ifndef _COMMON_NET_
#define _COMMON_NET_


#include <errno.h>
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/socket.h>
#include <netdb.h>
#include <sys/select.h>


namespace common {

  class  Net{

  protected:

  public:
    static int Open ( const char *pn, int flags, mode_t mode ) ;
    static int Open ( const char *pn, int flags ) ;
    static int Close ( int fd );
    static int Shutdown ( int fd, int hown );
    static int Write ( int fd, void *buf, int count  ) ;
    static int Read ( int fd, void *buf, int count  ) ;
    static int Listen ( int fd, int backlog );
    static int Select ( int n,  fd_set *rdset, fd_set *wset, fd_set *except_set , struct timeval *tv ) ;
    static int Fcntl ( int fd, int cmd );
    static int Fcntl ( int fd, int cmd, long arg );
    static int Fcntl ( int fd, int cmd, struct flock *lock );
    static int Gettimeofday ( struct timeval *tv, struct timezone *tz );
    static int Setsockopt (int fd,int level, int optname, void *optval, int optlen ) ;
    static int Getpid ( ) ;
    static int Accept ( int fd, struct sockaddr *addr, int *addrlen  );
    static int Lseek ( int fd, off_t offset, int whence  );
    static int Sem_init ( sem_t * sem, int pshared, unsigned value  );
    static int Sem_destroy ( sem_t *sem );
    static int Sem_post ( sem_t *sem );
    static int Sem_wait ( sem_t *sem );
    static int Sem_trywait ( sem_t *sem );
    static int Pthread_mutex_init( pthread_mutex_t * mutex, const pthread_mutexattr_t * attr);
    static int Pthread_mutex_destroy( pthread_mutex_t * mutex) ;
    static int Pthread_mutex_lock( pthread_mutex_t * mutex) ;
    static int Pthread_mutex_trylock( pthread_mutex_t * mutex) ;
    static int Pthread_mutex_unlock( pthread_mutex_t * mutex);
    static int Unlink ( const char * fn  );
    static void * Malloc ( size_t size  );
    static void * Realloc ( void* ptr, size_t size  );
    static pid_t Fork(void);
    static int   Chdir(const char *dir );
    static int   Kill( pid_t p, int sig );
    static int Connect(int sockfd, const struct sockaddr *serv_addr, int addrlen);
    static int Getsockopt(int s, int level, int optname, void *optval, int *optlen);
    static int Setsockopt(int s, int level, int optname, const void *optval, int optlen);
    static ssize_t Send(int s, const void *buf, size_t len, int flags);
    static ssize_t Sendto(int s, const void *buf, size_t len, int flags, const struct sockaddr *to, int tolen);
    static ssize_t Sendmsg(int s, const struct msghdr *msg, int flags);
    static ssize_t Recv(int s, void *buf, size_t len, int flags);
    static ssize_t Recvfrom(int s, void *buf, size_t len, int flags, struct sockaddr *from, int *fromlen);
    static ssize_t Recvmsg(int s, struct msghdr *msg, int flags);
    static int Socket(int domain, int type, int protocol);
    static int Bind(int sockfd, struct sockaddr *my_addr, int addrlen);
    static int Pthread_create(pthread_t * thread, pthread_attr_t * attr, void * (*start_routine)(void *), void * arg);
    static int Pthread_join(pthread_t th, void **thread_return);
    static int Pthread_kill(pthread_t thread, int signo);
    static int Pthread_detach(pthread_t th);
    static int ShmGet(int key, int size, int flgs =0);
    static void * ShmAt(int shmid, const void *shmaddr, int shmflg) ;
    static int ShmDt(const void *shmaddr) ;
    static int ShmCtl( int ShmMemId, int cmd, void * buffer) ;
    static void Sleep( int s) ;
    static void Usleep( int s) ;
    static int Waitpid( int pid, int *status, int i ) ;
    static int Chmod(const char *path, const mode_t mode) ;
    static int FChmod(const int fd, const mode_t mode) ;


  };
}

#endif
