#include <stdio.h>
#include <pthread.h>
#define LOOPS 50000
 
void *job1(void *arg);
void *job2(void *arg);
unsigned int flag = 0;
unsigned int x = 0;
unsigned int ac = 0;

void *job1(void *arg)
{
    if ( flag == 0 ) {
      ac = ac + x;
    };
    return NULL;
}
 
void *job2(void *arg)
{
    x = 0;
    flag = 1;
    flag = 0;
    x = 1;
    return NULL;
}
 
int main(){
    
    printf("Starting...\n");
    pthread_t job1_threads[LOOPS];
    pthread_t job2_threads[LOOPS];
    long i;
    long rc;
    long rc1;

    for(i=0; i<LOOPS; i++){
        rc1 = pthread_create(&job1_threads[i], NULL, job1, NULL);
    }

    for(i=0;i<LOOPS;i++){
        rc = pthread_create(&job2_threads[i], NULL, job2, NULL);
    }

    for ( i = 0; i < LOOPS; i++) {
        rc1 = pthread_join(job1_threads[i],NULL);
    }
    
    
    printf("Finished. The value of 'ac' is: %d\n", ac);
}