#/bin/bash

#Verifico que el servicio este activo en memoria
resul=$(ps aux | grep "$1")

if [[ ! -s $resul ]];
then
    echo "El proceso pasado por parametro no esta activo en memoria"
fi