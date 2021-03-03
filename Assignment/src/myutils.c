#include <stdio.h>
#include <stdarg.h> 
#include "/home/ltts/Desktop/Aman Kalaskar/LINUX_Assgnment/Assignment/inc/myutils.h"
int factorial(int x){
    int i,fact=1;   
    for(i=1;i<=x;i++){    
      fact=fact*i;    
    }    
    printf("Factorial of %d is: %d\n",x,fact);
    return fact; 
}
int isPrime(int n){
    int i, flag = 0;

    for (i = 2; i <= n / 2; ++i) {
        if (n % i == 0) {
            flag = 1;
            break;
        }
    }

    if (n == 1) {
        printf("1 is neither prime nor composite.\n");
        return -1;
    }
    else {
        if (flag == 0){
            printf("%d is a prime number.\n", n);
            return 0;
        }            
        else{
            printf("%d is not a prime number.\n", n);
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
            printf("%d is a palindrome.\n", originalN);
        return 0;
    }
    else{
        printf("%d is not a palindrome.\n", originalN);
        return 1;
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
    printf("vsum is: %d\n",sum);
    return sum; 
}
