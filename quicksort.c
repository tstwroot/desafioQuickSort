#include "quicksort.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int cormenPartition(int *A, int inicio, int fim)
{
    int pivo = A[fim];
    int i = inicio - 1;
    int j;
    
    for (j = inicio; j <= fim - 1; j++)
	{
        if (A[j] <= pivo) 
		{
            i = i + 1;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i + 1], &A[fim]);
    return i + 1;
}

void quicksortCormen(int *A, int inicio, int fim) 
{
    if (inicio < fim) 
	{
        int q = cormenPartition(A, inicio, fim);
        quicksortCormen(A, inicio, q - 1);
        quicksortCormen(A, q + 1, fim);
    }
}

void quicksort_mp(int *vector, int start, int end)
{
	int i = start, j = end - 1;
	int pivo = vector[get_pivot(vector, (start + end))];
	while (i <= j)
	{
		while (vector[i] < pivo && i < end)
		{
			i++;
		}
		while (vector[j] > pivo && j > start)
		{
			j--;
		}
		if (i <= j)
		{
			swap(vector + i, vector + j);
			i++;
			j--;
		}
	}
	if (j > start)
		quicksort_lib(vector, start, j + 1);
	if (i < end)
		quicksort_lib(vector, i, end);
}

void quicksort_recursive(int *vector, int start, int end)
{
	if (start < end)
	{
		int pivot = partition(vector, start, end);
		quicksort_recursive(vector, start, pivot - 1);
		quicksort_recursive(vector, pivot + 1, end);
	}
}

int partition(int *vector, int start, int end)
{
	int pivot = vector[end];
	int i = start - 1;
	for (int j = start; j < end; j++)
	{
		if (vector[j] <= pivot)
		{
			i++;
			swap(&vector[i], &vector[j]);
		}
	}
	swap(&vector[i + 1], &vector[end]);
	return (i + 1);
}

void quicksort_lib(int *vector, int start, int end)
{
	int i = start, j = end - 1;				// define 2 flags -- i para o inicio do vetor --
											//  j para o final do vetor
	int pivo = vector[(start + end) / 2];	// define o elemento do meio como o pivo
	while (i <= j)							// o while vai executar enqunto a flag i for menor
	{										// ou igual que a flag j
		while (vector[i] < pivo && i < end) // faz a verificação do elemento posição i se ele é menor que
		{									// que o pivo
			i++;
		}
		while (vector[j] > pivo && j > start) // faz a verificação do elemento posição j se ele é menor que
		{									  // que o pivo
			j--;
		}
		if (i <= j) 							// se a flag i for menor e j ele chama a função swap
		{										// que seriaa troca de elementos
			swap(vector + i, vector + j);
			i++; 								// incrementa o i para poder realizar as interações apos a realizção da troca
			j--; 								// incrementa o j para poder realizar as interações apos a realizção da troca
		}
	}
	if (j > start)							 	// se casoo j ainda for maior que o inicio ele faz uma chamada recursivo passando
		quicksort_lib(vector, start, j + 1); 	// o inicio como a referencia e j+1 como o novo final;
	if (i < end)							 	// se o i ainda for menor que o final ele passa o inicio comk a posição i
		quicksort_lib(vector, i, end);		 	// e o final como final
}

void quicksort_whileGotoReasonPivot(int *vector, int start, int end)
{
	int i = start, j = end - 1;
	unsigned int pivo = vector[abs(((end *start)  / (end + start) ) - (j - i))];
i1:
	while (vector[i] < pivo && i < end)
		i++;
	while (vector[j] > pivo && j > start)
		j--;
	if (i <= j)
	{
		swap(vector + i, vector + j);
		i++, j--;
	}
	if (i <= j)
		goto i1;
	if (j > start)
		quicksort_whileGotoReasonPivot(vector, start, j);
	if (i < end)
		quicksort_whileGotoReasonPivot(vector, i, end);
}

void quicksort_Goto(int *vector, int start, int end)
{
	int i = start, j = end - 1;
	int pivo = vector[(start + end) / 2];
i1:
	w1:
		i++;
		if(vector[i] < pivo && i < end) goto w1;
	w2:
		j--;
		if(vector[j] > pivo && j > start) goto w2;
	if (i <= j)
	{
		swap(vector + i, vector + j);
		i++, j--;
	}
	if (i <= j)
		goto i1;
	if (j > start)
		quicksort_Goto(vector, start, j + 1);
	if (i < end)
		quicksort_Goto(vector, i, end);
}

void quicksort_for(int *vector, int start, int end)
{
	int i = start, j = end - 1;
	int pivo = vector[(start + end) / 2];

	while (i <= j)
	{
		for (; vector[i] < pivo && i < end; i++)
			for (; vector[j] > pivo && j > start; j--)
				if (i <= j)
				{
					swap(vector + i, vector + j);
					i++, j--;
				}
	}
	if (j > start)
		quicksort_for(vector, start, j + 1);
	if (i < end)
		quicksort_for(vector, i, end);
}

 void quicksort_pivot(int *vector, int start, int end)
 {
	int i = start, j = end - 1;
	// int pivo = vector[pivot(start, end)];
	int pivo = vector[rand() % (end - start)];
	while (i <= j)
	{
		while (vector[i] < pivo && i < end)
		{
			i++;
		}
		while (vector[j] > pivo && j > start)
		{
			j--;
		}
		if (i <= j)
		{
			swap(vector + i, vector + j);
			i++;
			j--;
		}
	}
	if (j > start)
		quicksort_pivot(vector, start, j + 1);
	if (i < end)
		quicksort_pivot(vector, i, end);
 }
