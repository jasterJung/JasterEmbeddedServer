#include $(PRJHOME)/etc/build.mk
include ../common.mk

CCOPT=-fpic -O2 -Wall

CCDEBUG=-g

CC=g++    -D__LINUX__ -D_REENTRANT $(CCDEBUG)

INCPATH=-I ../include/thread -I ./
LDPATH=-L./
AR=ar -r

CCCMD=$(CC) $(EXTRAFLAGS)  $(CCOPT) $(CCDEBUG) $(INCPATH)

EXTRA_CXXFLAGS	= -D_REENTRANT



TARGET	=   jrThread.a

OBJS	=  Task.o TaskManager.o TaskManager.o ScopeMutex.o condition.o Thread.o

#.SUFFIXES:  .cpp .hxx

#.cpp.o:
#		-@echo ""
#		-@echo "** make object file($@) of $<."
#		$(CXX) $(CXXFLAGS) $(EXTRA_CXXFLAGS) $(INCLUDES) -c -g -ggdb $<

#.c.o:
#		-@echo ""
#		-@echo "** make object file($@) of $<."
#		$(CXX) $(CXXFLAGS) $(EXTRA_CXXFLAGS) $(INCLUDES) -c $<

%.o:%.cpp
	@echo "compiling...." 
	$(CCCMD) -c   $*.cpp


all:    $(TARGET)

$(TARGET):  $(OBJS)
		-@echo ""
		-@echo "** make  $(TARGET)."
		$(AR) $@ $(OBJS)

clean:
		-@echo ""
		-@echo "** cleanning all object file."
		$(RM) $(TARGET) $(OBJS)

install: $(TARGET)
		-@echo ""
		-@echo "** installing $(TARGET) to $(LIB_DIR)"
		$(INSTALL) $(TARGET) $(LIB_DIR)
