# Simple makefile to build inih as a static library using g++
include ../common.mk
SRC = ./ini.c
#OBJ = $(SRC:.c=.o)
OBJ = ini.o INIReader.o
OUT = libinih.a
INCLUDES = -I.
CCFLAGS = -g -O2
#CC = g++

default: $(OUT)

.cpp.o:
	$(CXX) $(INCLUDES) $(CCFLAGS) $(EXTRACCFLAGS) -c $< -o $@
.c.o:
	$(CXX) $(INCLUDES) $(CCFLAGS) $(EXTRACCFLAGS) -c $< -o $@

$(OUT): $(OBJ)
	ar rcs $(OUT) $(OBJ) $(EXTRAARFLAGS)
	mv -f $(OUT) ../lib/


clean:
	rm -f $(OBJ) $(OUT)
