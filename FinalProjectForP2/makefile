a.exe: main.o Heap.o Car.o
	g++ -g main.o Heap.o Car.o

main.o: main.cpp Car.h
	g++ -c -g main.cpp

Heap.o: Heap.cpp Heap.h
	g++ -c -g Heap.cpp

Car.o: Car.cpp Car.h
	g++ -c -g Car.cpp