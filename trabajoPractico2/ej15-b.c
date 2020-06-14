#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXPRODUCTS 1000000

int main(int argc, char *argv[]) {
   
    int rank;
    int totalProcs;
    float arrayPricesRoot[MAXPRODUCTS];
    float arrayPricesFinal[MAXPRODUCTS];


    
    MPI_Init (&argc, &argv); //Inicializo MPI 
    
    MPI_Comm_size (MPI_COMM_WORLD, &totalProcs); //Obtengo el numero de procesos 
    
    MPI_Comm_rank(MPI_COMM_WORLD,&rank); //Obtengo el numero del proceso 

    if((MAXPRODUCTS%totalProcs) == 0) {

        int elementPerProc = MAXPRODUCTS/totalProcs;
        float *arraySlave = malloc(sizeof(float) * elementPerProc);
        if (rank == 0) {
            for (int i = 0; i < MAXPRODUCTS; i++) {
                arrayPricesRoot[i] = i+1;            //Genero un numero para cargarle informacion al array
            }
        }

        MPI_Scatter(arrayPricesRoot, elementPerProc , MPI_FLOAT, arraySlave, elementPerProc, MPI_FLOAT, 0, MPI_COMM_WORLD);
        
        MPI_Barrier(MPI_COMM_WORLD);
        
        for (int i = 0; i < elementPerProc; i++) {
            arraySlave[i]+=(arraySlave[i]*0.2);
        }
        
        MPI_Barrier(MPI_COMM_WORLD);

        MPI_Gather(arraySlave, elementPerProc ,MPI_FLOAT, arrayPricesFinal, elementPerProc, MPI_FLOAT, 0, MPI_COMM_WORLD);
        
    }
    else if (rank == 0) {
            printf("La cantidad de procesos seleccionada no es divisor del total de productos \r\n");
    }
    

    MPI_Barrier(MPI_COMM_WORLD);
 
    printf("Finalizando ejecucion Proceso = %d \r\n",rank);

    MPI_Finalize(); //Finalizo MPI. Se destruye MPI_COMM_WORLD   

    return 0;
}