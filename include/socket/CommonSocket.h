#ifndef  COMMONSOCKET_H
#define  COMMONSOCKET_H

#include <iostream>
#include <cstring>

#define _CommDefaultReadAheadBufferSize (8*1024)

namespace socketIO {

class CommonSocket {

 protected:

    int               fd                         ;         // The  file descriptor
    bool              fd_attached                ;         // Should fd be closed in destructor ?
    int               WriteTimeout               ;         // Write Timeout. Used in Writen()
    int               ReadTimeout                ;         // Write Timeout. Used in Readn()
    int               MaxNumBytesToRead          ;         // Max Bytes read into std::string
    bool              IsOpen                     ;         // Used for IsEOF
    bool              FdClosed                   ;         // Used for IsEOF
    char              LineDelimiter              ;         // Used in ReadLN
    bool              ReadAhead                  ;
    char* 				 ReadAheadBuffer          	;
    unsigned int      ReadAheadBufferIndex       ;
    unsigned int      ReadAheadBufferSize        ;
    unsigned int      ReadAheadBufferTotalSize   ;
    bool              IsThrowing                 ;

 public:

    // Destructor
    virtual ~CommonSocket() ;

    // Constructors
    CommonSocket( unsigned int buffsz = _CommDefaultReadAheadBufferSize ) ;

    //Set
    void SetThrowing ( const bool yes = true );
    // Bind the file descriptor to the Object, which
    // means the file descriptor is automatically closed
    // by the deswtructor. This option should be on,
    // if exceptions are used. Any file descriptor is
    // attached by default.
    void AttachFD();
    // Detach the file descriptor, so it is not closed,
    // when the object is deleted.
    void DetachFD();
    // Returns true, if the socket is attached. False otherwise.
    bool FD_IsAttached();
    // Sets the time for the Writen() method. (in 1/1000000 sec)
    void SetWriteTimeout( int tmout  ) ;
    // Gets the time for the Writen() method. (in 1/1000000 sec)
    int GetWriteTimeout( ) const ;
    // Sets the time for the Readn() method. (in 1/1000000 sec)
    void SetReadTimeout( int tmout ) ;
    // Gets the time for the Readn() method. (in 1/1000000 sec)
    int GetReadTimeout()const;
    int GetMaxNumBytesToRead () const ;

    void SetLineDelimiter ( char c ) ;
    void SetMaxNumBytesToRead ( int num );

    void SetReadAhead ( bool yn ) ;

    virtual void Close ();

    virtual int Write ( const char *buf, const int count ) ;
    virtual int Write ( const std::string &buf  ) ;
    virtual int operator <<  ( const std::string &buf  ) ;

    virtual int Writen ( const char *buf, int count ) ;
    virtual int Writen ( const  std::string &buf ) ;

    virtual int Read ( char *buf, int count ) ;
    virtual int Read ( std::string & buf, int count ) ;

    virtual int Readn ( char *buf, int count ) ;
    virtual int Readn ( std::string &buf, int count) ;

    virtual bool ReadLn ( char * buf, int count );
    virtual bool ReadLn ( std::string &buf );

    virtual bool SetOptNonBlocking ( ) ;
    virtual bool SetOptBlocking ( ) ;

    // poll on it
    virtual bool PollSnd ( int usecs );
    virtual bool PollRcv ( int usecs );

    bool IsEOF () const;

/*
 * Returns the systems's file descriptor (fd) for the ressource.
 * The fd can be used then is all OS system calls.
 * ATTENTION: Bypassing the functionlity of the Comm++ framework
 * can lead to lost synchronisation between the OS and the application
 * data.
 * Please handle this functionality with care!
 */
    int GetFd () const;

} ;
}

#endif

