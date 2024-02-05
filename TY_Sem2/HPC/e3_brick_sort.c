#include <stdio.h>
#include <pthread.h>
#define MAX 500

const int max_threads = (MAX + 1) / 2;

void swap(int *, int *);
int print_arr(int *);
void* compare(void *);
int odd_even(pthread_t []);
int arr[MAX], tmp = 0;

int main(int argc, int *argv[]) {
    int threads[max_threads];
    int i = 0;

    for(; i < MAX; i ++) {
        arr[i] = rand();
    }

    return 0;
}

void swap(int *a, int *b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;

    return;
}

void* compare(void *arg) {
    int index = tmp;
    tmp += 2;

    if ((index + 1 < n) && (arr[index] > arr[index + 1]))
        swap(arr+index, arr+index+1);

    return NULL;
}

int print_arr(int *arr) {
    if(arr == NULL) {
        printf("\nArray is referenced to null");
        return 1;
    }
    while(arr+1 != NULL) {
        printf("%d ", *arr++);
    }

    return 0;
}

int odd_even(pthread_t threads[]) {
    int i = 1, j = 0;

    for(; i <= MAX; i ++) {
        if(i % 2 == 1) {
            tmp = 0;
            for(j = 0; j < max_threads; j ++)
                pthread_create(&threads[j], NULL, compare, NULL);

            for(j = 0; j < max_threads; j ++)
                pthread_join(threads[j], NULL);
        } else {
            tmp = 1;
            for(j = 0; j < max_threads - 1; j ++)
                pthread_create(&threads[j], NULL, compare, NULL);

            for(j = 0; j < max_threads - 1; j ++)
                pthread_join(threads[j], NULL);
        }
    }
}
// EOF