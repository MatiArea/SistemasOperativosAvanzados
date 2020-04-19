#!/bin/bash
function mostar(){
    echo "El valor es: "$1
}

for valor in {1..10000};  do
    mostar $valor &
    wait %mostar
done

echo "La ejecucion de 01_wait.sh ha finalizado"