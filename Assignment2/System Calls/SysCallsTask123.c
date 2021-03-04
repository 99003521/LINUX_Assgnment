#include <stdio.h> 
#include <stdlib.h> 

int main() 
{ 
	FILE *fptr1, *fptr2;
    int characters=0,words=1,lines=1;
	// Open one file for reading 
	fptr1 = fopen("text1.txt", "r"); 
	if (fptr1 == NULL) 
	{ 
		printf("Cannot open file %s \n", "text1.txt"); 
		exit(0); 
	} 
	// Open another file for writing 
	fptr2 = fopen("text2.txt", "w"); 
	if (fptr2 == NULL) 
	{ 
		printf("Cannot open file %s \n", "text2.txt"); 
		exit(0); 
	} 
	// Read contents from file 
	char c = fgetc(fptr1);
    // Write contents from file
    printf("Copying contents...\n\n*****\n");
    while (c != EOF) 
	{ 
		fputc(c, fptr2);
		printf("%c",c);
		
        ++characters;
        if(c ==' '){
            ++words;
        }
        else if(c == '\n'){
            ++lines;
            ++words;
        }
		c = fgetc(fptr1);
        
	} 
    printf("\n*****\n");
	printf("\nContents copied to %s\n", "text2.txt");
    printf("\nCharacters: %d\nWords: %d\nLines: %d\n",characters,words,lines);
	fclose(fptr1); 
	fclose(fptr2); 
	return 0; 
}
//Geeks for geeks reffered fior the code