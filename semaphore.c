/* Thread Synchronization using semaphore */
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

//function definition for thread
void monitor(void *ptr);
sem_t mutex; //define semaphore
int counter;

int main(){
    pthread_t thread1;
    pthread_t thread2;
    
    int i[2]; //argument to threads
    i[0]=0;
    i[1]=1;
    
    //initialize semaphore as binary semaphore
    sem_init(&mutex, 0, 1);
    
    //thread creation
    pthread_create(&thread1,NULL,(void *)&monitor,(void *)&i[0]);
    pthread_create(&thread2,NULL,(void *)&monitor,(void *)&i[2]);
    
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    
    sem_destroy(&mutex);
    
    exit(0);
}

void monitor(void *ptr){
    int x;
    x = *((int *) ptr);
    printf("Thread %d: Waiting to enter critical region...\n", x);
    sem_wait(&mutex);       //down semaphore
    //START CRITICAL REGION
    printf("Thread %d: Now in critical region...\n", x);
    printf("Thread %d: Counter Value: %d\n", x, counter);
    printf("Thread %d: Incrementing Counter...\n", x);
    counter++;
    printf("Thread %d: New Counter Value: %d\n", x, counter);
    printf("Thread %d: Exiting critical region...\n", x);
    // END CRITICAL REGION
    sem_post(&mutex);       // up semaphore

    pthread_exit(0);
}