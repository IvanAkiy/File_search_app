# Makefile for MyApp

# Compiler
CC = g++
# Compiler flags
CFLAGS = -Wall -std=c++11 -I$(LIBRARY_PATH)

# Source files
SRCS = main.cpp
# Object files
OBJS = $(SRCS:.cpp=.o)
# Library name
LIBRARY = libFileSearchLib.a

# Default Library path (can be overridden by users)
LIBRARY_PATH ?= $(CURDIR)/../FS_library

# Default Library directory (can be overridden by users)
LIBRARY_DIRECTORY ?= $(CURDIR)/../FS_library

# Build rule for object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Build rule for the application
MyApp: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBRARY_DIRECTORY) -lFileSearchLib

# Clean rule
clean:
	rm -f $(OBJS) MyApp
