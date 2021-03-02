#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

char *mystrcpy(char *a, char *b){
  /* Copy text1 to text2 using strcpy() */
  strcpy(a, b);

  printf("First string = %s\n", a);
  printf("Second string = %s\n", b);
  return b;
}

char *mystrcat(char *a, char *b){
  strcat(a,b);
  printf("Concatenated String: %s\n", a);
  char *ans = a;
  printf("%s",ans);
  return (char *) ans;
}
int mystrlen(char *a){
  int i;
  for (i = 0; a[i] != '\0'; ++i);
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