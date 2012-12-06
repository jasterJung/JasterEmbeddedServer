// **************************************************************
// Com ++ Framework by the C++ World
// Please report defects: mailto:compp@cplusplusworld.com
// Please visit: http://www.cplusplusworld.com/socketlibrary.html
// **************************************************************

#ifndef SYSLIBH
#define SYSLIBH


#include <sys/types.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/select.h>

#include <string>
#include "Tools.h"


namespace syspp {

  class Lib {

  protected:

  public:
    static struct hostent * Gethostbyname ( char * n ) ;
    static struct hostent * Gethostbyname ( std::string n ) ;
    static uint32 Ntohl ( syspp::uint32 );
    static uint32 Htonl ( syspp::uint32 );
    static uint16 Ntohs ( syspp::uint16 );
    static uint16 Htons ( syspp::uint16 );

  };
}

#endif
