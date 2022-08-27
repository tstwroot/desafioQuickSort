#ifndef __UTILS_H__
#define __UTILS_H__

struct timing;

int *create(unsigned int);
void swap(int *, int *);
void usage();
void destroy(int *);
void fillWithRandNums(int *, unsigned int, int);
void printVector(int *, unsigned int);
double getTimeExec(struct timing *, char *);
void printTime(struct timing *);
void getDimensionsOfVector(struct timing *, int, int);
void quicksort_for(int *vector, int start, int end);
int **createMatrix(int *, int, int, int);
int pivot(int, int);

#endif