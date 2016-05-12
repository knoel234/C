CC = gcc
CFLAGS = -pthread -Wall -g
LDFLGS = -pthread -Wall -g
OBJS = csapp.o

all: client

csapp.o: csapp.c csapp.h
	$(CC) $(CFLAGS) -c csapp.c

client.o: client.c csapp.h
	$(CC) $(CFLAGS) -c client.c

client: csapp.o client.o
	$(CC) $(LDFLGS) csapp.o client.o -o client
clean:
	rm -f *.o csapp client