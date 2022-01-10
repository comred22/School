a.exe: main.o
	g++ main.o -o a.exe
main.o: Node.h List.h main.cpp
	g++ -c -g main.cpp
clean:
	rm *.o a.exe