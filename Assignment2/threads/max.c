/**
 * @file max.c
 * @author Aman Kalaskar (amanajay.kalaskar@ltts.com)
 * @brief 
 * @version 0.1
 * @date 2021-03-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "minmax.h"

int Array[1000] = {0}, maxarr[10] = {0};
// fetching the arrays for max values
void *fetch(void *pv)
{
  int i, thread_num = (__intptr_t)pv, tempmax = 0;  
  for(i=0; i<100; ++i)
  {
    /* Searching maximum in 100 array values*/
    if(Array[thread_num * 100 + i] > tempmax)
    {
      tempmax = Array[i];
    }
  }
  maxarr[thread_num] = tempmax;
}

int getmax()
{
  int n=10, i, tempmax = 0;
  pthread_t ptrarr[n];

  srand(time(0));

  for(i=0; i<1000; i++)
  {
    /* Assigning random value to Array */
    Array[i] = random()%100;
  }
  for(i=0; i<n ; ++i)
  {
    /* Create a thread to search 100 array values */
    pthread_create(&ptrarr[i], NULL, fetch, (void*)(__intptr_t) i);
  }
  for(i=0; i<n ; ++i)
  {
    pthread_join(ptrarr[i], NULL);
  }
  for(i=0; i < n; ++i)
  {
    /* Find Maximum from thread results*/
    if(maxarr[i] > tempmax)
    {
      tempmax = maxarr[i];
    }
  }
  return tempmax;
}