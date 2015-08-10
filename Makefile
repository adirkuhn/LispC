CC = cc
CFLAGS = -std=c99 -Wall -g
FILES = prompt

%: %.c
	$(CC) $(CFLAGS) $^ -o $@.o

clean:
	rm *.o
