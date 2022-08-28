#include <stdio.h>

void mergesort(int *vector, int start, int end)
{
    if(end > start)
    {
        int middle = start + ((end - start) / 2);
        mergesort(vector, start, middle);
        mergesort(vector, (middle + 1), end);
        merge(vector, start, middle, end);
    }
}

void merge(int *vector, int start, int middle, int end)
{
    size_t lSize = (middle - start + 1), rSize = (end - middle);
    int *auxL = (int*)malloc(lSize * sizeof(int));
    int *auxR = (int*)malloc(rSize * sizeof(int));

    for(int i = 0; i < lSize; i++)
        auxL[i] = vector[start + i];
    for(int i = 0; i < rSize; i++)
        auxR[i] = vector[middle + 1 + i];

    int i = 0, j = 0, k = start;
    while(i < lSize && j < rSize)
    {
        if(auxL[i] <= auxR[j])
        {
            vector[k] = auxL[i];
            i++;
        }
        else
        {
            vector[k] = auxR[j];
            j++;
        }
        k++;
    }

    while(i < lSize)
    {
        vector[k] = auxL[i];
        i++;
        k++;
    }

    while(j < rSize)
    {
        vector[k] = auxR[j];
        j++;
        k++;
    }
    free(auxL);
    free(auxR);
}

void quicksort_lib(int *vector, int start, int end)
{
	int i = start, j = end - 1;										
	int pivo = vector[(start + end) / 2];
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

void test()
{

}

int main()
{

}