#include <pthread.h>
#include <stdio.h>
//#include <conio.h>

#define MAXPHILOSOPHERS 5
#define MINSTICKS 2

int sticks = 5;
int arrayComensales[MAXPHILOSOPHERS];


void *tomarPalillo(void *id){
    long idComensal = (long) id;

    while (arrayComensales[idComensal] < MINSTICKS) {

        if (sticks >= 1){
           
            printf("Tomando palillo comensal %ld \r\n",idComensal);
            sticks -= 1;
            arrayComensales[idComensal] += 1;
            
        }

    }

    printf("El comensal numero %ld esta comiendo \r\n",idComensal);
    sticks += 2;
    printf("Devolviendo palillos \r\n");
    
    pthread_exit(0);
    
}

int main() {

    long idThread;
    pthread_t thread[MAXPHILOSOPHERS];
    long returnThrearValue;

    for ( idThread = 0; idThread < MAXPHILOSOPHERS; idThread++) {
        arrayComensales[idThread]=0;
        returnThrearValue = pthread_create(&thread[idThread],NULL,tomarPalillo,(void *)idThread);
        if (returnThrearValue) {
            printf("ERROR, code error = %ld \r\n",returnThrearValue);
        }
        
    }

    for ( idThread = 0; idThread < MAXPHILOSOPHERS; idThread++) {
        returnThrearValue = pthread_join(thread[idThread],NULL);
    }

}