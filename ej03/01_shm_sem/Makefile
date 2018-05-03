all: a b

a: prog_a.c
	gcc prog_a.c -o a -lrt -pthread

b: prog_b.c
	gcc prog_b.c -o b -lrt -pthread
shared:
	rm -rf /dev/shm/*
clean:
	rm a b *.o
