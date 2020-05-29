CC=gcc
CFLAGS=-I.

brainfuck: main.c
	$(CC) -o brainfuck main.c

.PHONY: clean

clean:
	rm brainfuck
