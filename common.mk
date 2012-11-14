AR      = ar -rcv
MV      = /bin/mv -f
RM      = /bin/rm -f
#INSTALL        = /usr/bin/install -c
INSTALL = /bin/cp -i

#beagle bone case or not.
CROSS_COMPILE:= /usr/bin/arm-linux-gnueabi-
LDPATH		=-L/usr/arm-linux-gnueabi/lib -L./ -L../lib

CXX 	=$(CROSS_COMPILE)g++ 
AR		=$(CROSS_COMPILE)ar -r 
MV		=mv -i

INCPATH	=-I ../include/ -I ./
EXTRALIBSLIB	= 

