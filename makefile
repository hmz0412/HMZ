all: sort.c quick.o  merge.o heap.o
	gcc sort.c quick.o  merge.o heap.o  -o main

quick.o: quicksort.c quicksort.h
	gcc -c quicksort.c -o quick.o
merge.o: merge.c merge.h
	gcc -c merge.c -o merge.o
heap.o: heap.c heap.h
	gcc -c heap.c -o heap.o

clean: 
	rm -f quick.o  merge.o heap.o  main
