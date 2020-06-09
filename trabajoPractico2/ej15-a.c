#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXPRODUCTS 1000000

int main(int argc, char const *argv[])
{
    int arrayPrices[MAXPRODUCTS];

    printf("Inciando la ejecucion\r\n");

    for (int i = 0; i < MAXPRODUCTS; i++) {
        arrayPrices[i] = pow(i+1,2);            //Genero un numero para cargarle informacion al array
        arrayPrices[i] += arrayPrices[i]*0.2;   //Incremento un 20% el valor del array
    }

    printf("Incremento realizado!");
    return 0;
}
