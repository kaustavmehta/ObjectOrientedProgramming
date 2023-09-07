## Makefile for Admission system

CC = g++
CFLAGS = 

main.exe: main.o admission.o
	$(CC) $(CFLAGS) -o main.exe main.o admission.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

admission.o: admission.cpp
	$(CC) $(CFLAGS) -c admission.cpp