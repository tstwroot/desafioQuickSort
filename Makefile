all:
	@gcc -g -c quicksort.c utils.c
	@gcc main.c quicksort.o utils.o
	@rm quicksort.o utils.o