todo: main

main: merge.o 
	g++ merge.o -o main

limpiar:
	rm merge.o
	rm main
