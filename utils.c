#include "utils.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//main estados:






//-----------

int get_pivot(int *vetor, unsigned int size)
{
	int maior = 0;
	for (int i = 0; i < size; i++)
	{
		if (vetor[i] > maior)
		{
			maior = vetor[i];
		}
	}

	int Imelhor, melhor;
	for (int dif, i = 0; i < size; i++)
	{
		dif = abs((vetor[i] - (maior / 2)));
		if (i == 0)
			melhor = dif;
		else
		{
			if (dif < melhor)
			{
				melhor = dif;
				Imelhor = i;
			}
		}
	}
	return Imelhor;
}

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
	unsigned int *vector = (unsigned int *)calloc(size, sizeof(unsigned int));
	return vector;
}

// Cria uma matriz de inteiros, com linhas randomicas iguais.
int **createMatrix(int *v, int sizeI, int sizeJ)
{
	int **matrix = (int **)malloc(sizeI * sizeof(int *));
	for (int i = 0; i < sizeI; i++)
	{
		matrix[i] = (int *)malloc(sizeJ * sizeof(int));
	}

	for (int i = 0; i < sizeI; i++)
	{
		for (int j = 0; j < sizeJ; j++)
		{
			matrix[i][j] = v[j];
		}
	}

	return (matrix);
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
		return (time->final = (double)(time->end - time->start) / CLOCKS_PER_SEC);
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
	
	int range = abs(left - right);
	
	if (range == 0) range = 1;
	
	int pivot = rand() % range;

	return pivot;
}

