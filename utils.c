#include "utils.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct timing 
{
	clock_t start, end;
	double final;
	unsigned int vector_size;
	int rand_max;
};

void swap(int *__n1, int *__n2)
{
	int aux = *__n1;
	*__n1 = *__n2;
	*__n2 = aux;
}

void usage()
{
	puts("USAGE: quicksort <size of vector> <max rand>");
}

int *create(unsigned int size)
{
	unsigned int *vector = (unsigned int*)calloc(size, sizeof(unsigned int));
	return vector;
}

// Cria uma matriz de inteiros, com linhas randomicas iguais.
int **createMatrix(int *vector, int sizeI, int sizeJ, int randMax)
{
    int **matrix = (int**)malloc(sizeI * sizeof(int*));
    for(int i = 0; i < sizeI; i++)
    {
        matrix[i] = (int*)malloc(sizeJ * sizeof(int));
    }
    
    for(int i = 0; i < sizeI; i++)
	{
        for(int j = 0; j < sizeJ; j++)
        {
            matrix[i][j] = vector[j];
        }
	}

	return(matrix);
}

void destroy(int *vector)
{
	free(vector);
}


void printTime(struct timing *time)
{
	fprintf(stdout, "[x] Ordenated vector[%ld] positions with rand range = %d in: %lf seconds\n", time->vector_size, time->rand_max, time->final);
}

void printVector(int *vector, unsigned int size)
{
	fprintf(stdout, "Vector[");
	for (int i = 0; i < size; i++)
	{
		if (i == size - 1)
			fprintf(stdout, "%d]\n", vector[i]);
		else
			fprintf(stdout, "%d,", vector[i]);
	}
}

void fillWithRandNums(int *vector, unsigned size, int max)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		vector[i] = rand() % max;
	}
}

double getTimeExec(struct timing *time, char *point)
{
	if (strcmp(point, "start") == 0)
	{
		time->start = clock();
	}
	if (strcmp(point, "end") == 0)
	{
		time->end = clock();
		return(time->final = (double)(time->end - time->start) / CLOCKS_PER_SEC);
	}
}

void getDimensionsOfVector(struct timing *__time, int __size, int __max)
{
	__time->vector_size = __size;
	__time->rand_max = __max;
}


int pivot(int left, int right)
{
	srand(time(NULL));
    int range = right - left + 1;
    int pivot = rand() % range;
    
    return(pivot);
}
