#O2 for optimization, g for debugging
CFLAGS=-Wall -O2 -g --std=c++11 #-I. $(shell root-config --cflags)
LFLAGS= #$(shell root-config --libs)
CC=g++
LD=g++

#all source files
SRCS=$(wildcard *.cpp)

OBJS = $(filter-out main.o unittest.o, $(SRCS:.cpp=.o))

.PHONY: clean all

all: path unittest

clean:
	@rm -f *~ *.o *# *.d

path: $(OBJS) main.o
	$(LD) $(LFLAGS) -o path $^

unittest:  $(OBJS) unittest.o
	$(LD) $(LFLAGS) -o unittest $^


#rules
%.o : %.cpp
	$(CC) $(CFLAGS) -MMD -c -o $@ $<
	@sed -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' \
             -e '/^$$/ d' -e 's/$$/ :/' < $*.d >> $*.d

-include $(SRCS:%.cpp=%.d)

