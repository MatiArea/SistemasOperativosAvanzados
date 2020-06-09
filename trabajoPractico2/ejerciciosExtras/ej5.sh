#/bin/bash


#Datos del email
asunto="ALERTA! Uso de memoria al maximo"
autor=alerta@alerta.com
destinatario=serverAdmin@serverAdmin.com

#Calculo de memoria libre (en MB)
memory=$(free -mt | grep Mem | awk '{print $4}')

if [[ $free -le 500 ]];
then
    echo "Uso de memoria llegando al limite - notificando"
    mailx -c $destinatario -s $asunto -r $autor -t "Memoria al limite. Memoria libre = 500MB"
fi