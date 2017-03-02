CC = gcc
CFLAGS = -I -Wall -g -lncurses
clife: main.c game.c ga.c qs.c
	$(CC) -o clife main.c game.c ga.c qs.c $(CFLAGS)
