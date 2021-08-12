# Makefile

all: compile

compile: main.o read.o
	gcc -o  trab2 main.o read.o

main.o: ./src/main.c
	gcc -o main.o -c ./src/main.c 

read.o: ./src/IO/read.c
	gcc -o read.o -c ./src/IO/read.c



clean:
	rm -rf *.o *~ trab2
