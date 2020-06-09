import sys
from mpi4py import MPI

comm = MPI.COMM_WORLD
totalProcs = comm.Get_size()
rank = comm.Get_rank()

if len(sys.argv) == 2:
    if rank == 0:
        value = int(sys.argv[1])
        comm.send(value, dest=1, tag=1)
        comm.send(value, dest=2, tag=2)
        print(f"El proceso {rank} calculo la potencia numero 2 de {value} = {pow(value,2)}")
    elif rank == 1:
        value = comm.recv(source=0, tag=1)
        print(f"El proceso {rank} calculo la potencia numero 3 de {value} = {pow(value,3)}")

    elif rank == 2:
        value = comm.recv(source=0, tag=2)
        print(f"El proceso {rank} calculo la potencia numero 4 de {value} = {pow(value,4)}")

elif rank == 0:
    print("ERROR!, La cantidad de parametros enviados no es valida")

comm.Barrier()