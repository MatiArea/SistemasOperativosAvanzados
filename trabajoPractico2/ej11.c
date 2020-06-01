#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
  int actual, total;

  /* crea los distintos threads pasando a cada uno la copia de las variables */
  #pragma omp parallel private(total, actual)
  {
    /* toma el id del proceso actual */
    actual = omp_get_thread_num();

    /* toma la cantidad total de procesos */
    total = omp_get_num_threads();

    #pragma omp barrier
    printf( "HOLA MUNDO: proceso %d de %d\n", actual, total );
    printf("El total de procesos es %d \r\n",total);

  }

  return 0;
}