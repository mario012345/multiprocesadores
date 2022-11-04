/*
* RAM
*/
#include <stdio.h>
#include <omp.h>
#include <math.h>
#include <time.h>
#define NUM_THREADS 6
#define STEP_NUM 33333

FILE *fptr;

int main (int argc, char *argv[])
{
  clock_t start, end;
  double cpu_time;
  fptr = fopen("Euler_n_0.txt", "w");

  printf("Número de pasos: %d\n", STEP_NUM);
  fprintf(fptr, "Datos que encuentra el metodo de Euler(variable ind.\t variable dep.\t numero de thread)\n");

  double h, t[STEP_NUM], w[STEP_NUM], ab;
  double w0=0.5, a=0, b=2;
  int i;

  fprintf(fptr, "%f\t %f\n", a, *w);

  h = (b - a) / STEP_NUM;
  w[0] = w0;
  t[0] = a;
  start = clock();

  #pragma omp parallel
  {
    for(i=0; i<STEP_NUM; i++) {
      t[i] = a + (h * i);
      w[i] = w[i - 1] + h * (1 + t[i - 1] * t[i - 1] - w[i - 1]);
    }
    for(i=0; i<STEP_NUM; i++) {
      fprintf(fptr, "%f\t %f\n", t[i], w[i]);
    }
  }

  end = clock();
  fclose(fptr);
  cpu_time = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("%f segundos\n", cpu_time);
  return 0;
}
