// **************************************************************
// Com ++ Framework by the C++ World
// Please report defects: mailto:compp@cplusplusworld.com
// Please visit: http://www.cplusplusworld.com/socketlibrary.html
// **************************************************************

//#include "config.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <netinet/tcp.h>

#include <arpa/inet.h>
#include <netdb.h>
#include <sys/select.h>
#include <sys/time.h>
#include <iostream>

#include "common/syslib.h"


// *******************************************************************************


struct hostent * common::Lib::Gethostbyname ( std::string n ) {
  return gethostbyname ( n.c_str() ) ;
}

// *******************************************************************************

struct hostent * common::Lib::Gethostbyname ( char * n ) {

  return gethostbyname ( n ) ;

}

// *******************************************************************************
common::uint32 common::Lib::Ntohl ( common::uint32 v ) {

  return (common::uint32) ntohl ( (uint32_t) v );
  
}
// *******************************************************************************
common::uint32 common::Lib::Htonl ( common::uint32 v ) {
  
  return (common::uint32) htonl ( (uint32_t) v);

}
// *******************************************************************************
common::uint16 common::Lib::Ntohs ( common::uint16 v  ) {

  return (common::uint16) ntohs ( (uint16_t)v ) ;
  
}
// *******************************************************************************
common::uint16 common::Lib::Htons ( common::uint16 v ) {

  return (common::uint16) htons ( (uint16_t) v );

}


// *******************************************************************************

#ifdef SPECIAL_DEBUG

int main (int argc, char *argv[]) {

  common::uint32 t, t1, t2;

  common::uint16 tt, tt1, tt2;

  t= 67;

  t1 = common::Lib::Htonl( t );
  t2 = common::Lib::Ntohl( t1 );
  std::cout << t << " " << t1 << " " << t2 << "\n";
  
  tt = 89;

  tt1 = common::Lib::Htonl( tt );
  tt2 = common::Lib::Ntohl( tt1 );
  std::cout << tt << " " << tt1 << " " << tt << "\n";


}

// *******************************************************************************





#endif
