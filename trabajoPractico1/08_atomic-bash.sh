#!/bin/bash
echo "-----Simulando Semaforo-----"
echo "Proceso 1 creado con exito"
sleep 30 &
process_id=$!
echo "Proceso 2 creado con exito" &
echo "---Mostrando resultados---"
wait $process_id
echo "El proceso 1, con PID "$process_id", finalizo con estado: "$?
wait $!
echo "El proceso 2, con PID "$!", finalizo con estado: "$?
