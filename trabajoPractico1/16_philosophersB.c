#include <pthread.h>
#include <stdio.h>
//#include <conio.h>

#define MAXPHILOSOPHERS 5   //Numero de filosofos en la mesa
#define MINSTICKS 2         //Minimo de palillos que debe haber en el centro de la mesa para poder comer
#define MAXSTICKS 2         //Numero de palillos que necesita tener el comensal para comenzar a comer

int sticks = 5;
int arrayComensales[MAXPHILOSOPHERS];   //Arreglo de filosofos para almacenar cuantos palillos tiene en su poder
int arrayComidos[MAXPHILOSOPHERS];      //Arreglo de filosofos para indicar si terminaron de comer 

pthread_mutex_t mutexLock;


void *tomarPalillo(void *id){
    long idComensal = (long) id;

    while (arrayComensales[idComensal] < MAXSTICKS) {

        pthread_mutex_lock(&mutexLock);
        
        if (sticks >= MINSTICKS){
           
            printf("Tomando palillo comensal %ld \r\n",idComensal);
            sticks -= 2;                                           //Resta un palillo del centro de la mesa
            arrayComensales[idComensal] += 2;                      //Indica que el comensal con numero idComensal tiene un palillo mas en su poder
           printf("Actualmente hay %d palillos \r\n",sticks);
            
        }        

        pthread_mutex_unlock(&mutexLock);        

    }
    pthread_exit(0);
}

void *devolverPalillo(void *id){
    
    long idComensal = (long) id;

    while (arrayComidos[idComensal] == 0){
        if(arrayComensales[idComensal] == 2){
            pthread_mutex_lock(&mutexLock);
                    
            printf("El comensal numero %ld esta comiendo \r\n",idComensal);
            sticks += 2;                                                   //Suma 2 palillos al centro de la mesa para que pueda ser usados por los demas comensales    
            arrayComensales[idComensal] = 0;                               //Indica que el comensal con numero idComensal dejo de tener 2 palillos
            arrayComidos[idComensal] = 1;                                  //Indica que el comensal con numero idComensal termino de comer y devolvio los palillos
            printf("Devolviendo palillos \r\n");
            
            pthread_mutex_unlock(&mutexLock);
        }
    }

    pthread_exit(0);
}

int main() {

    long idThread;
    pthread_t thread1[MAXPHILOSOPHERS];
    pthread_t thread2[MAXPHILOSOPHERS];
    long returnThrearValue1,returnThrearValue2;

    pthread_mutex_init(&mutexLock,NULL);

    for ( idThread = 0; idThread < MAXPHILOSOPHERS; idThread++) {

        arrayComensales[idThread]=0;
        arrayComidos[idThread]=0;
        returnThrearValue1 = pthread_create(&thread1[idThread],NULL,tomarPalillo,(void *)idThread);
        returnThrearValue2 = pthread_create(&thread2[idThread],NULL,devolverPalillo,(void *)idThread);
        if (returnThrearValue1) {
            printf("ERROR, code error = %ld in create of thread1 \r\n",returnThrearValue1);
        }
        if (returnThrearValue2) {
            printf("ERROR, code error = %ld on create of thread2 \r\n",returnThrearValue1);
        }

    }

    for (idThread = 0; idThread < MAXPHILOSOPHERS; idThread++) {
    
        returnThrearValue1 = pthread_join(thread1[idThread],NULL);
        returnThrearValue2 = pthread_join(thread2[idThread],NULL);
    
    }

    printf("\r\n=======================================\r\n");
    for (int i = 0; i < MAXPHILOSOPHERS; i++) {
        
        if (arrayComidos[i] == 1){
            printf("El comensal %d termino de cenar con exito \r\n",i);
        }

    }
    
}