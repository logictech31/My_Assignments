#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#define MAX 2
#define NEW_MATRIX (int*) malloc(sizeof(int) * MAX * MAX)

int get_matrix_input(int *arr[MAX]);
int print_matrix(int *arr[MAX]);

void main(void) {
  int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
  int tid, i = 0, j = 0;
  int *d, *e, *f;

  printf("Enter data for 4x4 matrix A: ");
  
  for(i = 0; i < MAX; i ++) {
    for(j = 0; j < MAX; j ++) {
      scanf("%d", &A[i][j]);
    }
  }

  printf("Enter data for 4x4 matrix B: ");
  
  for(i = 0; i < MAX; i ++) {
    for(j = 0; j < MAX; j ++) {
      scanf("%d", &B[i][j]);
    }
  }
  printf("A = ");
  for(i = 0; i < MAX; i ++) {
    for(j = 0; j < MAX; j ++) {
      printf("%d\t", A[i][j]);
    }
    printf("\n");
  }
  printf("B = ");
  for(i = 0; i < MAX; i ++) {
    for(j = 0; j < MAX; j ++) {
      printf("%d\t", B[i][j]);
    }
    printf("\n");
  }
  

  d = NEW_MATRIX;
  e = NEW_MATRIX;
  f = NEW_MATRIX;

  d = (int*)A;
  e = (int*)B;
  f = (int*)C;

  #pragma omp parallel num_threads(MAX * MAX)
  {
    tid = omp_get_thread_num();
    f[tid] = e[tid] + d[tid]; 
  }

  printf("\nResult: \n");
  for(i = 0; i < MAX; i ++) {
      for(j = 0; j < MAX; j ++) {
        printf("%d ", C[i][j]);
      }
    printf("\n");
  }
}
