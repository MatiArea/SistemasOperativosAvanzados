#!/bin/bash

echo "El PID del proceso es $$"

trap 'echo Interrupcion detectada' SIGINT
trap 'echo Suspender ejecución; kill $$' SIGTSTP
trap 'echo Fin de script' EXIT

while [ true ]; do

    echo "."
    sleep 1

done