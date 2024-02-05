#include <stdio.h>
#include <stdlib.h>
#define MAX 8

void swap(int *, int *);
int bubble_sort(int *);

int main() {
  int arr[MAX] = {5, 4, 1, 2, 3, 8, 6, 9};
  int i = 0;
  bubble_sort(arr);

  for(; i < MAX; i ++)
    printf("%d ", arr[i]);

  return 0;
}

void swap(int *a, int *b) {
 *a = *a ^ *b;
 *b = *a ^ *b;
 *a = *a ^ *b;

 return; 
}

int bubble_sort(int *arr) {
  if(arr == NULL) {
    printf("Reference to null.");
    return 1;
  }

  for (int i = 0; i < MAX; i ++) {
    for(int j = i+1; j < MAX; j ++) {
      if(*(arr+i) > *(arr+j)) {
        swap(arr+i, arr+j);
      }
    }
  }

  return 0;  
}