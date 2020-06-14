#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int rank;
    int value;
    int totalProcs;
    int root = 0;
    
    MPI_Init (&argc, &argv); //Inicializo MPI 
    
    MPI_Comm_size (MPI_COMM_WORLD, &totalProcs); //Obtengo el numero de procesos 
    
    MPI_Comm_rank(MPI_COMM_WORLD,&rank); //Obtengo el numero del proceso 

    if (argc == 2){
        if (rank == root) {
            value = atoi(argv[1]);
        }
        MPI_Bcast(&value, 1, MPI_INT, root, MPI_COMM_WORLD);    
        if (rank == root) {
            printf("BASE = %d \r\n",value);
        }
        else {
            printf("El proceso %d calculo la potencia numero 2 de %d = %.0f \r\n",rank,value,pow(value,rank+1));
        }
    }
    else if(rank == 0) {
        printf("ERROR!, La cantidad de parametros enviados no es valida");
    }
    
    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Finalize(); //Finalizo MPI. Se destruye MPI_COMM_WORLD   
    return 0;
}

