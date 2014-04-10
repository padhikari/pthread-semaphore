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
    
    int i[2]={0,1}; //argument to threads
    
    //initialize semaphore as binary semaphore
    sem_init(&mutex, 0, 1);
    
    //thread creation
    pthread_create(&thread1,NULL,(void *)&monitor,(void *)&i[0]);
    pthread_create(&thread2,NULL,(void *)&monitor,(void *)&i[2]);
    
    sem_destroy(&mutex);
    
    
    exit(0);
}

void monitor(void *ptr){
    
    pthread_exit(0);
}