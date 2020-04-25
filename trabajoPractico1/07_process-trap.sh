#!/bin/bash

echo "El PID del proceso es $$"

#trap 'Interrupcion detectada' SIGINT
trap 'echo Detenido, kill $$' SIGTSTP

while [ true ]; do

    echo "."
    sleep 1

done



