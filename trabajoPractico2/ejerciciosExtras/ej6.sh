#/bin/bash

#Envio 3 paquetes, con un intervalo de 2 segundos, esperando 3 segundos maximo de respuesta al enlace parsado por parametro.
pingValue=$(ping -n -c 3 -i 2 -W 3 $1)

if [[ $? != 0 ]];
then
    if [[ $pingValue =~ "loss" ]]
    then
            valueError=$(echo $pingValue | grep 'loss')
    else
            valueError=$pingValue
    fi
    echo "ENLACE $1 INACTIVO"
    echo $valueError
fi