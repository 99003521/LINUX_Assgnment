#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include<semaphore.h>
#define N 3     //maximum number of items
#define Size 3  //biffersize

sem_t empty;
sem_t full;
int top=-1;     //index

int stack[Size];
pthread_mutex_t mutex;
void *producer(void *p)
{   
    
    for(int i = 0; i < N; i++) {
        int item = rand()%100; // Produce an random item
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        stack[++top] = item;

        printf("Producer %d:\tPush %d\n", *((int *)p),item);
        
        //printing the stack
        printf("stack:[");
        for(int j = 0; j < N; j++) {
        printf(" %d ",stack[j]);
        }
        printf("]\n\n");

        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
}
void *consumer(void *c)
{   
    for(int i = 0; i < N; i++) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        int item = stack[top];
        stack[top--]=0;
        
        printf("Consumer %d:\tPop %d\n",*((int *)c),item);
        
        //printing the stack
        printf("stack:[");
        for(int j = 0; j < N; j++) {
        printf(" %d ",stack[j]);
        }
        printf("]\n\n");
        
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
        
    }
}
int main()
{   

    pthread_t pro[10],con[5];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty,0,Size);
    sem_init(&full,0,0);

    //threads numbering
    int a[10] = {1,2,3,4,5,6,7,8,9,10}; 

    for(int i = 0; i < N; i++) {
        pthread_create(&pro[i], NULL, (void *)producer, (void *)&a[i]);
    }
    for(int i = 0; i < N; i++) {
        pthread_create(&con[i], NULL, (void *)consumer, (void *)&a[i]);
    }

    for(int i = 0; i < N; i++) {
        pthread_join(pro[i], NULL);
    }
    for(int i = 0; i < N; i++) {
        pthread_join(con[i], NULL);
       
    }

    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
    
    return 0;
    
}