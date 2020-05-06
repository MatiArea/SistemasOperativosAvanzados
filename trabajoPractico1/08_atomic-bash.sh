#Podemos simular un semaforo con el comando WAIT, TOUCH para crear un archivo y CAT para poder leer valores desde el archivo

#!/bin/bash

PID=1
PROCESOTOTAL=10

contar() {
    contador=$(cat sumFactorial.txt)
    echo $contador
    let COND=PID%2 
    if [ $COND -ne 0 ] && [ $contador -le 368047 ];
    then
        
        counter=$PID
        factorial=1
        while [ $counter -gt 0 ]
        do
            factorial=$(( $factorial * $counter ))
            counter=$(( $counter - 1 ))
        done
        var=$(($factorial + $contador))
        echo $var > sumFactorial.txt

    else
        sleep 1
        contar $PID
    fi
}

echo "Creando archivo..."
touch sumFactorial.txt
echo 0 > sumFactorial.txt
read

while [[ $PID -ne $PROCESOTOTAL ]]
do
    contar $PID &
    PID=$(( $PID + 1 ))
done

echo "El valor almacenado en el archivo es= "$(cat sumFactorial.txt)

wait
echo "Eliminando archivo..."
rm  sumFactorial.txt

#El codigo documentado aque es el codigo realizado bajo el concepto de semaforo, es decir, cree un algoritmo que tiene una variable
#que me permite realizar el control de hacer la accion o no. Se maneja de manera manual, no pude hacer que funcione automaticamente.
#Lo dejo adjunto porque pregunte 3 veces como se realizaba el ejercicio pero no me quedo muy claro, por lo tanto dejo las 2 soluciones 
#que pense
#
#!/bin/bash
#
# escribiendo=false
# var=''
# long=0
# arreglo=(h e l l o ' ' w o r l d)
#
# function escribiendo(){
#     if ! $escribiendo; then
#         if [[ long -lt 11 ]]; then
#             escribiendo=true
#             var="$var${arreglo[long]}"
#             long=$long+1
#             echo "Grabando letra..."
#             read
#             clear
#         else
#             echo "El mensaje fue terminado con exito "
#             read
#             clear
#         fi
#     else
#         echo "Proceso bloqueado"
#         read
#         clear
#     fi
# }
#
# function desbloquear(){
#     if $escribiendo; then
#         escribiendo=false
#         echo "Desbloqueando proceso..."
#     else
#         echo "El proceso ya esta desbloqueado"
#     fi
#     read
#     clear
# }
#
# valRta=1
# while [[ $valRta -ne 0 ]]; do
#     echo "1- Escribir letra"
#     echo "2- Dejar de escribir"
#     echo "3- Imprimir texto"
#     echo "0- Salir"
#     read valRta
#
#     if [[ $valRta -eq 1 ]];then
#         escribiendo
#     elif [[ $valRta -eq 2 ]];then
#         desbloquear
#     elif [[ $valRta -eq 3 ]];then
#         echo $var
#     elif [[ $valRta -eq 0 ]];then
#         echo "Finalizando ejecucion..."
#         exit
#     fi
# done