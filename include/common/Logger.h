// **************************************************************
// Com ++ Framework by the C++ World
// Please report defects: mailto:compp@cplusplusworld.com
// Please visit: http://www.cplusplusworld.com/socketlibrary.html
// **************************************************************

#ifndef LOGGER_H
#define LOGGER_H


#include <stdio.h>

namespace syspp {

  enum LogLevels  { LOGCRIT, LOGERROR, LOGWARNING, LOGNOTICE, LOGINFO, LOGDEBUG };

class Logger
{
  public:
    static Logger* Instance( char *InstanceId );
    static Logger* Instance(  );

    virtual ~Logger();

    void SetLevel ( enum LogLevels NewLevel ) ;
    static void Debug(const char* fmt, ...);
    static void Info(const char* fmt, ...);
    static void Notice(const char* fmt, ...);
    static void Warning(const char* fmt, ...);
    static void Error(const char* fmt, ...);
    static void Crit(const char* fmt, ...);

    void SwitchOn();
    void SwitchOff();

  protected:

    char *InstanceId ;
    Logger( char *Id);
    bool On;


  private:
    void log(int priority, const char *string);
    FILE*           Fd;

};

}

#endif

