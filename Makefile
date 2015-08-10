CC = cc
CFLAGS = -std=c99 -Wall -g
CLIBS = -ledit
FILES = prompt

%: %.c
	$(CC) $(CFLAGS) $^ $(CLIBS) -o $@.o

clean:
	rm *.o
