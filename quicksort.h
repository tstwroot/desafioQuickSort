#ifndef __QUICKSORT_H__
#define __QUICKSORT_H__

struct timing 
{
	clock_t start, end;
	long double final;
};

void swap(int *, int *);
void quicksort(int *, int, int);
int *create(int *, size_t);
void destroy(int *);
void fillWithRandNums(int *, size_t, int);
void usage();
void printVector(int *, size_t);
double getTimeExec(struct timing *, char *);

#endif