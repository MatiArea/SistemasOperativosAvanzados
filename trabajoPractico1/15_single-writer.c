#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXTHREAD 10
#define MAXCOUNTER 100

long counter = 0;
pthread_mutex_t mutexLock;

void *increment(void *t){
    long idThread = (long) t;
    
    while (counter < MAXCOUNTER) {
        pthread_mutex_lock(&mutexLock);
        
        if (counter < MAXCOUNTER) {

            printf("Process %ld is incrementing counter \r\n",idThread);
            counter+=1;
            printf("Partial value of counter = %ld \r\n",counter);
            
        }
        
        pthread_mutex_unlock(&mutexLock);
    

    }

    pthread_exit(0);     
}

int main() {
    printf("---------- MAIN ---------- \r\n");

    long idThread;
    pthread_t thread[MAXTHREAD];
    long returnThrearValue;

    pthread_mutex_init(&mutexLock,NULL);

    for ( idThread = 0; idThread < MAXTHREAD; idThread++) {

        returnThrearValue = pthread_create(&thread[idThread],NULL,increment,(void *) idThread);
        if (returnThrearValue) {
            printf("ERROR! Code error on create() = %ld \r\n",returnThrearValue);
        }
    }

    for ( idThread = 0; idThread < MAXTHREAD; idThread++) {
        returnThrearValue = pthread_join(thread[idThread],NULL);
    }
    
    printf("===== The counter is full ===== \r\n");
    printf("->Value = %ld \r\n",counter);
    pthread_exit(0);

}

