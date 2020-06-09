#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int rank;
    int value;
    int totalProcs;
    
    MPI_Init (&argc, &argv); //Inicializo MPI 
    
    MPI_Comm_size (MPI_COMM_WORLD, &totalProcs); //Obtengo el numero de procesos 
    
    MPI_Comm_rank(MPI_COMM_WORLD,&rank); //Obtengo el numero del proceso 

    if (argc == 2){
        if (rank == 0) {
            value = atoi(argv[1]);
            MPI_Send(&value, 1, MPI_INT, 1, 1, MPI_COMM_WORLD); //Envio el valor del parametro al proceso 1
            MPI_Send(&value, 1, MPI_INT, 2, 2, MPI_COMM_WORLD); //Envio el valor del parametro al proceso 2
            printf("El proceso %d calculo la potencia numero 2 de %d = %d",rank,value,pow(value,2));
        }
        else if (rank == 1) {
            MPI_Recv(&value,1,MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE); //Recibo desde el proceso 0 el valor del parametro 
            printf("El proceso %d calculo la potencia numero 3 de %d = %d",rank,value,pow(value,3));
        }
        else if (rank == 2) {
            MPI_Recv(&value,1,MPI_INT, 0, 2, MPI_COMM_WORLD, MPI_STATUS_IGNORE); //Recibo desde el proceso 0 el valor del parametro
            printf("El proceso %d calculo la potencia numero 4 de %d = %d",rank,value,pow(value,4));
        }
    }
    else if(rank == 0){
        printf("ERROR!, La cantidad de parametros enviados no es valida");
    }
    
    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Finalize(); //Finalizo MPI. Se destruye MPI_COMM_WORLD   
    return 0;
}
