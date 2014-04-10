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
    
    
    exit(0);
}

void monitor(void *ptr){
    
    pthread_exit(0);
}