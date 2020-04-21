#!/bin/bash

arc=$(sudo lscpu | grep -i arquitectura)
arc1=${arc:14}

if [ -z $arc1 ]; then
    echo "Error!"
else
    if [ $arc1 = "x86_64" ] || [ $arc1 = "x86-64" ] || [ $arc1 = "64" ] ;then
        echo "La arquitectura del sistema operativo es de 64 bits"        
    else
        echo "La arquitectura del sistema operativo es de 32 bits"
    fi
fi

echo " "

cant=$(sudo lscpu | grep -i -m 1 "cpu(s)")
cantC=${cant:8}

if [ -z $cantC ]; then
    echo "Error!"
else
    if [ $cantC = "0" ];then
        echo "El sistema es mono CPU"        
    else
        echo "El sistema es multi CPU"
    fi
fi



