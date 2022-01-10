all: bst
bst: main.o
	g++ -o bst main.o 
main.o: main.cpp
	g++ -c -g main.cpp
clean:
	rm -f *.o
