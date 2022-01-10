// very rigid structure 
a.exe: main.o DB.o Node.o
	g++ main.o DB.o Node.o -o a.exe
main.o: DB.h main.cpp
	g++ -c main.cpp
DB.o: DB.h Node.h DB.cpp
	g++ -c DB.cpp
Node.o: Node.h Node.cpp
	g++ -c Node.cpp
clean:
	rm *.o
	rm a.exe 
