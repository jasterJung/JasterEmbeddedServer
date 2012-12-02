include ../common.mk

CCOPT=-Wall


EXTRA_CXXFLAGS	= -D_REENTRANT
EXTRALIBSLIB=-lstdc++
LIBS=-lpthread -lrt
LLIBS=-lJrThread -linih $(EXTRALIBSLIB)
ALLLIBS=$(LLIBS) $(LIBS)
 
TARGET	=SudaServer  
OBJS	=SudaServer.o

INCPATH += -I../inih_r26 

CCCMD=${CXX} ${EXTRAFLAGS} ${CCOPT} ${CCDEBUG} ${INCPATH}

%.o:%.cpp
	-@echo "** make"
	$(CCCMD) -c $*.cpp

re: clean all

all : $(TARGET)

#default Target
$(TARGET) : $(OBJS)
	-@echo "find Objects ..."
	$(CXX) -D__LINUX__ -D_REENTRANT $(CCDEBUG) $(CCOPT) $(INCPATH) $(LDPATH) -o $@ SudaServer.o $(ALLLIBS) 
	
clean:
		-@echo "** cleanning all object file."
		$(RM) $(TARGET) *.o

#install: $(TARGET)
#		-@echo ""
#		-@echo "** installing $(TARGET) to $(LIB_DIR)"
#		$(INSTALL) $(TARGET) $(LIB_DIR)
		
		
