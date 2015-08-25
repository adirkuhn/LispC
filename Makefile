CC = cc
CFLAGS = -std=c99 -Wall -g
CLIBS = -ledit -lm
CFLIBS = lib/mpc/mpc.c
FILES = prompt parsing

%: %.c
	$(CC) $(CFLAGS) $(CFLIBS) $^ $(CLIBS) -o $@.o

clean:
	rm *.o
