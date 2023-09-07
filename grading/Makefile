## Makefile for Grading

CC = g++
CFLAGS = 

main1.exe: main.o gradingsystem.o
	$(CC) $(CFLAGS) -o main1.exe main.o gradingsystem.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

gradingsystem.o: gradingsystem.cpp
	$(CC) $(CFLAGS) -c gradingsystem.cpp