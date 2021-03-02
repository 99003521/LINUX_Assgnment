#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

char *mystrcpy(char *a, char *b){
  char text1[MAX_SIZE] = a, text2[MAX_SIZE] = b;

  /* Input original string from user */
  printf("Enter any string: ");
  gets(text1);

  /* Copy text1 to text2 using strcpy() */
  strcpy(text2, text1);

  printf("First string = %s\n", text1);
  printf("Second string = %s\n", text2);
  return text2;
}

char *mystrcat(char *a, char *b){
  char destination[] = a;
  char source[] = b;
  strcat(destination,source);
  printf("Concatenated String: %s\n", destination);
  char *ans = destination;
  return (char *) ans;
}

int mystrlen(char *a){
  char s[] = a;
  int i;
  for (i = 0; s[i] != '\0'; ++i);
  printf("Length of the string: %d", i);
  return i;
}

int mystrcmp(char *a,char *b){
  // return strcmp(a,b);
  int flag=0,i=0;  // integer variables declaration  
  while(a[i]!='\0' &&b[i]!='\0')  // while loop  
  {  
    if(a[i]!=b[i])  
    {  
      flag=1;  
      break;  
    }  
    i++;  
  }  
  if(flag==0)  
    return 0;  
  else  
    return 1;  
}