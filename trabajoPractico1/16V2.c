#include <pthread.h>
#include <stdio.h>
//#include <conio.h>

#define MAXPHILOSOPHERS 5
#define MINSTICKS 1
#define MAXSTICKS 2

int sticks = 5;
int todosComieron = 0;
int comensalFinalizado = 0;
int arrayComensales[MAXPHILOSOPHERS];
pthread_mutex_t mutexLock;


void *tomarPalillo(void *id){
    long idComensal = (long) id;

    while (arrayComensales[idComensal] < MAXSTICKS) {

        pthread_mutex_lock(&mutexLock);
        
        if (sticks >= MINSTICKS){
           
            printf("Tomando palillo comensal %ld \r\n",idComensal);
            sticks -= 1;
            arrayComensales[idComensal] += 1;
            printf("Actualmente hay %d palillos \r\n",sticks);
            
        }

        pthread_mutex_unlock(&mutexLock);        

    }
    pthread_exit(0);
}

void *devolverPalillo(void *id){
    
    long idComensal = (long) id;
    
    while (arrayComensales[idComensal] == MAXSTICKS){

        pthread_mutex_lock(&mutexLock);
                
        printf("El comensal numero %ld esta comiendo \r\n",idComensal);
        sticks += 2;
        arrayComensales[idComensal] = 0;
        printf("Devolviendo palillos \r\n");
        
        pthread_mutex_unlock(&mutexLock);
    }
    pthread_exit(0);
}

int main() {

    long idThread;
    pthread_t thread[MAXPHILOSOPHERS];
    pthread_t thread2[MAXPHILOSOPHERS];
    long returnThrearValue;

    pthread_mutex_init(&mutexLock,NULL);

    for ( idThread = 0; idThread < MAXPHILOSOPHERS; idThread++) {
        arrayComensales[idThread]=0;
        returnThrearValue = pthread_create(&thread[idThread],NULL,tomarPalillo,(void *)idThread);
        if (returnThrearValue) {
            printf("ERROR, code error = %ld \r\n",returnThrearValue);
        }
    }

    for (idThread = 0; idThread < MAXPHILOSOPHERS; idThread++) {
        returnThrearValue = pthread_join(thread1[idThread],NULL);
    }

    for ( idThread = 0; idThread < MAXPHILOSOPHERS; idThread++) {
        returnThrearValue = pthread_create(&thread2[idThread],NULL,devolverPalillo,(void *)idThread);
        if (returnThrearValue) {
            printf("ERROR, code error = %ld \r\n",returnThrearValue);
        }
    }

    for (idThread = 0; idThread < MAXPHILOSOPHERS; idThread++) {
        returnThrearValue = pthread_join(thread2[idThread],NULL);
    }
}