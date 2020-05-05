#include <pthread.h>
#include <stdio.h>
//#include <conio.h>


#define MINSTICKS 1
#define MAXSTICKS 2
int sticks = 5;

#define MAXPHILOSOPHERS 5
#define MAXMUTEX 5
int arrayComensales[MAXPHILOSOPHERS];

pthread_mutex_t mutexLock[5];


void *tomarPalillo(void *id){
    long idComensal = (long) id;
    long palilloIzquierda = idComensal+1;

    pthread_mutex_lock(&mutexLock[idComensal]);

    while (pthread_mutex_trylock(&mutexLock[palilloIzquierda])) {
        pthread_mutex_unlock(&mutexLock[idComensal]);
        pthread_mutex_lock(&mutexLock[idComensal]);
    }
    
    pthread_mutex_lock(&mutexLock[palilloIzquierda]);
    printf("El comensal %ld esta comiendo \r\n",idComensal);

    pthread_mutex_unlock(&mutexLock[idComensal]);
    pthread_mutex_unlock(&mutexLock[palilloIzquierda]);
 
    pthread_exit(0);
}


int main() {

    long idThread;
    pthread_t thread[MAXPHILOSOPHERS];
    long returnThrearValue;

    for (int idMutex = 0; idMutex < MAXMUTEX; idMutex++) {
        pthread_mutex_init(&mutexLock[MAXMUTEX],NULL);
    }
    

    for ( idThread = 0; idThread < MAXPHILOSOPHERS; idThread++) {

        returnThrearValue = pthread_create(&thread[idThread],NULL,tomarPalillo,(void *)idThread);
        if (returnThrearValue) {
            printf("ERROR, code error = %ld \r\n",returnThrearValue);
        }

    }

    for (idThread = 0; idThread < MAXPHILOSOPHERS; idThread++) {
        returnThrearValue = pthread_join(thread[idThread],NULL);
    }

}

