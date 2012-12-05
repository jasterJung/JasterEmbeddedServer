//#include "config.h"
#include <memory>
#include <iostream>

#include <string.h>

#if 0
#include "SysPlusPlus/Tools.h"
#include "SysPlusPlus/GenCfg.h"
#include "SysPlusPlus/syscall.h"
#include "ComPlusPlus/Comm.h"
#include "ComPlusPlus/File.h"
#include "ComPlusPlus/Poll.h"
#include "SysPlusPlus/ComException.h"

#include "ComPlusPlus/Socket.h"
#include "ComPlusPlus/SocketUdp.h"
#include "ComPlusPlus/SocketTcp.h"
#endif

#include "socket/CommonSocket.h"

/**
 * Constructor:
 * - FD is attached accoring to GenComm Config Class
 * - Readtimeout set accoring to GenComm Config Class
 * - Readtimeout set accoring to GenComm Config Class
 * - WriteTimeout accoring to GenComm Config Class
 * - MaxnumBytesToRead set accoring to GenComm Config Class
*/

#define MAXUDP 65536

socket::CommonSocket::CommonSocket ( unsigned int readaheadbuffersize ) {

  this->fd=-1;

  compp::GenCfg * Cfg = (compp::GenCfg*) compp::GenCfg::Instance();

  // By default always off
  this->ReadAhead                = false;

  this->ReadAheadBuffer          = NULL;
  this->ReadAheadBufferTotalSize = readaheadbuffersize ;
  this->ReadAheadBufferSize      = 0;
  this->ReadAheadBufferIndex     = 0;

  this->fd_attached       = Cfg->GetCommFDAttached ();
  this->WriteTimeout      = Cfg->GetCommWriteTimeout()  ;
  this->ReadTimeout       = Cfg->GetCommReadTimeout()  ;
  this->MaxNumBytesToRead = Cfg->GetCommMaxNumBytesToRead();
  this->LineDelimiter = '\n';

  IsOpen=false;
  FdClosed=false;

}

/**
 * Destructor:
 * std::close() called if Comm Channel was attached
 * ATTENTION: It might be adviseable to use Shutdown
 * beforehand on sockets. If not used, unset data could be lost.
*/
socket::CommonSocket::~CommonSocket ( ) {

  if ( NULL != ReadAheadBuffer ) {
    delete ReadAheadBuffer;
  }

  if ( this->fd == -1 )
    return ;

  if ( FD_IsAttached() )
      this->Close ();

}

/**
 *  Attach the FD.
 * An attached Comm Channel is automatically closed by the
 * destructor.
 */
void socket::CommonSocket::AttachFD() {
    this->fd_attached = true;
}

/*
 *  Deattach the FD.
 */
void socket::CommonSocket::DetachFD () {
    this->fd_attached = false;
}

/**
 *  Get Attache status.
 * Returnvalue is true is Comm Channel is attached.
 */
bool socket::CommonSocket::FD_IsAttached() {
    return this->fd_attached;
}

/**
 *  Close the descriptor usind close().
 * ATTENTION: Could be improper, if under
 */
void socket::CommonSocket::Close ( ) {

  if ( this->fd==-1 )
    return ;

  syspp::Call::Close(this->fd);

  IsOpen=false;
  this->fd=-1;
  this->ReadAheadBufferSize      = 0;
  this->ReadAheadBufferIndex     = 0;

}

/**
  Throws sys:ComException in case of error
*/

bool socket::CommonSocket::PollSnd ( int usecs )  {

  if ( this->fd == -1  ) {
    throw  syspp::ComException (  "socket::CommonSocket::Ressource not opened");
  }

  fd_set wrset, errset;
  struct timeval tv, *tvp;

  FD_ZERO( & wrset );
  FD_ZERO( & errset );

  if ( usecs >= 0 ) {
    memset   (&tv, 0, sizeof(tv));
    tv.tv_sec  = usecs / 1000000;
    tv.tv_usec = usecs % 1000000;
    tvp = &tv;
  } else
    tvp = NULL;

    int sfd = this->fd;

    FD_SET( sfd, &wrset);
    FD_SET( sfd, &errset);

    switch ( syspp::Call::Select ( sfd + 1, NULL,  &wrset,  &errset, tvp ) ) {
    case -1: {
      throw  syspp::ComException (  "socket::CommonSocket::PollSnd. Select failed" );
      break;
    }
    case 0: {
      return false;
    }
    case 1: {
      if ( FD_ISSET( sfd, &wrset ) )
	return true;
      else {
        return false ; // actually impossible
      }
    }
    default: {
        return false ; // actually impossible
    }
    }

    // Never reached
    return false;
}

