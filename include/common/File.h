/* ****************************************************************
   ****************************************************************
   * Com++ Professional (c) 2009 C++ World
   * http://www.cplusplusworld.com/ mailto:compp@cplusplusworld.com
   ****************************************************************
   ****************************************************************
*/

#ifndef  FILE_H
#define  FILE_H


#include <iostream>
#include <cstring>
#include <string>
#include <unistd.h>

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "socket/CommonSocket.h"

namespace common {

  /**
   * File Class.
   */
class File : public CommonSocket {

 protected:
  
     std::string FN;

 public:

    // Destructor
    ~File () ;

    // Constructor
    File ( ) ;
    File (const std::string & FileName) ;

    // Methods
    void SetName (const std::string & FileName);

    void OpenWR();
    void OpenRD();
    void OpenRW();

    void Truncate();
    void Create ();
    void Lock ();
    void UnLock ();
    void Delete ();
    void SetPerm ();


    void SetOwnerRD ();
    void SetOwnerWR ();
    void SetOwnerRW ();

    void SetGroupRD ();
    void SetGroupWR ();
    void SetGroupRW ();

    void SetOthersRD ();
    void SetOthersWR ();
    void SetOthersRW ();

    void Chmod (mode_t val);


    static bool Exist ( const std::string & FileName );
    static bool IsWriteable ( const std::string & FileName );
    static bool IsReadable ( const std::string & FileName );
    static void SetOwnerRD ( const std::string & FileName );
    static void SetOwnerWR ( const std::string & FileName );
    static void SetOwnerRW ( const std::string & FileName );
    static void SetGroupRD ( const std::string & FileName );
    static void SetGroupWR ( const std::string & FileName );
    static void SetGroupRW ( const std::string & FileName );
    static void SetOthersRD ( const std::string & FileName );
    static void SetOthersWR ( const std::string & FileName );
    static void SetOthersRW ( const std::string & FileName );
    static void Delete ( const std::string & FileName );
    static void Chmod (const std::string & FileName, mode_t val);
} ;
}

#endif
