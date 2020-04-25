#!/bin/bash

echo "Fabricante del Sistema: " >> 04_hardware.txt
sis=$(sudo dmidecode -t system | grep -i manufacturer)
echo ${sis:15} >> 04_hardware.txt
echo " ">>04_hardware.txt

echo "Version del Procesador: " >> 04_hardware.txt
pro=$(sudo dmidecode -t processor | grep -i version)
echo ${pro:9} >> 04_hardware.txt
echo " ">>04_hardware.txt

echo "Fecha de inicio de la BIOS: " >> 04_hardware.txt
bios=$(sudo dmidecode -t bios | grep -i date)
echo ${bios:14} >> 04_hardware.txt
echo " ">>04_hardware.txt

echo "Memoria máxima que el sistema permite: " >> 04_hardware.txt
mem=$(sudo dmidecode -t memory | grep -i max)
echo ${mem:18} >> 04_hardware.txt
echo " ">>04_hardware.txt
