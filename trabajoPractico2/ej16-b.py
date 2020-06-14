import numpy
from mpi4py import MPI

MAXPRODUCTS = 1000000

comm = MPI.COMM_WORLD
totalProcs = comm.Get_size()
rank = comm.Get_rank()


if(MAXPRODUCTS%totalProcs)==0: 
    arrayPricesRoot = None
    arraySlave = None
    arrayPricesFinal = None
    elementsPerProc = int(MAXPRODUCTS/totalProcs)
    
    if rank == 0:
        arrayPricesRoot = numpy.empty([totalProcs, elementsPerProc])
        arrayPricesRoot.T[:,:] = range(totalProcs)

    arraySlave = numpy.empty(elementsPerProc)
    comm.Scatter(arrayPricesRoot, arraySlave, root=0)

    for i in range(elementsPerProc):
        arraySlave[i]+=arraySlave[i]*0.2

    arrayPricesFinal = numpy.empty([totalProcs,elementsPerProc])
    comm.Gather(arraySlave, arrayPricesFinal, root=0)

elif rank == 0:
    print("La cantidad de procesos seleccionada no es divisor del total de productos")

print(f"Finalizando ejecucion de Proceso = {rank}")