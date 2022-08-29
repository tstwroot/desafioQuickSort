#ifndef __QUICKSORT_H__
#define __QUICKSORT_H__

void quicksort_lib(int *vector, int start, int end);

//quicksorts models
void quicksort_mp(int *vector, int start, int end);
void quicksort_pivot(int *vector, int start, int end);
void quicksort_recursive(int *vector, int start, int end);
void quicksort_for(int *vector, int start, int end);
void quicksort_whileGotoReasonPivot(int *vector, int start, int end);
void quicksort_Goto(int *vector, int start, int end);

void myquick(int *vector, int start, int end);
int mypartition(int *vector, int start, int end);

void quicksortCormen(int *A, int inicio, int fim);
int cormenPartition(int *A, int inicio, int fim);

//partition
int partition(int *vector, int start, int end);

#endif