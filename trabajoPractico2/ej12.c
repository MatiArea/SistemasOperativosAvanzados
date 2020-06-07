#include <mpi.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int rank;
    char message[33];
    int totalProcs;
    
    MPI_Init (&argc, &argv); //Inicializo MPI 
    
    MPI_Comm_size (MPI_COMM_WORLD, &totalProcs); //Obtengo el numero de procesos 
    
    MPI_Comm_rank(MPI_COMM_WORLD,&rank); //Obtengo el numero del proceso 

    if (rank == 0) {
        strcpy(message,"Mensaje enviado desde proceso 0");
        for (int i = 1; i <= (totalProcs-1); i++) {
            MPI_Send(&message, strlen(message), MPI_CHAR, i, 0, MPI_COMM_WORLD);
        }        
    }
    else {
        MPI_Recv(&message,33,MPI_CHAR, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("El proceso %d recibio el siguiente mensaje: %s \r\n",rank,message);
    }

    MPI_Finalize(); //Finalizo MPI. Se destruye MPI_COMM_WORLD   
    return 0;
}
