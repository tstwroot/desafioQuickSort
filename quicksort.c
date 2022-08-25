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

void getDimensionsOfVector(struct timing *__time, int __size, int __max)
{
	__time->vector_size = __size;
    __time->rand_max = __max;
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

void dumpInFile(FILE *__file, struct timing *time)
{
	__file = fopen("time.dump", "a");
	fprintf(__file, "[x] Ordenated vector[%ld] positions with rand range = %d in: %lf seconds\n", time->vector_size, time->rand_max, time->final);
	fclose(__file);
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

//quick auxliar pivos trocados depois de cada alteração -> mais rapido e 
// void quicksort(int *vector, int start, int end)
// {
// 	int i = start, j = end-1;
// 	int pivo = vector[(start + i) / 2];

// 	while(i <= j)
// 	{
// 		while(vector[i] < pivo && i < end)
// 		{
// 			i++;
// 		}
// 		while(vector[j] > pivo && j > start)
// 		{
// 			j--;
// 		}
// 		if(i <= j)
// 		{
//             swap(vector+i, vector+j);
// 			i++;
// 			j--;
// 		}
// 	}
// 	if(j > start)
// 		quicksort(vector, start, j+1);
// 	if(i < end)
// 		quicksort(vector, i, end);
// }

//terceira versao (mais lento)
// void quicksort(int *vector, int start, int end)
// {
// 	int i = start, j = end-1;
// 	int pivo = vector[(start + j) / 2];

// 	while(i <= j)
// 	{
// 		while(vector[i] < pivo && i < end)
// 		{
// 			i++;
// 		}
// 		while(vector[j] > pivo && j > start)
// 		{
// 			j--;
// 		}
// 		if(i <= j)
// 		{
//             swap(vector+i, vector+j);
// 			i++;
// 			j--;
// 		}
// 	}
// 	if(j > start)
// 		quicksort(vector, start, j+1);
// 	if(i < end)
// 		quicksort(vector, i, end);
// }

// //versão 4 mais rapido ordenado
// void quicksort(int *vector, int start, int end)
// {
// 	int i = start, j = end-1;
// 	int pivo = vector[(i + j) / 2];

// 	while(i <= j)
// 	{
// 		while(vector[i] < pivo && i < end)
// 		{
// 			i++;
// 		}
// 		while(vector[j] > pivo && j > start)
// 		{
// 			j--;
// 		}
// 		if(i <= j)
// 		{
//             swap(vector+i, vector+j);
// 			i++;
// 			j--;
// 		}
// 	}
// 	if(j > start)
// 		quicksort(vector, start, j+1);
// 	if(i < end)
// 		quicksort(vector, i, end);
// }


///nao tao efciente
// void quicksort(int *vector, int start, int end)
// {
// 	int i = start, j = end-1;
// 	int pivo = vector[(end - i) / 2];

// 	while(i <= j)
// 	{
// 		while(vector[i] < pivo && i < end)
// 		{
// 			i++;
// 		}
// 		while(vector[j] > pivo && j > start)
// 		{
// 			j--;
// 		}
// 		if(i <= j)
// 		{
//             swap(vector+i, vector+j);
// 			i++;
// 			j--;
// 		}
// 	}
// 	if(j > start)
// 		quicksort(vector, start, j+1);
// 	if(i < end)
// 		quicksort(vector, i, end);
// }


// void particion(int *vector, int start, int end){
// 	int x = vector[end];
// 	int i = start - 1
// }

// void quicksort(int *vector, int start, int end)
// {
// 	int i = start, j = end-1;
// 	int pivo = vector[(i)];

// 	while(i <= j)
// 	{
// 		while(vector[i] < pivo && i < end)
// 		{
// 			i++;
// 		}
// 		while(vector[j] > pivo && j > start)
// 		{
// 			j--;
// 		}
// 		if(i <= j)
// 		{
//             swap(vector+i, vector+j);
// 			i++;
// 			j--;
// 		}
// 	}
// 	if(j > start)
// 		quicksort(vector, start, j+1);
// 	if(i < end)
// 		quicksort(vector, i, end);
// }



//2pivor

// void quicksort(int *vector, int start, int end)
// {
// 	int i = start, j = end-1;
// 	int pivo = vector[() / 2];

// 	while(i <= j)
// 	{
// 		while(vector[i] < pivo && i < end)
// 		{
// 			i++;
// 		}
// 		while(vector[j] > pivo && j > start)
// 		{
// 			j--;
// 		}
// 		if(i <= j)
// 		{
//             swap(vector+i, vector+j);
// 			i++;
// 			j--;
// 		}
// 	}
// 	if(j > start)
// 		quicksort(vector, start, j+1);
// 	if(i < end)
// 		quicksort(vector, i, end);
// }

