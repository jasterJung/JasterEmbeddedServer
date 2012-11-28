include ../common.mk

#CCOPT=-fpic -O2 -Wall
CCOPT=-O2 -Wall

CCDEBUG=-g

INCPATH=-I ../include -I ../include/thread -I ./
LDPATH=-L./

LIBPATH=../lib/


CCCMD=$(CXX) -D__LINUX__ -D_REENTRANT $(CCDEBUG) $(EXTRAFLAGS)  $(CCOPT) $(CCDEBUG) $(INCPATH)

EXTRA_CXXFLAGS	= -D_REENTRANT



TARGET	=   libJrThread.a

OBJS	=  Task.o TaskManager.o TaskManager.o ScopeMutex.o condition.o Thread.o ThreadPool.o CommonSocketThread.o CommonNet.o


%.o:%.cpp
	@echo "compiling...." 
	$(CCCMD) -c $*.cpp


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

