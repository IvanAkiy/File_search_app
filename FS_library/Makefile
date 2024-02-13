# Compiler
CC = g++

# Compiler flags
CFLAGS = -Wall -std=c++11

# Source files
SRCS = file_search.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Library name
LIBRARY = libFileSearchLib.a

# Build rule for object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Build rule for the library
$(LIBRARY): $(OBJS)
	ar rcs $@ $^

# Clean rule
clean:
	rm -f $(OBJS) $(LIBRARY)

