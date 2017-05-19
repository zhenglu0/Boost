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
SPECIAL_FLAGS = -std=c++11

# the build target executable:
TARGET =boost_bind \
        enable_shared_from_this \
        boost_shared_ptr \
        boost_lexical_cast \
        boost_log

all: $(TARGET)

boost_bind: boost_bind.cxx
	$(CXX) $(CFLAGS) $< -o $@ -lm -lboost_system

enable_shared_from_this: enable_shared_from_this.cxx
	$(CXX) $(CFLAGS) $< -o $@ -lm -lboost_system

boost_shared_ptr: boost_shared_ptr.cxx
	$(CXX) $(CFLAGS) $(SPECIAL_FLAGS) $< -o $@ -lm -lboost_system

boost_lexical_cast: boost_lexical_cast.cxx
	$(CXX) $(CFLAGS) $< -o $@ -lm -lboost_system

boost_log: boost_log.cxx
	$(CXX) $(CFLAGS) $< -o $@ -lm -DBOOST_LOG_DYN_LINK -lboost_log -lboost_thread -lpthread -lboost_system -lboost_log_setup
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ 

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@ 

clean:
	$(RM) $(TARGET) *.o sample.log
