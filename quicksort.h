#ifndef __QUICKSORT_H__
#define __QUICKSORT_H__

void quicksort_lib(int *vector, int start, int end);

//quicksorts models
void quicksort_mp(int *vector, int start, int end);
void quicksort_while(int *vector, int start, int end);
void quicksort_whileGoto(int *vector, int start, int end);
void quicksort_whileGotop(int *vector, int start, int end);
//void quicksort_pivot(int *vector, int start, int end);
void quicksort_recursive(int *vector, int start, int end);
void quicksort_for(int *vector, int start, int end);
void quicksort_whileGotoReasonPivot(int *vector, int start, int end);

void quicksortCormen(int *A, int inicio, int fim);
int cormenPartition(int *A, int inicio, int fim);

//partition
int partition(int *vector, int start, int end);

#endif