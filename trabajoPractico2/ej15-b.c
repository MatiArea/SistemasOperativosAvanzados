#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXPRODUCTS 1000000

int main(int argc, char *argv[]) {
   
    int rank;
    int totalProcs;
    int arrayPrices[MAXPRODUCTS];

    
    MPI_Init (&argc, &argv); //Inicializo MPI 
    
    MPI_Comm_size (MPI_COMM_WORLD, &totalProcs); //Obtengo el numero de procesos 
    
    MPI_Comm_rank(MPI_COMM_WORLD,&rank); //Obtengo el numero del proceso 

    if (rank == 0) {
        for (int i = 0; i < MAXPRODUCTS; i++) {
            arrayPrices[i] = pow(i+1,2);            //Genero un numero para cargarle informacion al array
        }
    }

    if (rank == 0) {
        for (int i = 1; i <= totalProcs; i++) {
            MPI_Send(arrayPrices,MAXPRODUCTS , MPI_INT, i, 0, MPI_COMM_WORLD);
        }
    } 
    else {
        MPI_Recv(arrayPrices,MAXPRODUCTS,MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE); 
        for (int i = rank; i < MAXPRODUCTS; i+= totalProcs); {
            arrayPrices[i] += round(arrayPrices[i]*0.2);   //Incremento un 20% el valor del array
        }
        
    }
    
    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Finalize(); //Finalizo MPI. Se destruye MPI_COMM_WORLD   
    return 0;
}
