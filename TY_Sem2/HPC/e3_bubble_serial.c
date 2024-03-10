#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

void swap(int32_t *, int32_t *);
int32_t bubble_sort(int32_t *, uint32_t);

int32_t main(void) {
  int32_t *arr;
  uint32_t i = 0, N = 0;

  srand(time(NULL));
  do {
    printf("What should the size of array be?\nSize: ");
    scanf("%d", &N);
  } while(N <= 0);

  arr = (int32_t *) malloc(N * sizeof(int32_t));

  while(i < N) {
    arr[i++] = rand();
  }

  bubble_sort(arr, N);

  for(i = 0; i < N; i ++)
    printf("%d ", arr[i]);

  return 0;
}

void swap(int32_t *a, int32_t *b) {
 *a = *a ^ *b;
 *b = *a ^ *b;
 *a = *a ^ *b;

 return; 
}

int32_t bubble_sort(int32_t *arr, uint32_t N) {
  if(arr == NULL) {
    printf("Reference to null.");
    return 1;
  }

  for (int32_t i = 0; i < N; i ++) {
    for(int32_t j = i+1; j < N; j ++) {
      if(*(arr+i) > *(arr+j)) {
        swap(arr+i, arr+j);
      }
    }
  }

  return 0;  
}