/**
 *  Polling (actually select()) on the socket read queue.
 * Throws sys:ComException in case of error
 */
bool socket::CommonSocket::PollRcv ( int usecs )  {

  if ( this->fd == -1 ) {
    throw  syspp::ComException (  "socket::CommonSocket::Ressource not opened");
  }

  fd_set rdset, errset;
  struct timeval tv, *tvp;

  FD_ZERO( & rdset );
  FD_ZERO( & errset );

  if ( usecs >= 0 ) {
    memset   (&tv, 0, sizeof(tv));
    tv.tv_sec  = usecs / 1000000;
    tv.tv_usec = usecs % 1000000;
    tvp = &tv;
  } else
    tvp = NULL;

    int sfd = this->fd;

    FD_SET( sfd, &rdset);
    FD_SET( sfd, &errset);


    switch ( syspp::Call::Select ( sfd + 1, &rdset, NULL, &errset, tvp ) ) {
    case -1: {
      throw  syspp::ComException (  "socket::CommonSocket::PollRcv. Select failed" );
      break;
    }
    case 0: {
      return false;
    }
    case 1: {
      if ( FD_ISSET( sfd, &rdset ) )
	return true;
      else {
	return false;
      }
    }
    default: {
	return false;
    }
    }

    // Never reached
    return false;
}


/**
 * Making Comm Channel synchronous.
 */
bool socket::CommonSocket::SetOptBlocking () {

#if 0
u_long iMode = 0;
syspp::Call::Ioctlsocket(this->fd, FIONBIO, &iMode);
return true;
#else
    int i;

    i =  syspp::Call::Fcntl ( this->fd, F_GETFL, 0L ) ;

    if ( -1 == i ) {
	throw  syspp::ComException (  "socket::CommonSocket::SetOptBlocking (): Could not call fcntl()");
    }

    i ^= O_NONBLOCK;

    i = syspp::Call::Fcntl ( this->fd, F_SETFL, i );

    if ( -1 == i ) {
	throw  syspp::ComException (  "socket::CommonSocket::SetOptBlocking  Cannot Set Option Blocking");
    }

    return true;
#endif
}

/**
 * Making Comm Channel asynchronous.
 */
bool socket::CommonSocket::SetOptNonBlocking ( ) {

  int i;

  i =  syspp::Call::Fcntl ( this->fd, F_GETFL, 0L ) ;

  if ( -1 == i ) {
    throw  syspp::ComException (  "socket::CommonSocket::SetOptNonBlocking Could not call fcntl(GETFL)");
  }

  i |= O_NONBLOCK;
  i = syspp::Call::Fcntl ( this->fd, F_SETFL, i );

  if ( -1 == i ) {
    throw  syspp::ComException (  "socket::CommonSocket::SetOptNonBlocking Could not call fcntl(SETFL)");
  }

  return true;
}

/**
  * Returns true, if the Comm Channel is closed
  * Evaluation of this state: never initialsed or closed or other party closed connection
  */
bool socket::CommonSocket::IsEOF () const{
  if ( this->fd == -1 || FdClosed == true || IsOpen == false ) {
    return true;
  }

  return false;
}


/**
 * Perform simple write(). Number of actually sent bytes in return value.
 * Throws CommException, if error occured.
 * Can be used on all sockets.
 */
int socket::CommonSocket::Write ( const char *buf, const int count ) {


  if ( this->fd == -1 || !IsOpen || FdClosed ) {
    throw  syspp::ComException (  "socket::CommonSocket::Ressource not opened");
  }

  int ret;

 ret = syspp::Call::Send ( this->fd, (void *) buf, count, 0 );

  if ( ret == -1 && errno == EBADF )
  	  FdClosed=true;

  return ret;
}


/**
 * Write string. Returns the length of the sent string.
 * Throws ComException, if error occured.
 */
