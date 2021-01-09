CC = gcc
OBJ = main.o wordlist.o 
CFLAGS = -c -Wall
LFLAGS = -Wall

all:wordlist

wordlist:$(OBJ)
	$(CC) $(LFLAGS) $^ -o ../bin/$@

main.o:main.c
	$(CC) $(CFLAGS) $< -o $@

wordlist.o:wordlist.c wordlist.h
	$(CC) $(CFLAGS) $< -o $@

clean:
	-rm *.o
