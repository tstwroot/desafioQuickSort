#include <stdio.h>
#include <stdlib.h>
#include "quicksort.h"

int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        fprintf(stdout, "Invalid arguments!\n");
        usage();
        exit(EXIT_FAILURE);
    }

    int *vector;
    struct timing *time = (struct timing*)malloc(sizeof(struct timing));
    vector = create(vector, atoi(argv[1]));
    fillWithRandNums(vector, atoi(argv[1]), atoi(argv[2]));

    getTimeExec(time, "start");

    quicksort(vector, 0, atoi(argv[1]));
    getTimeExec(time, "end");
    free(time);
    // printVector(vector, atoi(argv[1]));
    printf("%lf segundos\n", time->final);
}