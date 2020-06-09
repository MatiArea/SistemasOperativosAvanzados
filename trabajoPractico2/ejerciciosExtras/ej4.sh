#/bin/bash

#Datos del email
asunto="ALERTA! Servicio inactivo"
autor=alerta@alerta.com
destinatario=serverAdmin@serverAdmin.com

#Calculo de memoria libre (en MB)
active=$(systemctl --quiet is-active $1)

if if [[ $? == 0 ]];
then
    if [ ! -s $active ];
    then
        echo "El servicio $1 esta inactivo - notificando"
        mailx -c $destinatario -s $asunto -r $autor -t "Servicio $1 = INACTIVO"
    fi
fi