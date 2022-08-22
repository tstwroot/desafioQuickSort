#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "quicksort.h"

double getTimeExec(struct timing *time, char *point)
{
	if(strcmp(point, "start") == 0)
	{
		time->start = clock();
	}
	if(strcmp(point, "end") == 0)
	{
		time->end = clock();
		return time->final = (double)(time->end - time->start) / CLOCKS_PER_SEC;
	}
}

void printVector(int *vector, size_t size)
{
	fprintf(stdout, "Vector[");
	for(int i = 0; i < size; i++)
	{
		if(i == size-1)
			fprintf(stdout, "%d]\n", vector[i]);
		else
			fprintf(stdout, "%d,", vector[i]);
	}
}

void usage()
{
	puts("USAGE: quicksort <size of vector> <max rand>");
}

int *create(int *vector, size_t size)
{
	vector = (int*)malloc(size * sizeof(int));
	return vector;
}

void destroy(int *vector)
{
	free(vector);
}

void fillWithRandNums(int *vector, size_t size, int max)
{
	srand(time(NULL));
	for(int i = 0; i < size; i++)
	{
		vector[i] = rand() % max;
	}
}

void swap(int *__n1, int *__n2)
{
    int aux = *__n1;
    *__n1 = *__n2;
    *__n2 = aux;
}

void quicksort(int *vector, int start, int end)
{
	int i = start, j = end-1;
	int pivo = vector[(start + end) / 2];

	while(i <= j)
	{
		while(vector[i] < pivo && i < end)
		{
			i++;
		}
		while(vector[j] > pivo && j > start)
		{
			j--;
		}
		if(i <= j)
		{
            swap(vector+i, vector+j);
			i++;
			j--;
		}
	}
	if(j > start)
		quicksort(vector, start, j+1);
	if(i < end)
		quicksort(vector, i, end);
}