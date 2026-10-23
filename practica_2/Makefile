all: array

array: main.o dynamic_array.o
	g++ main.o dynamic_array.o -o array.exe

main.o: main.cpp dynamic_array.h
	g++ -c main.cpp -o main.o

dynamic_array.o: dynamic_array.cpp dynamic_array.h
	g++ -c dynamic_array.cpp -o dynamic_array.o

clean:
	rm -f *.o array.exe


