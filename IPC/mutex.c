#include<pthread.h>
#include<stdio.h>
int val = 100;
int iter=1000;
pthread_t tid[2]; 
int counter; 
pthread_mutex_t lock;

void* task_body1(void* pv)
{
    // pthread_mutex_lock(&lock);
	for(int i=0;i<iter;i++)
	    val++;
    // pthread_mutex_unlock(&lock);
}
void* task_body2(void* pv)
{
    // pthread_mutex_lock(&lock);
    for(int i=0;i<iter;i++)
	    val--;
    // pthread_mutex_unlock(&lock);
}
int main()
{
	pthread_t pt1,pt2;	//thread handle
	pthread_create(&pt1,NULL,task_body1,NULL);
	pthread_create(&pt2,NULL,task_body2,NULL);
	pthread_join(pt1,NULL);
	pthread_join(pt2,NULL);
	printf("\nfinal val =%d\n",val);
    pthread_mutex_destroy(&lock);
	return 0;	//exit(0);
}
