#include $(PRJHOME)/etc/build.mk
include ../common.mk

EXTRA_CXXFLAGS	= -D_REENTRANT

TARGET	=   jrthread.a

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
