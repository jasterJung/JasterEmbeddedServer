#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <sys/ipc.h>
#include <sys/shm.h>


#include <sys/types.h>
#include <sys/wait.h>



#include <fcntl.h>

#include <sys/time.h>

//#include <process.h>
#include <iostream>

#include "common/CommonNet.h"

// *******************************************************************************

int common::Net::Open ( const char *pn, int flags, mode_t mode ) {

  return open ( pn, flags, mode );

}

// *******************************************************************************

int common::Net::Open ( const char *pn, int flags ) {

  return open ( pn, flags );

}

// *******************************************************************************

int common::Net::Close ( int fd ) {

  return close ( fd );

}

// *******************************************************************************

int common::Net::Shutdown ( int fd, int hown ) {

  return close ( fd );

}

// *******************************************************************************

int common::Net::Write ( int fd, void *buf, int count  ) {
  int ret ;

  do {
    errno = 0;
    ret = write ( fd, buf, count  ) ;
  } while ( ret == -1 && errno == EINTR );

  return ret;
}

// *******************************************************************************

int common::Net::Read ( int fd, void *buf, int count  ) {
  int ret;
			 
  do {
    errno = 0;
    ret = read ( fd,  buf, count  ) ;
  } while ( ret == -1 && errno == EINTR );
  return ret;

}

// *******************************************************************************

int common::Net::Listen ( int fd, int backlog ) {
  int ret;
			 
  do {
    errno = 0;
    ret = listen ( fd, backlog ) ;
  } while ( ret == -1 && errno == EINTR );
  return ret;

}

// *******************************************************************************
int common::Net::Select ( int n,  fd_set *rdset, fd_set *wset, fd_set *except_set , struct timeval *tv ) {
  int ret;
			 
  do {
    errno = 0;
    ret = select ( n, rdset, wset, except_set, tv );
  } while ( ret == -1 && errno == EINTR );
  return ret;

}

// *******************************************************************************

int common::Net::Fcntl ( int fd, int cmd ) {
  int ret;
			 
  do {
    errno = 0;
    ret = fcntl (fd, cmd); 
  } while ( ret == -1 && errno == EINTR );
  return ret;

}

// *******************************************************************************
int common::Net::Fcntl ( int fd, int cmd, long arg ) {
  int ret;
			 
  do {
    errno = 0;
    ret = fcntl (fd, cmd, arg); 
  } while ( ret == -1 && errno == EINTR );
  return ret;

}

// *******************************************************************************
int common::Net::Fcntl ( int fd, int cmd, struct flock *lock ) {

  int ret;
			 
  do {
    errno = 0;
    ret = fcntl (fd, cmd, lock); 
  } while ( ret == -1 && errno == EINTR );
  return ret;
}

// *******************************************************************************

int common::Net::Setsockopt (int fd, int level, int optname, void *optval, int optlen ) {
  int ret=0;
			 
  do {
    errno = 0;
    ret = setsockopt ( fd, level, optname, optval, optlen ) ;

  } while ( ret == -1 && errno == EINTR );

  return ret;
}

// *******************************************************************************

int common::Net::Getpid (  ) {

  return getpid () ;
}

// *******************************************************************************

int common::Net::Accept ( int fd, struct sockaddr *addr, int *addrlen  ) {

  int ret=0;
			 
  do {
    errno = 0;

    ret = accept ( fd, addr, (socklen_t*) addrlen );

//     ret = accept ( fd, addr, addrlen );

  } while ( ret == -1 && errno == EINTR );

  return ret;
}


// *******************************************************************************

int common::Net::Sem_init ( sem_t * sem, int pshared, unsigned value ) {

  int ret=0;
			 
  do {
    errno = 0;
    ret = sem_init (sem, pshared, value );
  } while ( ret == -1 && errno == EINTR );

  return ret;


}


// *******************************************************************************

int common::Net::Sem_destroy ( sem_t *sem ) {

  int ret=0;
			 
  do {
    errno = 0;
    ret = sem_destroy (sem );
  } while ( ret == -1 && errno == EINTR );

  return ret;

}


// *******************************************************************************

int common::Net::Sem_post ( sem_t *sem ){

  int ret=0;
			 
  do {
    errno = 0;
    ret = sem_post (sem );
  } while ( ret == -1 && errno == EINTR );

  return ret;

}


// *******************************************************************************

int common::Net::Sem_wait ( sem_t *sem ){

  int ret=0;
			 
  do {
    errno = 0;
    ret = sem_wait (sem );
  } while ( ret == -1 && errno == EINTR );

  return ret;

}


