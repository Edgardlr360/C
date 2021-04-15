#include<ctype.h>
#include <stdio.h> 
#include <string.h> 
#define MAX 100 

int main(void)
{ 
  
char TEXTO1[MAX];
char VOLTEADA[MAX];

  scanf("%s",TEXTO1); 

int i, e; 
  for(i = strlen(TEXTO1)-1, e = 0; 0 <= i; i--, e++) 
  VOLTEADA[e] = TEXTO1[i]; 
  VOLTEADA[e] = '\0'; 

char prueba; 


 prueba=strcmp(TEXTO1, VOLTEADA); 
    if(prueba == 0) 
    {
        printf("The string IS  a palindrome.\n");
    }
    else
    {
        printf("The string IS NOT a palindrome.\n"); 
    }
  return(0); 
}
