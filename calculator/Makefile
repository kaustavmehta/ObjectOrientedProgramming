## Makefile for Admission system

CC = g++
CFLAGS = 

# Compile and link to main program
main.exe: main.o calculator.o
	$(CC) $(CFLAGS) -o main.exe main.o calculator.o

# Compile main.cpp to main.o
main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

# Compile calculator.cpp to calculator.o
calculator.o: calculator.cpp
	$(CC) $(CFLAGS) -c calculator.cpp

# Instead of manually deleting compiler output, we automate it.
clean:
	rm -f main.exe *.o

# Declare a phony target so that make always cleans up
# upon running make again.
.PHONY: clean