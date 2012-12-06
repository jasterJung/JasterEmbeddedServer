//#include "config.h"
#include <memory>
#include <iostream>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>


#include "common/Tools.h"
#include "common/CommonNet.h"
#include "socket/CommonSocket.h"

#if 0
#include "socket/Socket.h"
#include "socket/SocketUdp.h"
#include "socket/SocketTcp.h"
#endif


#include "INIReader.h"

/**
 * Constructor:
 * - FD is attached accoring to GenComm Config Class
 * - Readtimeout set accoring to GenComm Config Class
 * - Readtimeout set accoring to GenComm Config Class
 * - WriteTimeout accoring to GenComm Config Class
 * - MaxnumBytesToRead set accoring to GenComm Config Class
*/

#define MAXUDP 65536

socketIO::CommonSocket::CommonSocket ( unsigned int readaheadbuffersize ) {

  this->fd=-1;

  INIReader* cfg = (INIReader*)INIReader::Instance("server.cfg");

  // By default always off
  this->ReadAhead                = false;
  this->ReadAheadBuffer          = NULL;
  this->ReadAheadBufferTotalSize = readaheadbuffersize ;
  this->ReadAheadBufferSize      = 0;
  this->ReadAheadBufferIndex     = 0;

  this->fd_attached        = cfg->GetBoolean("socket","FD_ATTACHED",true);
  this->WriteTimeout       = cfg->GetInteger("socket","WRITE_TIMEOUT",5000000);
  this->ReadTimeout       = cfg->GetInteger("socket","READ_TIMEOUT",5000000);
  this->MaxNumBytesToRead = cfg->GetInteger("socket","MAX_NUM_BYTES_TO_READ",1204*1204);
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
socketIO::CommonSocket::~CommonSocket ( ) {

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
void socketIO::CommonSocket::AttachFD() {
    this->fd_attached = true;
}

/*
 *  Deattach the FD.
 */
void socketIO::CommonSocket::DetachFD () {
    this->fd_attached = false;
}

/**
 *  Get Attache status.
 * Returnvalue is true is Comm Channel is attached.
 */
bool socketIO::CommonSocket::FD_IsAttached() {
    return this->fd_attached;
}

/**
 *  Close the descriptor usind close().
 * ATTENTION: Could be improper, if under
 */
void socketIO::CommonSocket::Close ( ) {

  if ( this->fd==-1 )
    return ;

  common::Net::Close ( this->fd );

  IsOpen=false;
  this->fd=-1;
  this->ReadAheadBufferSize      = 0;
  this->ReadAheadBufferIndex     = 0;

}

/**
  Throws sys:ComException in case of error
*/

bool socketIO::CommonSocket::PollSnd ( int usecs )  {

  if ( this->fd == -1  ) {
	  return false;
    //throw  common::ComException (  "socketIO::CommonSocket::Ressource not opened");
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

    switch ( common::Net::Select ( sfd + 1, NULL,  &wrset,  &errset, tvp ) ) {
    case -1: {
      //throw  common::ComException (  "socketIO::CommonSocket::PollSnd. Select failed" );
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
bool socketIO::CommonSocket::PollRcv ( int usecs )  {

  if ( this->fd == -1 ) {
	  return false;
    //throw  common::ComException (  "socketIO::CommonSocket::Ressource not opened");
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


    switch ( common::Net::Select ( sfd + 1, &rdset, NULL, &errset, tvp ) ) {
    case -1: {
      //throw  common::ComException (  "socketIO::CommonSocket::PollRcv. Select failed" );
      //printf("")
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
bool socketIO::CommonSocket::SetOptBlocking () {

#if 0
u_long iMode = 0;
common::Net::Ioctlsocket(this->fd, FIONBIO, &iMode);
return true;
#else
    int i;

    i =  common::Net::Fcntl ( this->fd, F_GETFL, 0L ) ;

    if ( -1 == i ) {
    	//logging better then exceptions
    	//throw  common::ComException (  "socketIO::CommonSocket::SetOptBlocking (): Could not call fcntl()");
    }

    i ^= O_NONBLOCK;

    i = common::Net::Fcntl ( this->fd, F_SETFL, i );

    if ( -1 == i ) {
    	return false;
    	//logging better then exceptions
    	//throw  common::ComException (  "socketIO::CommonSocket::SetOptBlocking  Cannot Set Option Blocking");
    }

    return true;
#endif
}

/**
 * Making Comm Channel asynchronous.
 */
bool socketIO::CommonSocket::SetOptNonBlocking ( ) {

  int i;

  i =  common::Net::Fcntl ( this->fd, F_GETFL, 0L ) ;

  if ( -1 == i ) {
	  return false;
	 //logging better then exceptions
    //throw  common::ComException (  "socketIO::CommonSocket::SetOptNonBlocking Could not call fcntl(GETFL)");
  }

  i |= O_NONBLOCK;
  i = common::Net::Fcntl ( this->fd, F_SETFL, i );

  if ( -1 == i ) {
	 //logging better then exceptions
    //throw  common::ComException (  "socketIO::CommonSocket::SetOptNonBlocking Could not call fcntl(SETFL)");
  }

  return true;
}

/**
  * Returns true, if the Comm Channel is closed
  * Evaluation of this state: never initialsed or closed or other party closed connection
  */
bool socketIO::CommonSocket::IsEOF () const{
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
int socketIO::CommonSocket::Write ( const char *buf, const int count ) {
  int ret;

  if ( this->fd == -1 || !IsOpen || FdClosed ) {
	  ret = -1;
	 //logging better then exceptions
    //throw  common::ComException (  "socketIO::CommonSocket::Ressource not opened");
  }

 ret = common::Net::Send ( this->fd, (void *) buf, count, 0 );

  if ( ret == -1 && errno == EBADF )
  	  FdClosed=true;

  return ret;
}


/**
 * Write string. Returns the length of the sent string.
 * Throws ComException, if error occured.
 */
int socketIO::CommonSocket::Write ( const std::string & buf ) {
  int ret;

  if ( this->fd == -1 || !IsOpen || FdClosed ) {
	 ret = -1;
    //throw  common::ComException (  "socketIO::CommonSocket::Ressource not opened");
  }



  ret = Write ( (char *) buf.data(), buf.length()) ;
  return ret;
}


/**
 *  R. Steven's writen() on the Comm Channel.
 * If WriteTimeout >0 the timeout is considered
 * Return value is the number of bytes successfully written
 * Throws sys:ComException in case of error.
 */
int socketIO::CommonSocket::Writen ( const char *buf, int count ) {

  if ( this->fd == -1 || !IsOpen || FdClosed ) {
	  return -1;
    //throw  common::ComException (  "socketIO::CommonSocket::Ressource not opened");
  }

  int i= 0, len = count;
  int remain=0;
  char *c = (char*) buf;
  common::int64 from =0, to = 0, now = 0;

  if ( len == 0 )
    return 0;

  if ( WriteTimeout > 0 ) {
    from = common::Tools::Time64();
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
    	 	 return -1;
       //throw common::ComException ( "Error writing to Comm Channel" );
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

     now = common::Tools::Time64();

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
int socketIO::CommonSocket::Writen ( const std::string & buf ) {

//   if ( dynamic_cast<compp::SocketUdp*>(this) !=NULL ) {
// 	compp::SocketUdp *s = dynamic_cast<compp::SocketUdp*>(this);
//   	s->Send(buf.c_str() , buf.length() );
//   	return buf.length();
//   }

  if ( this->fd == -1 || !IsOpen || FdClosed ) {
	  printf("socketIO::CommonSocket::Ressource not opened");
	  return -1;
    //throw  common::ComException (  "socketIO::CommonSocket::Ressource not opened");
  }

  return Writen ( buf.c_str(), buf.length() ) ;
}


int socketIO::CommonSocket::operator<< ( const std::string & buf ) {

	return Writen (buf );

}

/**
 * Simple Read().
 * Throws sys:ComException in case of error
 *
 */
int socketIO::CommonSocket::Read ( char *buf, int count ) {

  if ( count <= 0 )
    return count;

  if ( this->fd == -1 || !IsOpen || FdClosed ) {
	  std::cout << "socketIO::CommonSocket::Ressource not opened\n";
    //throw  common::ComException (  "socketIO::CommonSocket::Ressource not opened");
  }

  int ret;
  //   std::cout << "Read ReadAheadBufferSize:" <<ReadAheadBufferSize << " ReadAhead:" << ReadAhead <<"\n" ;
  if ( ReadAhead == false ) {

    ret = common::Net::Recv ( this->fd, (void *) buf, count,0  );
    if ( ret == 0  )
      FdClosed=true;
    return ret ;
  }


  // Read ahead enabled
  if ( this->ReadAheadBufferSize == 0 ) {    // Buffer empty
     if ( (unsigned int ) count > ReadAheadBufferTotalSize ) {  // Special Case: More ocets requested than sizeof buffer. Solution: bypassing buffer.
     ret = common::Net::Recv ( this->fd, (void *) buf, count, 0 );
     //     std::cout << "Special Case\n" ;
       if ( ret == 0  )
 	FdClosed=true;
       return ret;
     }
    // Buffer Reload
    // Buffer is empty and we request less than number of buffered octets
    this->ReadAheadBufferSize = common::Net::Recv( this->fd, (void *) this->ReadAheadBuffer, ReadAheadBufferTotalSize , 0);
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
int socketIO::CommonSocket::Read ( std::string &buf, int count ) {

  if ( this->fd == -1 || !IsOpen || FdClosed ) {
	  std::cout << "socketIO::CommonSocket::Ressource not opened\n";
  }

    buf = "";
    char c[1000] ;
    int ret;
    int i;

    for ( i = 0; i < count; ) {
	if ( ( ret = Read (c, count-i )) == -1 ) {
			std::cout <<" Read Error \n";
			//throw common::ComException ( " Read Error ");
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
bool socketIO::CommonSocket::ReadLn ( char * buf, int count ) {

  if ( dynamic_cast<compp::SocketUdp*>(this) !=NULL ) {
	  std::cout <<"socketIO::CommonSocket::ReadLn does not make sense on UDP Socket\n";
	  //throw  common::ComException (  "socketIO::CommonSocket::ReadLn does not make sense on UDP Socket");
  }

  if ( this->fd == -1 || !IsOpen || FdClosed ) {
	  std::cout <<"socketIO::CommonSocket::Ressource not opened\n";
	  //throw  common::ComException (  "socketIO::CommonSocket::Ressource not opened");
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
bool socketIO::CommonSocket::ReadLn ( std::string & s ) {

  s ="";
  if ( dynamic_cast<compp::SocketUdp*>(this) !=NULL ) {
	  	 std::cout << "socketIO::CommonSocket::ReadLN does not make sense on UDP Socket";
  	    //throw  common::ComException (  "socketIO::CommonSocket::ReadLN does not make sense on UDP Socket");
  }

  if ( this->fd == -1 || !IsOpen || FdClosed ) {
	  std::cout << "socketIO::CommonSocket::Ressource not opened\n";
    //throw  common::ComException (  "socketIO::CommonSocket::Ressource not opened");
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

int socketIO::CommonSocket::Readn ( char *buf, int count )  {

  if ( this->fd == -1 || !IsOpen || FdClosed ) {
	  std::cout << "socketIO::CommonSocket::Ressource not opened";
    //throw  common::ComException (  "socketIO::CommonSocket::Ressource not opened");
  }

  int i=0, bytesdone =0, len = count, timeleft;
  int remain;
  char *c = (char*) buf;
  common::int64 from=0, to=0, now =0 ;


  if ( ReadTimeout > 0 ) {
    from = common::Tools::Time64() ;
    to = from + ReadTimeout;
    now = common::Tools::Time64() ;
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
      	//throw common::ComException ( "Read Error ");
    	  std::cout << "Read Error \n";
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

      now = common::Tools::Time64();
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
int socketIO::CommonSocket::Readn ( std::string &buf, int count ) {

  if ( this->fd == -1 || !IsOpen || FdClosed ) {
	 std::cout >> "socketIO::CommonSocket::Ressource not opened\n";
    //throw  common::ComException (  "socketIO::CommonSocket::Ressource not opened");
  }

  int i;
  std::auto_ptr<char> c (new char[count+1]);

  //try {
    i = this->Readn ( (char*)c.get(),  count ) ;
    buf= "";
    buf.append ( c.get(), i );
  //} catch ( common::ComException e)  {
	  	//throw common::ComException( e.what());
  //}
  return i;

}

/**
 *  Set MaxNumBytesToRead. This parameter is stored ni the object
 * and and is releveant to all Read.. () methods, which
 * do not have "count" parameter.
 */
void socketIO::CommonSocket::SetMaxNumBytesToRead ( int num ) {
  MaxNumBytesToRead = num;
}

/**
  * Modifier
  **/
void socketIO::CommonSocket::SetWriteTimeout( int tmout  ) {
  WriteTimeout = tmout ;
}
/**
  * Accessor
  **/
int socketIO::CommonSocket::GetWriteTimeout( ) const {
  return WriteTimeout  ;
}
/**
  * Modifier
  **/
void socketIO::CommonSocket::SetReadTimeout( int tmout ) {
  ReadTimeout = tmout ;
}
/**
  * Accessor
  **/
int socketIO::CommonSocket::GetReadTimeout() const {
  return ReadTimeout ;
}

/**
  * Accessor
  **/
int socketIO::CommonSocket::GetFd () const {
  return fd;
}

/**
  * Modifier
  **/
void socketIO::CommonSocket::SetLineDelimiter ( char c ) {
   this->LineDelimiter = c;
}
/**
  * Modifier
  **/
void socketIO::CommonSocket::SetReadAhead ( bool yn ) {

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
