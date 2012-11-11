## **************************************************************
# Com ++ Framework by the C++ World
# Please report defects: mailto:compp@cplusplusworld.com
# Please visit: http://www.cplusplusworld.com/socketlibrary.html
# **************************************************************

CC=g++   -D_REENTRANT -D__LINUX__
CCOPT= -fpic -O2 -Wall
CCDEBUG=-g

INCPATH=-I ../include -I ./
LDPATH=-L./
AR=ar -r

VERSION=1.7

EXTRALIBSLIB=-lpthread -lrt
CCCMD=$(CC) $(EXTRAFLAGS)  $(CCOPT) $(CCDEBUG) $(INCPATH) 

SYSOBJECTS=syscall.o syslib.o Logger.o Tools.o GenCfg.o
SYSLIB=libSysPP.a
SYSSHAREDLIB=libSysPP-$(VERSION).so
HEADERFILES=ComException.h  GenCfg.h  Logger.h  syscall.h  syslib.h  Tools.h config.h

ifeq (yesx,yesx)
	LIBLIST=$(SYSLIB)  $(SYSSHAREDLIB)
else
	LIBLIST=$(SYSLIB)
endif


all: $(SYSLIB) preinstall

$(SYSLIB): $(SYSOBJECTS)
	$(AR) $(SYSLIB) $(SYSOBJECTS)  
	$(CC) -shared -o $(SYSSHAREDLIB) $(SYSOBJECTS) 
	ln -sf $(SYSSHAREDLIB) libSysPP.so

preinstall: 
	cp ${LIBLIST} ../lib
	( cd ../lib; ln -sf $(SYSSHAREDLIB) libSysPP.so )


#################################################################
########## Generic part from here ###############################
#################################################################

%.o:%.cpp
	$(CCCMD) -c   $*.cpp

%.o:%.cc 
	$(CCCMD) -c   $*.cc

rebuild: clean all

clean:
	rm -f *.o $(LIBLIST) $(SYSOBJECTS) libSysPP.so libSysPP.so${VERSION}

#################################################################
#################### FINITO #####################################
#################################################################
