// **************************************************************
// Com ++ Framework by the C++ World
// Please report defects: mailto:compp@cplusplusworld.com
// Please visit: http://www.cplusplusworld.com/socketlibrary.html
// **************************************************************
//#include "config.h"

#include "SysPlusPlus/Logger.h"
#include <syslog.h>

#include <iostream>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/param.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>
#include <cstring>

#include "SysPlusPlus/syscall.h"
#include "SysPlusPlus/syslib.h"


// ################################################################################

static syspp::Logger *instance_ ;
static enum syspp::LogLevels Level;


// ################################################################################

syspp::Logger * syspp::Logger::Instance( char *InstanceId ) {
    if (instance_ == NULL) {
        instance_ = new Logger(InstanceId);
    }
    return instance_;
}

// ################################################################################

syspp::Logger * syspp::Logger::Instance(  ) {

  if (instance_ == NULL) {
    instance_ = new Logger((char*)"Logger");
    instance_->On = true;
  }

  return instance_;
}

// ################################################################################

syspp::Logger::~Logger () {
}

// ################################################################################

void syspp::Logger::SetLevel ( enum LogLevels NewLevel ) {

  Level = NewLevel;

}

// ################################################################################

void syspp::Logger::SwitchOn (  ) {

  On=true;

}
// ################################################################################

void syspp::Logger::SwitchOff (  ) {

  On=false;

}

// ################################################################################

void syspp::Logger::Debug(const char* fmt, ...) {

  if ( Level < LOGDEBUG )  
    return;

  va_list args;
  va_start(args, fmt);
  char buf[1024];
  vsnprintf(buf, sizeof(buf), fmt, args);
  va_end(args);

  syspp::Logger *LogObj = syspp::Logger::Instance( );
  LogObj->log(LOGDEBUG, buf);
  
}

// ################################################################################

void syspp::Logger::Info(const char* fmt, ...) {

  if ( Level < LOGINFO )  
    return;

    va_list args;
    va_start(args, fmt);

    char buf[1024];
    vsnprintf(buf, sizeof(buf), fmt, args);
    va_end(args);
    syspp::Logger *LogObj = syspp::Logger::Instance( );
    LogObj->log(LOGINFO, buf);

}

// ################################################################################

void syspp::Logger::Notice(const char* fmt, ...) {

  if ( Level < LOGNOTICE )  
    return;

    va_list args;
    va_start(args, fmt);

    char buf[1024];
    vsnprintf(buf, sizeof(buf), fmt, args);
    va_end(args);
    syspp::Logger *LogObj = syspp::Logger::Instance( );
    LogObj->log(LOGNOTICE, buf);

}

// ################################################################################

void syspp::Logger::Warning(const char* fmt, ...) {

  if ( Level < LOGWARNING )  
    return;

    va_list args;
    va_start(args, fmt);

    char buf[1024];
    vsnprintf(buf, sizeof(buf), fmt, args);
    va_end(args);

    syspp::Logger *LogObj = syspp::Logger::Instance( );
    LogObj->log(LOGWARNING, buf);
}

// ################################################################################

void syspp::Logger::Error(const char* fmt, ...) {

  if ( Level < LOGERROR )  
    return;

    va_list args;
    va_start(args, fmt);

    char buf[1024];
    vsnprintf(buf, sizeof(buf), fmt, args);
    va_end(args);

    syspp::Logger *LogObj = syspp::Logger::Instance( );
    if ( errno != 0 ) {
	char *buf1;
	char buf2[1024];
	buf1 = strerror ( errno) ;

	sprintf ( buf2 , "%s. errno == %d (%s)", buf, errno, buf1 );
	LogObj->log(LOGERROR, buf2);
    } else {
	LogObj->log(LOGERROR, buf);
    }
}

// ################################################################################

void syspp::Logger::Crit(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);

    char buf[1024];
    vsnprintf(buf, sizeof(buf), fmt, args);
    va_end(args);

    syspp::Logger *LogObj = syspp::Logger::Instance( );
    if ( errno != 0 ) {
	char *buf1;
	char buf2[1024];
	buf1 = strerror ( errno) ;

	sprintf ( buf2 , "%s. errno == %d (%s)", buf, errno, buf1 );
	LogObj->log(LOGERROR, buf2);
    } else {
	LogObj->log(LOGCRIT, buf);
    }
}

// ################################################################################

syspp::Logger::Logger( char *InstanceName) {  
  InstanceId = strdup ( InstanceName );
  Fd = stdout ;
  SetLevel ( LOGWARNING );

#ifndef SPECIAL_DEBUG
  openlog(InstanceId, LOG_PID | LOG_NDELAY, LOG_USER );
#endif
}

// ################################################################################


void syspp::Logger::log(int priority, const char* str) {

  if ( On == false )
    return;
  char c [ 1000 ];

  strcpy(c, "%s %s" ); 
#ifdef SPECIAL_DEBUG
  fprintf(Fd, "%s\n",  str );
#else
  switch ( priority ) {
  case LOGCRIT:     syslog ( LOG_CRIT,    c, "CRIT", str ); break;
  case LOGERROR:    syslog ( LOG_ERR,     c, "ERR ", str ); break;
  case LOGWARNING:  syslog ( LOG_WARNING, c, "WARN", str ); break;
  case LOGNOTICE:   syslog ( LOG_NOTICE,  c, "NOTI", str ); break;
  case LOGINFO:     syslog ( LOG_INFO,    c, "INFO", str ); break;
  case LOGDEBUG:    syslog ( LOG_DEBUG,   c, "DBG ", str ); break;
  }
#endif
}

// ################################################################################

#ifdef SPECIAL_DEBUG
int main (int argc, char *argv [] ) {

  syspp::Logger *LogObj = syspp::Logger::Instance( "Test" );

  LogObj->SetLevel ( syspp::LOGDEBUG );
  LogObj->SwitchOn();
  LogObj->Debug   ( "Debug"  );
  LogObj->Info    ( "Info"   );
  LogObj->Notice  ( "Notice" );
  LogObj->Warning ( "Warning");
  LogObj->Error   ( "Error"  );
  LogObj->Crit    ( "Crit"   );

  return 0;
}
#endif
