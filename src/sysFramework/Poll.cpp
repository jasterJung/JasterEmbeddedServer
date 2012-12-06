// **************************************************************
// Com ++ Framework by the C++ World
// Please report defects: mailto:compp@cplusplusworld.com
// Please visit: http://www.cplusplusworld.com/socketlibrary.html
// **************************************************************

#include <iostream>

#include "SysPlusPlus/syscall.h"
#include <string.h>


#include "socket/Poll.h"
#include "socket/CommonSocket.h"

//#include "ComPlusPlus/SocketTcp.h"
#include <unistd.h>

// Destructor
common::Poll::~Poll () {

}
  

/**
  * Constructor
  * All Queues zeroed
  * Timeout set to 1000000 usecs (1 second)
  */
common::Poll::Poll ( ) {

  NumConn = 0;
  Timeout = StdPollTimeout;
  FD_ZERO( & rdset );
  FD_ZERO( & wrset );
  FD_ZERO( & errset );
  ErrorContainer.clear();
  ReadContainer.clear();
  WriteContainer.clear();
} 
 
/**
  * Add a communication channel to the WriteQueue
  */
void common::Poll::AddWriteQueue( common::CommonSocket * Channel ) {

  if ( Channel == NULL ) {
  	    throw syspp::ComException("CommunicationChannel is NULL.");
  }
  int FD;

  if ( ( FD = Channel->GetFd ()) == -1 ) {
    throw syspp::ComException("CommunicationChannel not initialised.");
  } 
  WriteContainer[FD] = Channel;
}

/**
  * Add a communication channel to the ReadQueue
  */
void common::Poll::AddReadQueue( CommonSocket * Channel ){

  if ( Channel == NULL ) {
  	    throw syspp::ComException("CommunicationChannel is NULL.");
  }

  int FD;

  if ( (FD = Channel->GetFd ()) == -1 ) {
  	throw syspp::ComException("CommunicationChannel not initialised.");
  }
 
  ReadContainer[FD] = Channel;
 

}

/**
  *  Add a communication channel to the ErrorQueue
  */
void common::Poll::AddErrorQueue( CommonSocket * Channel ){

  if ( Channel == NULL ) {
  	    throw syspp::ComException("CommunicationChannel is NULL.");
  }

  int FD;

  if ( (FD = Channel->GetFd ()) == -1 ) {
    throw syspp::ComException("CommunicationChannel not initialised.");
  }
  ErrorContainer[FD] = Channel;
}

/**
  * Set the default timeout for the multiplexer
  */
void common::Poll::SetTimeout ( int usecs ) {
	this->Timeout = usecs;
}

/**
  * Start the multiplexer using
  * ReadQueue, WriteQueue and ErrorQueue
  * with the default Timeout 
  */
int common::Poll::Multiplexer ( ) {
	return Multiplexer ( this->Timeout ) ;
}

/**
  * Start the multiplexer using
  * ReadQueue, WriteQueue and ErrorQueue
  * with the dexplicit Timeout 
  */
int common::Poll::Multiplexer ( int usecs ) {

  struct timeval tv, *tvp;

      if ( usecs >= 0 ) {
    memset   (&tv, 0, sizeof(tv));
    tv.tv_sec  = usecs / 1000000;
    tv.tv_usec = usecs % 1000000;
    tvp = &tv;
  } else {
    tvp = NULL;
  }
      
   int maxfd=0;
   std::map<int, Comm*>::iterator iter;
   // *********** WRITECONTAINER ******************
   for ( iter=WriteContainer.begin(); iter != WriteContainer.end(); ++iter ) {
   	  
   	  int i;
   	  i = iter->second->GetFd();
   	  FD_SET( i, &wrset);
   	  maxfd = maxfd < i ? i : maxfd;
   }

   // *********** READCONTAINER ******************
   for ( iter=ReadContainer.begin(); iter != ReadContainer.end(); ++iter ) {
   	  int i;
   	  i = iter->second->GetFd();
   	  FD_SET( i, &rdset);
   	  maxfd = maxfd < i ? i : maxfd;
   }

   // *********** READCONTAINER ******************
   for ( iter=ErrorContainer.begin(); iter != ErrorContainer.end(); ++iter ) {
   	  int i;
   	  i = iter->second->GetFd();
   	  FD_SET( i, &errset);
   	  maxfd = maxfd < i ? i : maxfd;
   }
   

    int retv;
    if (-1 == (retv = syspp::Call::Select (maxfd + 1, &rdset, &wrset, &errset, tvp))) {
      throw  syspp::ComException (  "common::Comm::PollRcv. Select failed" );
    }
    
    return retv;
}

/**
  * Checks if Channel is active in any one
  * of the Queues. 
  * Handle with care!
  */
bool common::Poll::CheckAll( CommonSocket * Channel ) {
  
if ( FD_ISSET ( Channel->GetFd(), &rdset ) ) {
	return true;	
}

if ( FD_ISSET ( Channel->GetFd(), &wrset ) ) {
	return true;	
}

if ( FD_ISSET ( Channel->GetFd(), &errset ) ) {
	return true;	
}

return false;

}

/**
 * Checks if Channel is active in the
 * ReadQueues. 
 **/
bool common::Poll::CheckReadQueue( CommonSocket * Channel ) {
  
	if ( FD_ISSET ( Channel->GetFd(), &rdset ) ) {
	 return true;	
	}

	return false;
}

/**
 * Checks if Channel is active in the
 * WriteQueues. 
 **/
bool common::Poll::CheckWriteQueue( CommonSocket * Channel ) {
if ( FD_ISSET ( Channel->GetFd(), &wrset ) ) {
	return true;	
}
return false;
}

/**
  * Checks if Channel is active in the
  * ErrorQueues. 
  **/
bool common::Poll::CheckErrorQueue( CommonSocket * Channel ) {
  

if ( FD_ISSET ( Channel->GetFd(), &errset ) ) {
	return true;	
}

return false;

}

/**
 * Clear all Channels from WriteQueue
 **/
void common::Poll::EmptyWriteQueue( ) {
	  FD_ZERO( & wrset );
	  WriteContainer.clear();
}

/**
 * Clear all Channels from ReadQueue
 **/
void common::Poll::EmptyReadQueue ( ){
	  FD_ZERO( & rdset );
	  ReadContainer.clear();
}

/**
 * Clear all Channels from ErrorQueue
 **/
void common::Poll::EmptyErrorQueue( ) {
	  FD_ZERO( & errset );
	  ErrorContainer.clear();	  
} 

/**
 * Clear all Channels from all Queues
 **/
void common::Poll::EmptyAllQueues( ) {
	  FD_ZERO( & wrset );
	  FD_ZERO( & rdset );
	  FD_ZERO( & errset );
	  ErrorContainer.clear();
	  ReadContainer.clear();
	  WriteContainer.clear();
}

