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

// void quicksort(int *vector, int start, int end)
// {
// 	int i = start, j = end-1;
// 	int pivo = vector[(start + end) / 2];

// 	while(i <= j)
// 	{
// 		while(vector[i] < pivo && i < end) i++;
// 		while(vector[j] > pivo && j > start) j--;
// 		if(i <= j)
// 		{
//         	swap(vector+i, vector+j);
// 			i++, j--;
// 		}
// 	}
// 	if(j > start) quicksort(vector, start, j+1);
// 	if(i < end) quicksort(vector, i, end);
// }




// void quicksort(int *vector, int start, int end)
// {
// 	int i = start, j = end-1;
// 	int pivo = vector[(start + end) / 2];

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
//          swap(vector+i, vector+j);
// 			i++;
// 			j--;
// 		}
// 	}
// 	if(j > start)
// 		quicksort(vector, start, j+1);
// 	if(i < end)
// 		quicksort(vector, i, end);
// }









/*void quicksort(int *vector, int start, int end)
{
	int i = start, j = end - 1; 					// define 2 flags -- i para o inicio do vetor --
													//  j para o final do vetor

	int pivo = vector[(start + end) / 2]; 			// define o elemento do meio como o pivo

	while (i <= j) 									// o while vai executar enqunto a flag i for menor
	{			   									// ou igual que a flag j

		while (vector[i] < pivo && i < end) 		// faz a verificação do elemento posição i se ele é menor que
		{											// que o pivo
			i++;
		}

		while (vector[j] > pivo && j > start) 		// faz a verificação do elemento posição j se ele é menor que
		{									  		// que o pivo
			j--;
		}~

		if (i <= j)									// se a flag i for menor e j ele chama a função swap
		{											// que seriaa troca de elementos
			swap(vector + i, vector + j);
			i++;									//incrementa o i para poder realizar as interações apos a realizção da troca
			j--;									//incrementa o j para poder realizar as interações apos a realizção da troca
		}
		
	}
	if (j > start)									//se casoo j ainda for maior que o inicio ele faz uma chamada recursivo passando 
		quicksort(vector, start, j + 1);			//o inicio como a referencia e j+1 como o novo final;
	if (i < end)									//se o i ainda for menor que o final ele passa o inicio comk a posição i
		quicksort(vector, i, end);					//e o final como final
}
*/