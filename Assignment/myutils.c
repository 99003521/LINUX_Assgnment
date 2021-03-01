#include "myutils.h"
#include<stdio.h>
#include <stdarg.h> 

int factorial(int x){
    int i,fact=1;  
    printf("Enter a x: ");    
    scanf("%d",&x);    
    for(i=1;i<=x;i++){    
      fact=fact*i;    
    }    
    printf("Factorial of %d is: %d",x,fact);
    return fact; 
}
int isPrime(int n){
    int i, flag = 0;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    for (i = 2; i <= n / 2; ++i) {
        if (n % i == 0) {
            flag = 1;
            break;
        }
    }

    if (n == 1) {
        printf("1 is neither prime nor composite.");
        return -1;
    }
    else {
        if (flag == 0){
            printf("%d is a prime number.", n);
            return 0;
        }            
        else{
            printf("%d is not a prime number.", n);
            return 1;
        }            
    }
}

int isPalindrome(int n){ 
    int reversedN = 0, remainder, originalN;
    originalN = n;
    while (n != 0) {
        remainder = n % 10;
        reversedN = reversedN * 10 + remainder;
        n /= 10;
    }
    if (originalN == reversedN){
            printf("%d is a palindrome.", originalN);
        return 0;
    }
    else{
        printf("%d is not a palindrome.", originalN);
        return 0;
    }
}

int vsum(int num, ...) 
{ 
    va_list valist; 
    int sum = 0, i; 
    va_start(valist, num); 
    for (i = 0; i < num; i++)  
        sum += va_arg(valist, int);
    va_end(valist);
    return sum; 
}
