CC=gcc

all: src/main.c src/gpio.c
	${CC} src/gpio.c src/main.c -o build/main -Wall -g -std=c11

test: build/main
	./build/main

clear: build/main
	rm build/main