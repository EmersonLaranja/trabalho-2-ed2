# Makefile

all: compile

compile: main.o read.o data.o edges.o
	gcc -o  trab2 main.o read.o data.o edges.o

main.o: ./src/main.c
	gcc -o main.o -c ./src/main.c 

read.o: ./src/IO/read.c
	gcc -o read.o -c ./src/IO/read.c

data.o: ./src/DataStructures/data.c
	gcc -o data.o -c ./src/DataStructures/data.c

edges.o: ./src/DataStructures/edges.c
	gcc -o edges.o -c ./src/DataStructures/edges.c


clean:
	rm -rf *.o *~ trab2
