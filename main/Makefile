include ../common.mk

CCOPT=-fpic -O2 -Wall

CCDEBUG=-g

CC=g++    -D__LINUX__ -D_REENTRANT $(CCDEBUG) 
INCPATH	=-I ../include/ -I ./
LDPATH		=-L./ -L../lib



AR=ar -r
MV=mv -i

CCCMD=$(CC) $(EXTRAFLAGS)  $(CCOPT) $(CCDEBUG) $(INCPATH)
EXTRA_CXXFLAGS	= -D_REENTRANT

#LIB
EXTRALIBSLIB=
LIBPATH=../lib/
LIBS=-lpthread -lrt
LLIBS=-lJrThread $(EXTRALIBSLIB)
ALLLIBS=$(LLIBS) $(LIBS)
 
TARGET	=SudaServer  
OBJS	=SudaServer.cpp

all : $(TARGET)
#initial lable it will go to next lable. 

$(TARGET) : $(OBJS)
		$(CXX) ${INCPATH} ${LDPATH} -c $(OBJS) -o $@ ${ALLLIBS}	

#SudaServer: SudaServer.cpp $(LIBPATH)libJrThread.a
#			$(CC) $(INCPATH) $(LDPATH) -o SudaServer SudaServer.o ${ALLLIBS}
	
clean:
		-@echo "** cleanning all object file."
		$(RM) $(TARGET) *.o

install: $(TARGET)
		-@echo ""
		-@echo "** installing $(TARGET) to $(LIB_DIR)"
		$(INSTALL) $(TARGET) $(LIB_DIR)
		
		
