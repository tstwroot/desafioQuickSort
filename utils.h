#ifndef __UTILS_H__
#define __UTILS_H__
#include <time.h>

struct timing 
{
	clock_t start, end;
	double final;
	unsigned int vector_size;
	int rand_max;
};

int *create(int size);
void swap(int *, int *);
void usage();
void destroy(int *);
void fillWithRandNums(int *, unsigned int, int);
void printVector(int *, unsigned int);
double getTimeExec(struct timing *, char *);
void printTime(struct timing *);
void getDimensionsOfVector(struct timing *, int, int);
void quicksort_for(int *, int, int);
int **createMatrix(int *, int, int);
int pivot(int, int);
int get_pivot(int *vetor, unsigned int size);
void swap(int *, int *);
void invertVector(int vector[], int size);



#endif