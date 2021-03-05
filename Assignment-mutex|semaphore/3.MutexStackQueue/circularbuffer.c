#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include<semaphore.h>
#define N 5    //maximum number of items
#define Size 5  //biffersize

sem_t empty;
sem_t full;
int front = -1; 
int rear = -1;    //index

int queue[Size];
pthread_mutex_t mutex;

void display(){
    if (front == -1) 
    { 
        printf("\n[Queue is Empty]"); 
        return; 
    } 
    printf("\n["); 
    if (rear >= front) 
    { 
        for (int i = front; i <= rear; i++) 
            printf(" %d ",queue[i]); 
    } 
    else
    { 
        for (int i = front; i < Size; i++) 
            printf(" %d ", queue[i]); 
  
        for (int i = 0; i <= rear; i++) 
            printf(" %d ", queue[i]); 
    }
    printf("]"); 
}

void *producer(void *p)
{   
    
    for(int i = 0; i < N; i++) {
        int item = rand()%100; // Produce an random item
        // sem_wait(&empty);
        pthread_mutex_lock(&mutex);

        if ((front == 0 && rear == Size-1) || 
            (rear == (front-1)%(Size-1))) 
        { 
            printf("\n[Queue is Full]"); 
            break; 
        } 
    
        else if (front == -1) /* Insert First Element */
        { 
            front = rear = 0; 
            queue[rear] = item; 
        } 
    
        else if (rear == Size-1 && front != 0) 
        { 
            rear = 0; 
            queue[rear] = item; 
        } 
    
        else
        { 
            rear++; 
            queue[rear] = item; 
        }
        printf("\n\nEnqueue: %d",item);
        display();


        pthread_mutex_unlock(&mutex);
        // sem_post(&full);
    }pthread_mutex_unlock(&mutex);
    
}
void *consumer(void *c)
{   
    for(int i = 0; i < N; i++) {
        // sem_wait(&full);
        pthread_mutex_lock(&mutex);
        int item;

        if (front == -1) 
        { 
            printf("\nQueue is Empty"); 
            break; 
        }
        else{
            item = queue[front];
        }
    
        // int data = queue[front]; 
        queue[front] = -1; 
        if (front == rear) 
        { 
            front = -1; 
            rear = -1; 
        } 
        else if (front == Size-1) 
            front = 0; 
        else
            front++; 
        printf("\n\nDequeue: %d",item);
        display();
        pthread_mutex_unlock(&mutex);
        // sem_post(&empty);
        
    }pthread_mutex_unlock(&mutex);
}
int main()
{   

    pthread_t pro[5],con[5];
    pthread_mutex_init(&mutex, NULL);
    // sem_init(&empty,0,Size);
    // sem_init(&full,0,0);

    //threads numbering
    int a[10] = {1,2,3,4,5}; 

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
    // sem_destroy(&empty);
    // sem_destroy(&full);
    
    return 0;
    
}