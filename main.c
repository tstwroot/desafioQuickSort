#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quicksort.h"
#include "utils.h"
#include <math.h>

#define FUNCTIONS_SIZE 3
#define SIZE 1000
#define AMOSTRAS 100

int main(int argc, char* argv[])
{
    void (*functions[])(int*, int, int) = {
        quicksort_lib,
        quicksort_whileGotoReasonPivot,
        quicksortCormen
        // quicksort_whileGoto,
        // quicksort_mp,
        // quicksort_recursive
        // quicksort_pivot,
    };

    int *v = create(SIZE);
    fillWithRandNums(v, SIZE, 1000);
    
    int **matrix = createMatrix(v, FUNCTIONS_SIZE, SIZE);
    struct timing *time = (struct timing*)malloc(sizeof(struct timing));
    double amostras[AMOSTRAS][FUNCTIONS_SIZE], medias[FUNCTIONS_SIZE];
    
    for(int i = 0; i < FUNCTIONS_SIZE; i++)
    {
        for(int j = 0; j < AMOSTRAS; j++)
        {
            getTimeExec(time, "start");
            (*functions[i])(matrix[i], 0, SIZE-1);
            getTimeExec(time, "end");
            amostras[i][j] = time->final;
            // printVector(matrix[i], SIZE);
            memset(time, 0, sizeof(time));
        }
    }

    for(int i = 0; i < FUNCTIONS_SIZE; i++)
    {
        for(int j = 0; j < AMOSTRAS; j++)
        {
            medias[i] += amostras[i][j];
        }
        medias[i] /= AMOSTRAS;
    }

    int best = 0;
    double bestTime;
    for(int i = 0; i < FUNCTIONS_SIZE; i++)
    {   
        if(i == 0) bestTime = medias[i];
        else
        {
            if(medias[i] < bestTime)
            {
                bestTime = medias[i];
                best = i;
            }
        }
        printf("Media da função[%d]: \t%.8lf\n", i+1, medias[i]);
    }

    printf("FUNÇÃO GANHADORA[%d]: \t%.8lf\n", best+1, bestTime);
}