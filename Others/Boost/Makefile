# the compiler: g++ for C++ program, define as g++ for C++
CXX = g++
CC = gcc
RM = rm -f
CFLAGS = $(CXXFLAGS)
# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CXXFLAGS  = -g -Wall -Werror
#LDFLAGS = -lm
SPECIAL_FLAGS = -std=c++0x -D_GNU_SOURCE

# the build target executable:
TARGET =boost_bind \
        enable_shared_from_this

all: $(TARGET)

boost_bind: boost_bind.cxx
	$(CXX) $(CFLAGS) $< -o $@ -lm -lboost_system

enable_shared_from_this: enable_shared_from_this.cxx
	$(CXX) $(CFLAGS) $< -o $@ -lm -lboost_system

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ 

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@ 

clean:
	$(RM) $(TARGET) *.o
