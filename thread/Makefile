include ../common.mk

CCOPT=-fpic -O2 -Wall

CCDEBUG=-g

#CC=g++ -D__LINUX__ -D_REENTRANT $(CCDEBUG)

INCPATH=-I ../include/thread -I ./
LDPATH=-L./

LIBPATH=../lib/





CCCMD=$(CXX) -D__LINUX__ -D_REENTRANT $(CCDEBUG) $(EXTRAFLAGS)  $(CCOPT) $(CCDEBUG) $(INCPATH)

EXTRA_CXXFLAGS	= -D_REENTRANT



TARGET	=   libJrThread.a

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

install: $(TARGET)
		-@echo ""
		-@echo "** installing $(TARGET) to $(LIB_DIR)"
		$(INSTALL) $(TARGET) $(LIB_DIR)
