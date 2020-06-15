#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
  int actual, total;

  /* crea los distintos threads pasando a cada uno la copia de las variables */
  #pragma omp parallel private(total, actual)
  {

    #pragma omp barrier //Barrera 1
    /* toma el id del proceso actual */
    actual = omp_get_thread_num();
    /* toma la cantidad total de procesos */
    total = omp_get_num_threads();
    
    #pragma omp barrier //Barrera 2
    printf("HOLA MUNDO: proceso %d de %d \r\n",actual,total);
    
    #pragma omp barrier //Barrera 3
    printf("CHAU MUNDO: proceso %d de %d \r\n",actual,total); //Nuevo printf agregado

  }

  return 0;
}
