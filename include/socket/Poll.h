/* ****************************************************************
   ****************************************************************
   * Com++ Professional (c) 2009 C++ World
   * http://www.cplusplusworld.com/ mailto:compp@cplusplusworld.com
   ****************************************************************
   ****************************************************************
*/

#ifndef  POLL_H
#define  POLL_H


#include "common/CommonSocket.h"
#include <map>
#include <iterator>


namespace common {

  const int StdPollTimeout = 1000000;

class Poll {

 protected:
  int NumConn;
  std::map< int, Comm*> WriteContainer;
  std::map< int, Comm*> ReadContainer;
  std::map< int, Comm*> ErrorContainer;

  fd_set rdset, wrset, errset;
  int Timeout ;
 

  public:
  virtual ~Poll () ;
  Poll ( ) ;
  void AddWriteQueue(  Comm * Channel );
  void AddReadQueue (  Comm * Channel );
  void AddErrorQueue(  Comm * Channel );
  void EmptyWriteQueue( );
  void EmptyReadQueue ( );
  void EmptyErrorQueue( );
  void EmptyAllQueues( ) ;
  void SetTimeout ( int usecs );
  int Multiplexer ( ) ;
  int Multiplexer ( int Timeout ) ;
  bool CheckAll( Comm * Channel );
  bool CheckReadQueue( Comm * Channel );
  bool CheckWriteQueue( Comm * Channel );
  bool CheckErrorQueue( Comm * Channel );

} ;
}
#endif