// *******************************************************************************

int common::Net::Sem_trywait ( sem_t *sem ){

  int ret=0;
			 
  do {
    errno = 0;
    ret = sem_trywait (sem );
  } while ( ret == -1 && errno == EINTR );

  return ret;


}


// *******************************************************************************

int common::Net::Unlink ( const char *fn ){

  int ret=0;
			 
  do {
    errno = 0;
    ret = unlink (fn );
  } while ( ret == -1 && errno == EINTR );

  return ret;
}


// *******************************************************************************

int common::Net::Pthread_mutex_init( pthread_mutex_t * mutex, const pthread_mutexattr_t * attr) {

  int ret=0;
			 
  do {
    errno = 0;
    ret = pthread_mutex_init( (pthread_mutex_t * ) mutex, (const pthread_mutexattr_t *) attr);
  } while ( ret == -1 && errno == EINTR );

  return ret;


}


// *******************************************************************************

int common::Net::Pthread_mutex_destroy( pthread_mutex_t * mutex) {

  int ret=0;
			 
  do {
    errno = 0;
    ret = pthread_mutex_destroy( mutex);
  } while ( ret == -1 && errno == EINTR );

  return ret;

}


// *******************************************************************************

int common::Net::Pthread_mutex_lock( pthread_mutex_t * mutex) {

  int ret=0;
			 
  do {
    errno = 0;
    ret = pthread_mutex_lock( mutex);
  } while ( ret == -1 && errno == EINTR );

  return ret;


}


// *******************************************************************************

int common::Net::Pthread_mutex_trylock( pthread_mutex_t * mutex) {

  int ret=0;
			 
  do {
    errno = 0;
    ret = pthread_mutex_trylock( mutex);
  } while ( ret == -1 && errno == EINTR );

  return ret;


}


// *******************************************************************************

int common::Net::Pthread_mutex_unlock( pthread_mutex_t * mutex) {

  int ret=0;
			 
  do {
    errno = 0;
    ret = pthread_mutex_unlock( mutex);
  } while ( ret == -1 && errno == EINTR );

  return ret;


}

// *******************************************************************************

int common::Net::Lseek ( int fd, off_t offset, int whence  ) {

  int ret=0;
			 
  do {
    errno = 0;
    ret = lseek ( fd, offset, whence );
  } while ( ret == -1 && errno == EINTR );

  return ret;
			  

}

// *******************************************************************************
int common::Net::Gettimeofday( struct  timeval *t,  struct timezone *tz ) {

  return gettimeofday(t, NULL ) ;


}

// *******************************************************************************


void * common::Net::Malloc ( size_t size  ) {

  void * ret ;
  ret = malloc ( size );
  if ( ret == NULL ) {
    std::cout << "PANIC: OUT OF Memory(Malloc)\n";
    exit(0);
  }
  return ret;

}
// *******************************************************************************

void * common::Net::Realloc ( void *ptr, size_t size  ) {

  void * ret = realloc ( ptr, size );
  if ( ret == NULL ) {
    std::cout << "PANIC: OUT OF Memory(Realloc)\n";
    abort();
  }
  return ret;
}
// *******************************************************************************

pid_t common::Net::Fork(void) {

  pid_t p = fork ();
  if ( p == -1 ) {
    std::cout << "PANIC! Cannot start new process (fork).\n";
    abort();
  }
  return p;

}

// *******************************************************************************
int common::Net::Chdir(const char *dir ) {

  return chdir ( dir );

}
			 
// *******************************************************************************

int common::Net::Kill( pid_t p, int sig ){

  return kill ( p, sig );

}

// *******************************************************************************

int common::Net::Connect(int sockfd, const struct sockaddr *serv_addr, int addrlen){
  int ret ;

  do {
    errno = 0;
    ret = connect( sockfd, serv_addr, addrlen);
  } while ( ret == -1 && errno == EINTR );

  return ret;
}

// *******************************************************************************

int common::Net::Getsockopt(int s, int level, int optname, void *optval, int *optlen){



  return getsockopt( s, level, optname, optval,(socklen_t*) optlen);
}

// *******************************************************************************

int common::Net::Setsockopt(int s, int level, int optname, const void *optval, int optlen){

  return setsockopt( s, level, optname, optval, (socklen_t) optlen);

}

// *******************************************************************************

