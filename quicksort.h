#ifndef __QUICKSORT_H__
#define __QUICKSORT_H__

struct timing 
{
	clock_t start, end;
	double final;
	size_t vector_size;
	int rand_max;
};

void swap(int *, int *);
void quicksort(int *, int, int);
int *create(int *, size_t);
void destroy(int *);
void fillWithRandNums(int *, size_t, int);
void usage();
void printVector(int *, size_t);
double getTimeExec(struct timing *, char *);
void dumpInFile(FILE *, struct timing*);
void getDimensionsOfVector(struct timing*, int, int);

#endif