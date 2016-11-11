todo: main

VElement.o: VElement.h VElement.cpp
	g++ -c VElement.cpp -Wall

main: merge.o VElement.o
	g++ merge.o VElement.o -o main

limpiar:
	rm merge.o
	rm main