int socket::CommonSocket::Write ( const std::string & buf ) {

  if ( this->fd == -1 || !IsOpen || FdClosed ) {
    throw  syspp::ComException (  "socket::CommonSocket::Ressource not opened");
  }

  int ret;

  ret = Write ( (char *) buf.data(), buf.length()) ;
  return ret;
}


/**
 *  R. Steven's writen() on the Comm Channel.
 * If WriteTimeout >0 the timeout is considered
 * Returnvalue is the number of bytes successfully written
 * Throws sys:ComException in case of error.
 */
int socket::CommonSocket::Writen ( const char *buf, int count ) {

  if ( this->fd == -1 || !IsOpen || FdClosed ) {
    throw  syspp::ComException (  "socket::CommonSocket::Ressource not opened");
  }

  int i= 0, len = count;
  int remain=0;
  char *c = (char*) buf;
  syspp::int64 from =0, to = 0, now = 0;

  if ( len == 0 )
    return 0;

  if ( WriteTimeout > 0 ) {
    from = syspp::Tools::Time64();
    now = from;
    to = from + WriteTimeout;
  }

  for ( remain = len ; remain > 0;  ) {

    if ( PollSnd ( to - now  ) == false ) {
      errno = EAGAIN;
      return -1;
    }

    i = Write ( c, remain);

    if ( i == -1 && errno == EBADF ) {
      FdClosed=true;
    }

   if ( i <= 0 ) {
     if ( errno != EAGAIN )
       throw syspp::ComException ( "Error writing to Comm Channel" );
     if ( i == 0 )
       errno = 0;
     return i;

   } else {
     remain -= i;

     if ( remain  == 0 )
       return len;

     if ( remain > 0)
       c += i;
   }

   if ( WriteTimeout > 0 ) {

     now = syspp::Tools::Time64();

     if ( now > to ) {
	errno = EAGAIN;
	return (len - remain);
     }
   }
 }

 return len;
}

/**
 * R. Steven's writen() of a string.
 * Throws sys:ComException, if things go wrong.
 */
int socket::CommonSocket::Writen ( const std::string & buf ) {

//   if ( dynamic_cast<compp::SocketUdp*>(this) !=NULL ) {
// 	compp::SocketUdp *s = dynamic_cast<compp::SocketUdp*>(this);
//   	s->Send(buf.c_str() , buf.length() );
//   	return buf.length();
//   }

  if ( this->fd == -1 || !IsOpen || FdClosed ) {
    throw  syspp::ComException (  "socket::CommonSocket::Ressource not opened");
  }

  return Writen ( buf.c_str(), buf.length() ) ;
}


int socket::CommonSocket::operator<< ( const std::string & buf ) {

	return Writen (buf );

}

/**
 * Simple Read().
 * Throws sys:ComException in case of error
 *
 */
int socket::CommonSocket::Read ( char *buf, int count ) {

  if ( count <= 0 )
    return count;

  if ( this->fd == -1 || !IsOpen || FdClosed ) {
    throw  syspp::ComException (  "socket::CommonSocket::Ressource not opened");
  }

  int ret;
  //   std::cout << "Read ReadAheadBufferSize:" <<ReadAheadBufferSize << " ReadAhead:" << ReadAhead <<"\n" ;
  if ( ReadAhead == false ) {

    ret = syspp::Call::Recv ( this->fd, (void *) buf, count,0  );
    if ( ret == 0  )
      FdClosed=true;
    return ret ;
  }


  // Read ahead enabled
  if ( this->ReadAheadBufferSize == 0 ) {    // Buffer empty
     if ( (unsigned int ) count > ReadAheadBufferTotalSize ) {  // Special Case: More ocets requested than sizeof buffer. Solution: bypassing buffer.
     ret = syspp::Call::Recv ( this->fd, (void *) buf, count, 0 );
     //     std::cout << "Special Case\n" ;
       if ( ret == 0  )
 	FdClosed=true;
       return ret;
     }
    // Buffer Reload
    // Buffer is empty and we request less than number of buffered octets
    this->ReadAheadBufferSize = syspp::Call::Recv( this->fd, (void *) this->ReadAheadBuffer, ReadAheadBufferTotalSize , 0);
    //     std::cout << "Reload ReadAheadBufferSize:" << ReadAheadBufferSize  << "\n" ;

    this->ReadAheadBufferIndex = 0;
    if ( this->ReadAheadBufferSize  <= 0) {
      FdClosed=true;
      return this->ReadAheadBufferSize;
    }

  }

  // Octets copied from Buffer
  if ( ( unsigned int ) count > ( this->ReadAheadBufferSize - this->ReadAheadBufferIndex) )  {
    count = this->ReadAheadBufferSize- this->ReadAheadBufferIndex;   // Request empties the buffer
  }

  memcpy ( (void*) buf, (void*) & (this->ReadAheadBuffer[this->ReadAheadBufferIndex]),  count );
  ret = count ;
  this->ReadAheadBufferIndex += count;
   if ( this->ReadAheadBufferIndex == this->ReadAheadBufferSize ) {
    this->ReadAheadBufferIndex = 0;
    this->ReadAheadBufferSize = 0;
  }

  return ret;
}


