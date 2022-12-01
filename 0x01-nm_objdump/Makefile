CC = gcc
CFLAGS = -g -Wall -Werror -Wextra -pedantic -std=gnu90

SRC = $(wildcard *.c)
OBJS = $(patsubst %.c, %.o, $(SRC))
0 = $(patsubst %.c, %.o, hreadelf.c main.c)

.PHONY: hnm clean

hnm: $(0)
	$(CC) $(CFLAGS) $(0) -o hnm

hobjdump: hobjdump.c
	$(CC) $(CFLAGS) hobjdump.c -o hobjdump	
clean:
	rm -f $(OBJS) hnm
