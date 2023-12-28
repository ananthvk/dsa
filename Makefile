CC=gcc
CFLAGS=-O0 -ggdb3 -Wall -Wextra -pedantic -fsanitize=address,undefined -pedantic -Wno-unused-parameter -Wno-unused-variable -Werror
build: main.c slist.c slist.h
	$(CC) $(CFLAGS) main.c slist.c -o main -std=gnu11

run: build
	./main