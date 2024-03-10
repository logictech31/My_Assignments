#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static int size_arr;
static long *iarr;
static void quicksort(int, int);
static int partition(int, int);
static void swap(long*, long*);

int main(int argc, char **argv) {
    int i = 0;
    
    srand(time(NULL));
    if(argc > 1) {
        size_arr = atoi(argv[1]);
    } else {
    (void)printf("What is the size of array?\nSize: ");
    (void)scanf("%d", &size_arr);
    }

    iarr = (long*) malloc(size_arr * sizeof(long int));
    if(iarr == NULL) {
        exit(EXIT_FAILURE);
    }

    *iarr = 0;    
    
    while(i < size_arr) {
        *(iarr+i++) = rand();
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
        quicksort(low, pivot);
        quicksort(pivot+1, high);
    }
}