/**
 * Read a maximum of count characters and store into string.
 * Throws sys:ComException in case of error
 */
int socket::CommonSocket::Read ( std::string &buf, int count ) {

  if ( this->fd == -1 || !IsOpen || FdClosed ) {
    throw  syspp::ComException (  "socket::CommonSocket::Ressource not opened");
  }

    buf = "";
    char c[1000] ;
    int ret;
    int i;

    for ( i = 0; i < count; ) {
	if ( ( ret = Read (c, count-i )) == -1 ) {
			throw syspp::ComException ( " Read Error ");
    	}
        if ( ret == 0 ) {
  	  FdClosed=true;
	  return i;
        }
    	buf.append ( c, ret );
    	i += ret;
	if ( ret != ( count-i ))
	  return i;
    }
    return i;
}


/**
 * Read until a newline is found (similar to Readln found in Pascal ).
 * not optimized. Still very slow.
 */
bool socket::CommonSocket::ReadLn ( char * buf, int count ) {

  if ( dynamic_cast<compp::SocketUdp*>(this) !=NULL ) {
  	    throw  syspp::ComException (  "socket::CommonSocket::ReadLn does not make sense on UDP Socket");
  }

  if ( this->fd == -1 || !IsOpen || FdClosed ) {
    throw  syspp::ComException (  "socket::CommonSocket::Ressource not opened");
  }

  int i, j;
  char c;

  std::memset ( buf, (int)0, count);
  for ( i=0; i<count; ++i ) {
    if ( PollRcv ( ReadTimeout )) {
      j = Read( &c, 1 );
      if ( j == 0)
	return false;

      if ( c == this->LineDelimiter ) {
	buf[i] = '\0';
	return true;
      }

      buf[i] = c;
    } else
      return false;
  }

  return false;
}

/**
 * Readln . Result placed in string.
 * Throws sys:ComException in case of error
 *
 */
bool socket::CommonSocket::ReadLn ( std::string & s ) {

  s ="";
  if ( dynamic_cast<compp::SocketUdp*>(this) !=NULL ) {
  	    throw  syspp::ComException (  "socket::CommonSocket::ReadLN does not make sense on UDP Socket");
  }

  if ( this->fd == -1 || !IsOpen || FdClosed ) {
    throw  syspp::ComException (  "socket::CommonSocket::Ressource not opened");
  }

  int i, j;
  char c;

  for ( i=0; i < this->MaxNumBytesToRead; ++i ) {
    if ( PollRcv ( this->ReadTimeout )) {
      j = Read( &c, 1 );
      if ( j == 0)
	return false;

      if ( c == this->LineDelimiter ) {
	return true;
      }

      s += c;
    } else
      return false;
  }
  return false;
}

/**
 * R. Steven's readn() .
 * Reads count bytes into buf. Considers ReadTimeout
 * Throws sys:ComException in case of error
 */

