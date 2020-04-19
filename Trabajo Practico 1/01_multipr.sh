#!/bin/bash

for valor in {1..10000};  do
    echo "El valor es: "$valor &
done

echo "La ejecucion de 01_monopr.sh ha finalizado"