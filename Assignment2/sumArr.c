/**
 * @file sumArr.c
 * @author Aman Kalaskar (amanajay.kalaskar@ltts.com)
 * @brief sum of array using multithreading
 * @version 0.1
 * @date 2021-03-03
 * 
 * @copyright Copyright (c) 2021 
 */
#include <stdio.h> 
#include <pthread.h> 

// size of array 
#define MAX 1000

// maximum number of threads 
#define MAX_THREAD 10 

int a[] = { 1, 5, 7, 10, 12, 14, 15, 18, 20, 22, 25, 27, 30, 64, 110, 220 };
int sum[10] = { 0 };
int part = 0;

void* sum_array(void* arg) 
{ 

	// Each thread computes sum of 1/10th of array 
	int thread_part = part++; 
	for (int i = thread_part * (MAX / 10); i < (thread_part + 1) * (MAX / 10); i++) 
		sum[thread_part] += a[i]; 
} 

// Driver Code 
int main() 
{ 

	pthread_t threads[MAX_THREAD]; 

	// Creating 10 threads 
	for (int i = 0; i < MAX_THREAD; i++) 
		pthread_create(&threads[i], NULL, sum_array, (void*)NULL); 

	// joining 10 threads i.e. waiting for all the  threads to complete 
	for (int i = 0; i < MAX_THREAD; i++) 
		pthread_join(threads[i], NULL); 

	// adding sum of all 10 parts 
	int total_sum = 0; 
	for (int i = 0; i < MAX_THREAD; i++) 
		total_sum += sum[i]; 

	printf("\nthe sum is: %d",total_sum);

	return 0; 
} 
