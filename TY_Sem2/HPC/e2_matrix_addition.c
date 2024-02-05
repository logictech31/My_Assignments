#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#define MAX 2

int get_matrix(int [MAX][MAX]);

void main(void) {
  int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
  int tid = 0, i = 0, j = 0;
  int *d, *e, *f;

  printf("Enter data for 4x4 matrix A: ");
  
  get_matrix(A);

  printf("Enter data for 4x4 matrix B: ");
  
  get_matrix(B);
  
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


int get_matrix(int arr[MAX][MAX]) {
  for(int i = 0; i < MAX; i ++)
    for(int j = 0; j < MAX; j ++)
      scanf("%d", &arr[i][j]);
}
