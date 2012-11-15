AR      = ar -rcv
MV      = /bin/mv -f
RM      = /bin/rm -f
#INSTALL        = /usr/bin/install -c
INSTALL = /bin/cp -i

#BEAGLE BONE 
#CROSS_COMPILE:= /usr/bin/arm-linux-gnueabi-
#LDPATH		=-L/usr/arm-linux-gnueabi/lib -L./ -L../lib
#
CROSS_COMPILE:= /usr/bin/
LDPATH		=-L./ -L../lib

CCDEBUG=-g
CXX 	=$(CROSS_COMPILE)g++ 
AR		=$(CROSS_COMPILE)ar -r 

INCPATH	=-I ../include/ -I ./
EXTRALIBSLIB	= 