int socket::CommonSocket::Readn ( char *buf, int count )  {

  if ( this->fd == -1 || !IsOpen || FdClosed ) {
    throw  syspp::ComException (  "socket::CommonSocket::Ressource not opened");
  }

  int i=0, bytesdone =0, len = count, timeleft;
  int remain;
  char *c = (char*) buf;
  syspp::int64 from=0, to=0, now =0 ;


  if ( ReadTimeout > 0 ) {
    from = syspp::Tools::Time64() ;
    to = from + ReadTimeout;
    now = syspp::Tools::Time64() ;
  }


  for ( remain = len ; remain > 0;  ) {
    errno = 0;

    if ( ReadTimeout > 0 ) {
      timeleft = to - now;

      if ( ( false == this->ReadAhead ) ||
	   ( true == this->ReadAhead &&(  this->ReadAheadBufferSize == 0 || this->ReadAheadBufferIndex >= this->ReadAheadBufferSize ) ) ) {

	if ( PollRcv ( timeleft ) == false ) {
	  errno = EAGAIN;
	  return -1;
	}
      }
    }

    i = Read (  c, remain);
    if ( i == 0 ) {
      errno = 0;
      if (  count > 0 )
	FdClosed=true;
      return bytesdone;
    }
    if ( i < 0 ) {
      if ( errno != EAGAIN ) {
      	throw syspp::ComException ( "Read Error ");
      } else {
	errno = 0;
      }
    } else {
      remain -= i;
      if ( remain  == 0 ) {
	errno = 0;
	return len;
      }

      if ( remain > 0) {
	c += i;
	bytesdone+=i;
      }
    }

    if ( ReadTimeout > 0 ) {

      now = syspp::Tools::Time64();
      if ( now > to) {
	errno = EAGAIN;
	return (len - remain);
      }
    }
  }

  return len;
}

/**
 * R. Steven's  Readn() . Result stored in string.
 * Comsiders ReadTimeout and the count parameter.
 * This method reads up to count bytes from the Comm Channel.
 * If the timeout expires.
 * Returnvalue is number of bytes read.
 * Throws sys:ComException in case of error
 */
int socket::CommonSocket::Readn ( std::string &buf, int count ) {

  if ( this->fd == -1 || !IsOpen || FdClosed ) {
    throw  syspp::ComException (  "socket::CommonSocket::Ressource not opened");
  }

  int i;
  std::auto_ptr<char> c (new char[count+1]);

  try {
    i = this->Readn ( (char*)c.get(),  count ) ;
    buf= "";
    buf.append ( c.get(), i );
  } catch ( syspp::ComException e)  {
	  	throw syspp::ComException( e.what());
  }
  return i;

}

/**
 *  Set MaxNumBytesToRead. This parameter is stored ni the object
 * and and is releveant to all Read.. () methods, which
 * do not have "count" parameter.
 */
void socket::CommonSocket::SetMaxNumBytesToRead ( int num ) {
  MaxNumBytesToRead = num;
}

/**
  * Modifier
  **/
void socket::CommonSocket::SetWriteTimeout( int tmout  ) {
  WriteTimeout = tmout ;
}
/**
  * Accessor
  **/
int socket::CommonSocket::GetWriteTimeout( ) const {
  return WriteTimeout  ;
}
/**
  * Modifier
  **/
void socket::CommonSocket::SetReadTimeout( int tmout ) {
  ReadTimeout = tmout ;
}
/**
  * Accessor
  **/
int socket::CommonSocket::GetReadTimeout() const {
  return ReadTimeout ;
}

/**
  * Accessor
  **/
int socket::CommonSocket::GetFd () const {
  return fd;
}

/**
  * Modifier
  **/
void socket::CommonSocket::SetLineDelimiter ( char c ) {
   this->LineDelimiter = c;
}
/**
  * Modifier
  **/
void socket::CommonSocket::SetReadAhead ( bool yn ) {

   if ( dynamic_cast<compp::SocketUdp*>(this) !=NULL ) {
     this->ReadAhead = false;
     return;
   }

   if ( true == this->ReadAhead && NULL != ReadAheadBuffer) {
     delete  [] ReadAheadBuffer;
     ReadAheadBuffer = NULL;
   }

   this->ReadAhead = yn;

   if ( true == ReadAhead ) {
     if ( ReadAheadBufferTotalSize > 0 ) {
       ReadAheadBuffer = new char [ReadAheadBufferTotalSize];
     } else {
       this->ReadAhead = false;
       ReadAheadBuffer = NULL;
     }
   } else {
     if ( NULL != ReadAheadBuffer ) {
       delete ReadAheadBuffer;
     }
   }
}
