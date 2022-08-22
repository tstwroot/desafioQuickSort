all:
	@gcc -g -c quicksort.c
	@gcc main.c quicksort.o
	@rm quicksort.o