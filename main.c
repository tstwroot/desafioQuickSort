#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quicksort.h"
#include "utils.h"
#include <math.h>

#define FUNCTIONS_SIZE 2
#define SIZE 1000000
#define AMOSTRAS 1

int main(int argc, char* argv[])
{
    void (*functions[])(int*, int, int) = {
        quicksort_lib,
        Aquicksort
        // quicksort_Goto,
        // quicksort_whileGotoReasonPivot,
        // quicksortCormen,
        // quicksort_mp,
        // quicksort_recursive
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