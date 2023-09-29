## Makefile for LinkedList system

CC = g++
CFLAGS = 

# Compile and link to main program
main.exe: main.o linkedList.o
	$(CC) $(CFLAGS) -o main.exe main.o linkedList.o

# Compile main.cpp to main.o
main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

# Compile linkedList.cpp to linkedList.o
linkedList.o: linkedList.cpp
	$(CC) $(CFLAGS) -c linkedList.cpp

# Instead of manually deleting compiler output, we automate it.
clean:
	rm -f main.exe *.o

# Declare a phony target so that make cleans up without a target.
.PHONY: clean