ssize_t common::Net::Send(int s, const void *buf, size_t len, int flags){

  int ret ;

  do {
    errno = 0;
    ret = send ( s, buf, len, flags );
  } while ( ret == -1 && errno == EINTR );

  return ret;

}
// ******************************************************************************
ssize_t common::Net::Sendto(int s, const void *buf, size_t len, int flags, const struct sockaddr *to, int tolen){

  int ret ;

  do {
    errno = 0;
    ret = sendto(s, buf, len, flags, to, tolen);

  } while ( ret == -1 && errno == EINTR );

  return ret;

}
// *******************************************************************************
ssize_t common::Net::Sendmsg(int s, const struct msghdr *msg, int flags){
  int ret ;

  do {
    errno = 0;
    ret = sendmsg ( s, msg, flags );
  } while ( ret == -1 && errno == EINTR );

  return ret;

}

// *******************************************************************************

ssize_t common::Net::Recv(int s, void *buf, size_t len, int flags){

  int ret ;

  do {
    errno = 0;
    ret = recv ( s, buf, len, flags );
  } while ( ret == -1 && errno == EINTR );

  return ret;

}

// *******************************************************************************
ssize_t common::Net::Recvfrom(int s, void *buf, size_t len, int flags, struct sockaddr *from, int *fromlen){

  int ret ;

  do {
    errno = 0;
    ret = recvfrom ( s, buf, len, flags, from, (socklen_t*)fromlen );
  } while ( ret == -1 && errno == EINTR );

  return ret;
}

// *******************************************************************************
ssize_t common::Net::Recvmsg(int s, struct msghdr *msg, int flags){

  int ret ;

  do {
    errno = 0;
    ret = recvmsg ( s, msg, flags );
  } while ( ret == -1 && errno == EINTR );

  return ret;

}

// *******************************************************************************

int common::Net::Socket(int domain, int type, int protocol){
  return socket(domain, type, protocol);
}

// *******************************************************************************

int common::Net::Bind(int sockfd, struct sockaddr *my_addr, int addrlen){

  return bind ( sockfd, my_addr, addrlen);

}


// *******************************************************************************

int common::Net::Pthread_create(pthread_t * thread, pthread_attr_t * attr, void * (*start_routine)(void *), void * arg){

  return pthread_create( thread, attr, start_routine, arg);

}
// *******************************************************************************
int common::Net::Pthread_join(pthread_t th, void **thread_return){

  return pthread_join( th, thread_return);

}
// *******************************************************************************
int common::Net::Pthread_kill(pthread_t thread, int signo){

  return pthread_kill( thread, signo);

}
// *******************************************************************************
int common::Net::Pthread_detach(pthread_t th){

  return pthread_detach( th);

}
// *******************************************************************************
int common::Net::ShmGet(int key, int size, int flgs ){

  return shmget( key, size, flgs);


}
// *******************************************************************************
void* common::Net::ShmAt(int shmid, const void *shmaddr, int shmflg) {

  return shmat( shmid, shmaddr,  shmflg);

}

// *******************************************************************************
int common::Net::ShmDt(const void *shmaddr) {

  return shmdt( shmaddr );


}

// *******************************************************************************

int common::Net::ShmCtl( int ShmMemId, int cmd, void * dst) {

  struct shmid_ds buffer;
  int ret;
  ret = shmctl( ShmMemId, cmd , &buffer) ;

  if ( ret == -1 )
    return -1;

  if ( dst != NULL ) {
    memcpy ( dst, (void*) &buffer, sizeof( buffer ));
  }
  return ret;

}

// *******************************************************************************
void  common::Net::Sleep( int s) {
  struct timeval tv;

  tv.tv_sec = s;
  tv.tv_usec = 0;

  select ( 0,NULL, NULL, NULL, &tv );

}


// *******************************************************************************
void common::Net::Usleep( int s) {

  struct timeval tv;

  tv.tv_sec =  s/1000000;
  tv.tv_usec = s%1000000;

  select ( 0,NULL, NULL, NULL, &tv );

}

// *******************************************************************************
int common::Net::Waitpid( int pid, int * status, int i ) {
  
  int ret =0;
  do {
    errno = 0;
    ret = waitpid( pid, status, i );
  } while ( ret == -1 && errno == EINTR );

  return ret;

}


// *******************************************************************************

int common::Net::Chmod(const char *path, const mode_t mode) {

  return chmod( path,  mode);

}

// *******************************************************************************

int common::Net::FChmod(const int fd, const mode_t mode) {

  return fchmod( fd, mode);

}

// *******************************************************************************




