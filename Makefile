CC=gcc

all: src/gpio.c src/gpio.h
	${CC} src/gpio.c src/gpio.h -o build/main -Wall -g -std=c11

test: build/main
	./build/main

clear: build/main
	rm build/main