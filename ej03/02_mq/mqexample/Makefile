CC=gcc
DEPEN=-lrt -pthread
all: server client
server: server.c common.h
	$(CC) server.c -o server $(DEPEN)
client:	client.c common.h
	$(CC) client.c -o client $(DEPEN)
clean:
	rm -rf *.o