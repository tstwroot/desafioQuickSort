#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quicksort.h"
#include "utils.h"
#define FUNCTIONS_SIZE 5
#define SIZE 100

int main(int argc, char* argv[])
{
    
    void (*functions[])(int*, int, int) = {
        quicksort_whileGoto,
        quicksort_lib,
        quicksort_pivot,
        quicksort_while,
        quicksort_recursive, //erro -> numeros diferentes
        quicksort_for // erro -> nao ordena
    };

    int **matrix, *v, size;
    
    v = create(SIZE);
    fillWithRandNums(v, SIZE, 1000);

    matrix = createMatrix(v, FUNCTIONS_SIZE, SIZE);
    struct timing *time = (struct timing*)malloc(sizeof(struct timing));
    for(int i = 0; i < FUNCTIONS_SIZE; i++)
    {
        getTimeExec(time, "start");
        (*functions[i])(matrix[i], 0, SIZE);
        getTimeExec(time, "end");
        printf("[Função %d terminada] - Tempo: %lf\n", i+1, time->final);
    }
 
    // for(int i = 0; i < FUNCTIONS_SIZE; i++)
    // {
    //     printVector(matrix[i], SIZE);
    // }
}
