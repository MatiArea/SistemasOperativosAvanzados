#!/bin/bash

echo "Fabricante del Sistema: " >> test.txt
sis=$(sudo dmidecode -t system | grep -i manufacturer)
echo ${sis:15} >> test.txt
echo " ">>test.txt

echo "Version del Procesador: " >> test.txt
pro=$(sudo dmidecode -t processor | grep -i version)
echo ${pro:9} >> test.txt
echo " ">>test.txt

echo "Fecha de inicio de la BIOS: " >> test.txt
bios=$(sudo dmidecode -t bios | grep -i date)
echo ${bios:14} >> test.txt
echo " ">>test.txt

echo "Memoria máxima que el sistema permite: " >> test.txt
mem=$(sudo dmidecode -t memory | grep -i max)
echo ${mem:18} >> test.txt
echo " ">>test.txt
