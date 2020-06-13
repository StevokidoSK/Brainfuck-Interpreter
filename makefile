CC=gcc
CFLAGS=-I.

src = $(wildcard *.c)
obj = $(src:.c=.o)

out = brainfuck

%.o: %.c %.h
	$(CC) -o $@ $<

$(out): $(obj)
	$(CC) -o $@ $^

.PHONY: clean

clean:
	rm $(out) $(obj)
