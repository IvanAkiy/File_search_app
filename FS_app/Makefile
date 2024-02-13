CC = g++

CFLAGS = -Wall -std=c++11 -I$(LIBRARY_PATH)

SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o)

LIBRARY = libFileSearchLib.a

LIBRARY_PATH ?= $(CURDIR)/../FS_library

LIBRARY_DIRECTORY ?= $(CURDIR)/../FS_library

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

MyApp: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBRARY_DIRECTORY) -lFileSearchLib

clean:
	rm -f $(OBJS) MyApp
