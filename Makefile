# Makefile

all: compile

compile: main.o read.o data.o component.o heap.o write.o path.o statistics.o algorithms.o list.o    
	gcc -o  trab2 main.o read.o data.o component.o heap.o write.o path.o  statistics.o algorithms.o list.o

main.o: ./src/main.c
	gcc -o main.o -c ./src/main.c 

read.o: ./src/IO/read.c
	gcc -o read.o -c ./src/IO/read.c

data.o: ./src/DataStructures/data.c
	gcc -o data.o -c ./src/DataStructures/data.c
	
component.o: ./src/DataStructures/component.c
	gcc -o component.o -c ./src/DataStructures/component.c
	
heap.o: ./src/DataStructures/heap.c
	gcc -o heap.o -c ./src/DataStructures/heap.c

write.o: ./src/IO/write.c
	gcc -o write.o -c ./src/IO/write.c
	
path.o: ./src/DataStructures/path.c
	gcc -o path.o -c ./src/DataStructures/path.c

statistics.o: ./src/DataStructures/statistics.c
	gcc -o statistics.o -c ./src/DataStructures/statistics.c

list.o: ./src/DataStructures/list.c
	gcc -o list.o -c ./src/DataStructures/list.c

algorithms.o: ./src/Algorithms/algorithms.c
	gcc -o algorithms.o -c ./src/Algorithms/algorithms.c

clean:
	rm -rf *.o *~ trab2
