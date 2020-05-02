#Podemos simular un semaforo con el comando WAIT

#!/bin/bash
echo "-----Simulando Semaforo-----"

echo "Proceso 1 creado con exito"
sleep 30 &
pidProcess=$!

echo "Proceso 2 creado con exito" &
wait $pidProcess

echo "---Mostrando resultados---"
echo "Finalizando proceso 1, con PID "$pidProcess" ..."
wait $!
echo "Finalizando proceso 2, con PID "$!" ..."
