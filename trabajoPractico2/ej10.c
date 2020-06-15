#include <stdio.h>
#include <mpi.h>

int main (int argc, char *argv[])
{
  int actual, total;

  /* inicializa MPI, crea MPI_COMM_WORLD */
  MPI_Init (&argc, &argv);
  
  MPI_Barrier(MPI_COMM_WORLD); //Barrera 1
  
  MPI_Comm_rank (MPI_COMM_WORLD, &actual); // Toma el id del proceso actual 
  MPI_Comm_size (MPI_COMM_WORLD, &total);  //Toma la cantidad de procesos total
  
  MPI_Barrier(MPI_COMM_WORLD); //Barrera 2

  MPI_Barrier(MPI_COMM_WORLD); //Barrera 3
  printf( "HOLA MUNDO: proceso %d de %d\n", actual, total );

  MPI_Barrier(MPI_COMM_WORLD); //Barrera 4s
  printf("CHAU MUNDO: proceso %d de %d \r\n",actual,total); //Nuevo printf colocado

  /* finaliza MPI */
  MPI_Finalize();

  return 0;
}

