include ../common.mk

CCOPT=-Wall


EXTRA_CXXFLAGS	= -D_REENTRANT
EXTRALIBSLIB=-lstdc++
LIBS=-lpthread -lrt
LLIBS=-lJrThread $(EXTRALIBSLIB)
ALLLIBS=$(LLIBS) $(LIBS)
 
TARGET	=SudaServer  
OBJS	=SudaServer.o

CCCMD=${CXX} ${EXTRAFLAGS} ${CCOPT} ${CCDEBUG} ${INCPATH}

#.cpp.o:
#		-@echo ""
#		-@echo "** make object file($@) of $<."
#		$(CXX) $(CXXFLAGS) $(EXTRA_CXXFLAGS) $(INCLUDES) $(XMLCFGFLAGS) -c -g -ggdb $<

#all:    $(TARGET)
#
#$(TARGET):  $(OBJS)
#		#$(CXX) -D_REENTRANT -D_GNU_SOURCE -D_LINUX_SYSTEM -Wall -o $(TARGET) $(OBJS) $(LIBFLAGS) $(LIBRARY) $(BOOST_THREAD) $(XMLLIBFLAGS) $(LDFLAGS)
#	$(CXX) -D_REENTRANT -D_GNU_SOURCE -D_LINUX_SYSTEM -Wall -o $(TARGET) $(OBJS) $(LIBFLAGS) $(LIBRARY) -L. $(LIB_PATH) $(BOOST_THREAD) $(XMLLIBFLAGS) $(LDFLAGS)

#	-@echo "** make object file($@) of $<."

#default Target
$(TARGET) : $(OBJS)
	-@echo "find Objects ..."
	$(CXX) -D__LINUX__ -D_REENTRANT $(CCDEBUG) $(CCOPT) $(INCPATH) $(LDPATH) -o $@ SudaServer.o $(ALLLIBS) 
%.o:%.cpp
	-@echo "** make"
	$(CCCMD) -c $*.cpp
	
#	$(CXX) -c $@ $<
#	$(CXX) -D_REENTRANT $(CCDEBUG) $(CCOPT) $(INCPATH) $(LDPATH) -c $(OBJS) $(ALLLIBS)
	
#$(TARGET) : $(OBJS)
#	$(CXX) -D_REENTRANT $(CCDEBUG) $(EXTRAFLAGS) $(CCOPT) $(INCPATH) $(LDPATH) -c $(OBJS) $(ALLLIBS)

#all : $(TARGET)
#initial lable it will go to next lable.

#$(TARGET) :  $(OBJS)
#	$(CXX) -D_REENTRANT $(CCDEBUG) $(EXTRAFLAGS) $(CCOPT) $(CCDEBUG) $(INCPATH) $(LDPATH) -c $(OBJS) -o $@ $(ALLLIBS)

#$(TARGET) : $(OBJS)
#		$(CXX) -D__LINUX__ -D_REENTRANT $(CCDEBUG) $(EXTRAFLAGS) $(CCOPT) $(CCDEBUG) ${INCPATH} ${LDPATH} -c $(OBJS) -o $@ ${ALLLIBS}	
	
clean:
		-@echo "** cleanning all object file."
		$(RM) $(TARGET) *.o

#install: $(TARGET)
#		-@echo ""
#		-@echo "** installing $(TARGET) to $(LIB_DIR)"
#		$(INSTALL) $(TARGET) $(LIB_DIR)
		
		
