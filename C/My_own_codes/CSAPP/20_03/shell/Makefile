CC = gcc
CFLAGS = -g  -std=c99 -m64
clean:
	rm -f *.o sio handler main *~

main: main.c handler.c sio.c
	$(CC) $(CFLAGS) -o main main.c handler.c sio.c