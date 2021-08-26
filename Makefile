# Makefile

all: compile

compile: main.o read.o data.o edges.o component.o heap.o
	gcc -o  trab2 main.o read.o data.o edges.o component.o heap.o

main.o: ./src/main.c
	gcc -o main.o -c ./src/main.c 

read.o: ./src/IO/read.c
	gcc -o read.o -c ./src/IO/read.c

data.o: ./src/DataStructures/data.c
	gcc -o data.o -c ./src/DataStructures/data.c

edges.o: ./src/DataStructures/edges.c
	gcc -o edges.o -c ./src/DataStructures/edges.c
	
component.o: ./src/DataStructures/component.c
	gcc -o component.o -c ./src/DataStructures/component.c
	
heap.o: ./src/DataStructures/heap.c
	gcc -o heap.o -c ./src/DataStructures/heap.c

clean:
	rm -rf *.o *~ trab2
