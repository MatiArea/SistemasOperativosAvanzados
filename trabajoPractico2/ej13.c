#include <mpi.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    
    int rank;
    int n = 1000;
    int totalProcs;
    
    MPI_Init (&argc, &argv); //Inicializo MPI 
    MPI_Comm_size (MPI_COMM_WORLD, &totalProcs); //Obtengo el numero de procesos 
    MPI_Comm_rank(MPI_COMM_WORLD,&rank); //Obtengo el numero del proceso 

    double h = 1.0 / (double) n;
	double sum = 0.0;

	for (int i = 1; i <= n; i+=totalProcs) {
		
        double x = h * ((double)i - 0.5);
		sum += (4.0 / (1.0 + x*x));
	
    }
    
    double partialPi = sum * h;

    double pi;
    MPI_Reduce(&partialPi, &pi, 1, MPI_DOUBLE, MPI_SUM, 0,MPI_COMM_WORLD);

    MPI_Barrier(MPI_COMM_WORLD);
    
    if (rank == 0) {
        printf("El valor aproximado de PI es: %.16f \r\n", pi);
        printf("Total de procesos = %d \r\n",totalProcs);
    }

    MPI_Finalize(); //Finalizo MPI. Se destruye MPI_COMM_WORLD   
    return 0;
}