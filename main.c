#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quicksort.h"
#include "utils.h"
#define FUNCTIONS_SIZE 5

int main(int argc, char* argv[])
{
    
    void (*functions[])(int*, int, int) = {
        quicksort_while,
        quicksort_whileGoto,
        quicksort_recursive,
        quicksort_lib,
        quicksort_pivot
        // quicksort_for
    };

    int **matrix, *v;
    v = create(10);
    fillWithRandNums(v, 10, 100);
    
    matrix = createMatrix(v, 10, FUNCTIONS_SIZE, 10);
    for(int i = 0; i < FUNCTIONS_SIZE; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}