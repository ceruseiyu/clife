CC = gcc
CFLAGS = -I -Wall -g -lncurses
clife: main.c game.c ga.c
	$(CC) -o clife main.c game.c ga.c $(CFLAGS)
