# Makefile for MyApp

# Compiler
CC = g++
# Compiler flags
CFLAGS = -Wall -std=c++11 -I/home/ivan/Documents/Project_draft
# Source files
SRCS = main.cpp
# Object files
OBJS = $(SRCS:.cpp=.o)
# Library name
LIBRARY = libFileSearchLib.a
# Library path
LIBRARY_PATH = /home/ivan/Documents/Project_draft

# Build rule for object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Build rule for the application
MyApp: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBRARY_PATH) -lFileSearchLib

# Clean rule
clean:
	rm -f $(OBJS) MyApp
