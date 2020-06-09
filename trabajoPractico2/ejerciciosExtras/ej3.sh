#/bin/bash

log=$(lastlog --time 3)

if [[ $? == 0 ]];
then
    echo "Accesos al sistema en los ultimos 3 dias: "
    echo $log
fin