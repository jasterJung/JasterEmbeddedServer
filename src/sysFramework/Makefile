include ../../common.mk

#CCOPT=-fpic -O2 -Wall
CCOPT=-O2 -Wall

CCDEBUG=-g

INCPATH=-I ../../include -I ./ -I ../../inih_r26
LDPATH=-L ../../lib

LIBPATH=../../lib/

LIBS=-lpthread -lrt
LLIBS= -linih $(EXTRALIBSLIB)
ALLLIBS=$(LLIBS) $(LIBS)


CCCMD=$(CXX) -D__LINUX__ -D_REENTRANT $(CCDEBUG) $(EXTRAFLAGS)  $(CCOPT) $(CCDEBUG) $(INCPATH) $(LDPATH) $(ALLLIBS)

EXTRA_CXXFLAGS	= -D_REENTRANT



TARGET	=   libJrThread.a

OBJS	=  Task.o TaskManager.o TaskManager.o ScopeMutex.o condition.o Thread.o ThreadPool.o CommonSocketThread.o CommonNet.o\
 CommonSocket.o


%.o:%.cpp
	@echo "compiling...." 
	$(CCCMD) -c $*.cpp

re: clean all

all:    $(TARGET)

$(TARGET):  $(OBJS)
		-@echo ""
		-@echo "** make  $(TARGET)."
		$(AR) $@ $(OBJS)
		$(MV) $@ $(LIBPATH)$(TARGET)

clean:
		-@echo ""
		-@echo "** cleanning all object file."
		$(RM) $(TARGET) $(OBJS)
		$(RM) $(LIBPATH)$(TARGET)

