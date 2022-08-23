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
    int size = atoi(argv[1]), max_rand = atoi(argv[2]);

    vector = create(vector, size);
    fillWithRandNums(vector, size, max_rand);
    getDimensionsOfVector(time, size, max_rand);
    getTimeExec(time, "start");
    quicksort(vector, 0, size);
    getTimeExec(time, "end");
    FILE *file;
    dumpInFile(file, time);
    free(time);
}
