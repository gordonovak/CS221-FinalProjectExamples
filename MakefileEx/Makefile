CXX = g++
CXXFLAGS = -Wall -std=c++11

TARGET = main
SRCS = main.cpp Chair.cpp
OBJS = $(SRCS:. cpp=.o)

$(TARGET):	$(OBJS)	
	$(CXX)	$(CXXFLAGS)	$(OBJS)	-o	$(TARGET)

%.o:	%.cpp
	$(CXX)	$(CXXFLAGS)	-c	$<	-o	$@

clean:
	rm	-f	$(OBJS)	$(TARGET)