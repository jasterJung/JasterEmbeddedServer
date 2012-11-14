include ../common.mk

CCOPT=-fpic -O2 -Wall
CCDEBUG=-g
 
CCCMD=$(CXX) -D__LINUX__ -D_REENTRANT $(CCDEBUG) $(EXTRAFLAGS)  $(CCOPT) $(CCDEBUG) $(INCPATH)
EXTRA_CXXFLAGS	= -D_REENTRANT

LIBS=-lpthread -lrt
LLIBS=-lJrThread $(EXTRALIBSLIB)
ALLLIBS=$(LLIBS) $(LIBS)
 
TARGET	=SudaServer  
OBJS	=SudaServer.cpp

all : $(TARGET)
#initial lable it will go to next lable. 

$(TARGET) : $(OBJS)
		$(CXX) ${INCPATH} ${LDPATH} -c $(OBJS) -o $@ ${ALLLIBS}	
	
clean:
		-@echo "** cleanning all object file."
		$(RM) $(TARGET) *.o

install: $(TARGET)
		-@echo ""
		-@echo "** installing $(TARGET) to $(LIB_DIR)"
		$(INSTALL) $(TARGET) $(LIB_DIR)
		
		
