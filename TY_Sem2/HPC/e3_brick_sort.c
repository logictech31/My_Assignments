#include <stdio.h>
#include <omp.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int32_t brick_sort(int32_t *, uint32_t);
int32_t print_arr(int32_t *, uint32_t);
uint32_t swap(int32_t *, int32_t *);

uint32_t main(void) {
    uint32_t N = 0;
    uint32_t i = 0;
    int32_t *arr = NULL;
    srand(time(NULL));
    
    do {
        printf("What should the size of array be?\nSize: ");
        scanf("%d", &N);
    }while(N <= 0);

    arr = (int32_t *) malloc(N * sizeof(int32_t));

    while(i < N) {
        arr[i++] = rand();
    }
    brick_sort(arr, N);
    print_arr(arr, N);

    return 0;
}

int32_t print_arr(int32_t *arr, uint32_t N) {
    uint32_t i = 0;
    if(arr == NULL) {
        return 1;
    }

    while(i < N)
        printf("%d ", *(arr+i++));

    return 0;
}

uint32_t swap(int32_t *a, int32_t *b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

int32_t brick_sort(int32_t *arr, uint32_t N) {
    bool sorted = false;
    uint32_t i = 0;

    if(arr == NULL) {
        return 1;
    }

    while(!sorted) {
        sorted = true;
        #pragma omp for 
            for (i = 1; i < N; i ++) {
                if(arr[i] > arr[i + 1]) {
                    swap(&arr[i], &arr[i+1]);
                    sorted = false;
                }
            }

        #pragma omp for
            for (i = 0; i < N - 1; i ++) {
                if(arr[i] > arr[i + 1]) {
                    swap(&arr[i], &arr[i+1]);
                    sorted = false;
                }
            }
    }

    return 0;
}