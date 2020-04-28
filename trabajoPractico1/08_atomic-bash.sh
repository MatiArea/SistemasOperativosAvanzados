#!/bin/bash
echo "-----Simulando Semaforo-----"

echo "Proceso 1 creado con exito"
sleep 30 &
pidProcess=$!

echo "Proceso 2 creado con exito" &
wait $pidProcess

echo "---Mostrando resultados---"
echo "El proceso 1, con PID "$pidProcess", finalizo con estado: "$?
wait $!
echo "El proceso 2, con PID "$!", finalizo con estado: "$?
