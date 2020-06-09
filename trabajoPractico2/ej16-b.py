import sys
import numpy
from mpi4py import MPI

MAXPRODUCTS = 1000000

comm = MPI.COMM_WORLD
totalProcs = comm.Get_size()
rank = comm.Get_rank()

if rank == 0:
    arrayPrices = numpy.arange(MAXPRODUCTS, dtype='i')
    for i in range(MAXPRODUCTS):
        arrayPrices[i]=pow(i+1,2)
    
    for i in range(totalProcs):
        comm.send(arrayPrices, dest=i, tag=i)
     
else:
    arrayPrices = numpy.empty(MAXPRODUCTS, dtype='i')
    comm.Recv([arrayPrices, MPI.INT], source=0, tag=rank)
    for i in range(rank,MAXPRODUCTS,totalProcs):
        arrayPrices[i] += round(arrayPrices[i]*0.2)

comm.Barrier()