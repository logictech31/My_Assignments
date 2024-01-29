#include <stdio.h>
#include <omp.h>

int main(void) {
  #pragma omp parallel // you can add limiters by putting num_threads(n)
  {
    printf("Hello, World! from thread = %d\n", omp_get_thread_num());
  }
}
