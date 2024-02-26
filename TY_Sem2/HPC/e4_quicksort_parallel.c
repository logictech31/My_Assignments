#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

static int size_arr;
static long *iarr;
static void quicksort(int, int);
static int partition(int, int);
static void swap(long*, long*);

int main(void) {
    int i = 0;

    (void)printf("What is the size of array?");
    (void)scanf("%d", &size_arr);

    iarr = (long*) malloc(size_arr * sizeof(long int));
    if(iarr == NULL) {
        exit(EXIT_FAILURE);
    }

    *iarr = 0;    


    (void)printf("Array Input: ");
    #pragma omp parallel num_threads(100)
    {
        while(i < size_arr) {
            *(iarr+i++) = rand() % 1000;
        }
    }

    quicksort(0, size_arr-1);

    (void)printf("Array Sorted: ");
    i = 0;
    while(i < size_arr) {
        (void)printf("%ld ", *(iarr+i++));
    }

    (void)printf("\n");
    free(iarr);

    return 0;
}

void swap(long *a, long *b) {
    long temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int low, int high) {
    long pivot = iarr[low];
    int leftwall = (int)low;
    int i;
    
    for(i = low + 1; i <= high; i++) {
        if(pivot > iarr[i]) {
            swap(&iarr[i], &iarr[leftwall]);
            ++leftwall;
        }
    }
    
    swap(&iarr[leftwall], &pivot);

    return leftwall;
}

void quicksort(int low, int high) {
    if(low < high) {
        int pivot = partition(low, high);
        
        #pragma omp parallel sections
        {
            #pragma omp section
            {
                quicksort(low, pivot);
            }
            #pragma omp section
            {
                quicksort(pivot+1, high);
            }
        }
    }
}
