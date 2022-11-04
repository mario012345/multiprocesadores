#include <stdio.h>
#include "omp.h"
#define NUM_THREADS 18

int main (int argc, char *argv[])
{
  omp_set_num_threads(NUM_THREADS);
  #pragma omp parallel
  {
    int ID = omp_get_thread_num();
    printf("ID procesador(%d)\n", ID);
  }
  return 0;
}
