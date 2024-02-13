CC = g++

CFLAGS = -Wall -std=c++11

SRCS = file_search.cpp

OBJS = $(SRCS:.cpp=.o)

LIBRARY = libFileSearchLib.a

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBRARY): $(OBJS)
	ar rcs $@ $^

clean:
	rm -f $(OBJS) $(LIBRARY)

