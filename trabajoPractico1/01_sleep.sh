#!/bin/bash

for valor in {1..10000};  do
    (echo "El valor es: "$valor)&
    sleep 0.00001
done

echo "La ejecucion de 01_sleep.sh ha finalizado"
