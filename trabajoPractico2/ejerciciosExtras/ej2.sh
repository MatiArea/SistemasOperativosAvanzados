#/bin/bash

#Obtengo el nombre de host pasado por parametro
host=$1

if [ -d /sys/class/net/$host ] 
then
    address=$(cat /sys/class/net/$host/address)
    echo "La MAC address del host con nombre $host es = $address"
else
    echo "El nombre de host parado por parametro no corresponde a un host valido"
fi
