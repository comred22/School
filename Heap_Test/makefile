a.exe: main.o Heap.o
	g++ main.o Heap.o -o a.exe
main.o: Heap.h main.cpp
	g++ -c -g main.cpp
Heap.o: Heap.h Heap.cpp
	g++ -c -g Heap.cpp