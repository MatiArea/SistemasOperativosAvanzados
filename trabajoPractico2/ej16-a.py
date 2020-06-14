import sys
from mpi4py import MPI

comm = MPI.COMM_WORLD
totalProcs = comm.Get_size()
rank = comm.Get_rank()

if len(sys.argv) == 2:

    if rank == 0:
        value = int(sys.argv[1])
    else:
        value = 0

    value = comm.bcast(value, root=0)
    
    if rank == 0:
        print(f"BASE = {value}")
    else:
        print(f"El proceso {rank} calculo la potencia numero 4 de {value} = {pow(value,rank+1)}")

elif rank == 0:
    print("ERROR!, La cantidad de parametros enviados no es valida")

comm.Barrier()