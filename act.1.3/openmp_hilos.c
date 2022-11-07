#include <stdio.h>
#include "omp.h"
#define NUM_THREADS 18

int main ()
{
  omp_set_num_threads(NUM_THREADS);
  double t1 = omp_get_wtime();
  #pragma omp parallel
  {
    int ID = omp_get_thread_num();
    printf("ID procesador(%d)\n", ID);
  }
  double t2 = omp_get_wtime();
  double time = t2 - t1;

  printf("tomo %lf segundos\n", time);
  return 0;
}
