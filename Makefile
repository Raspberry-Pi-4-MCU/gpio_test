CC = gcc
SOURCESRC = src
BUILDSRC = build

.PHONY: clean gpio.o main test

all: clean gpio.o main

main:
	${CC} -o ${BUILDSRC}/main ${BUILDSRC}/gpio.o ${SOURCESRC}/main.c ${SOURCESRC}/gpio.h ${SOURCESRC}/raspi4.h

gpio.o: 
	${CC} -c -o ${BUILDSRC}/gpio.o ${SOURCESRC}/gpio.c

test:
	sudo ${BUILDSRC}/main

clean:
	rm -f ${BUILDSRC}/*.o ${BUILDSRC}/main