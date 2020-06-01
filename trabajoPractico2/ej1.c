#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    
    char nombre[50];

    printf("Ingrese su nombre: \r\n");
    scanf("%s",nombre);

    printf("\r\nBienvenido %s \r\n",nombre);
    printf("Este es un script para limpiar la terminal de un sistema operativo linux \r\n");
    printf("\r\nPresione una tecla para continuar... \r\n");
    getchar();
    getchar();
    
    system("clear");
    
    printf("Terminal limpiada. Hasta luego %s \r\n",nombre);

    return 0;

}
