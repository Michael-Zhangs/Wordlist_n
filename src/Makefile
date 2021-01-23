CC = gcc
OBJ = main.o wordlist.o 
CFLAGS = -c -Wall
LFLAGS = -Wall

all:wordlist setup

setup.o:setup.c 
	$(CC) $(CFLAGS) $< -o $@

http_download.o:http/http_download.c http/http_download.h
	$(CC) $(CFLAGS) $< -o $@

setup:setup.o http_download.o
	$(CC) $(LFLAGS) $^ -o ../bin/$@

wordlist:$(OBJ)
	$(CC) $(LFLAGS) $^ -o ../bin/$@

main.o:main.c
	$(CC) $(CFLAGS) $< -o $@

wordlist.o:wordlist.c wordlist.h
	$(CC) $(CFLAGS) $< -o $@

clean:
	-rm *.o
