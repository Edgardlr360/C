#include <stdio.h>                                                  /*Help by rulygamer03*/
#define TRUE 1
#define FALSE 0

int main() 
{
  int x, n = FALSE, parnt = FALSE, comillas = FALSE;                /*Se crea contador de numeros y contador de parentesis*/
  while ((x = getchar()) != EOF) 
  {
      switch(x)                                                     /*Cuando son parentesis el contador aumenta*/
      {
     
      case '[':
          parnt=TRUE;
          putchar(x);
          break;
      case ']':
          parnt=FALSE;
          putchar(x);
          break;
      case '(':
          parnt=TRUE;
          putchar(x);
          break;
      case ')':
          parnt=FALSE;
          putchar(x);
          break;
      case '{':
          parnt=TRUE;
          putchar(x);
          break;
      case '}':
          parnt=FALSE;
          putchar(x);
          break;
      case '<':
          parnt=TRUE;
          putchar(x);
          break;
      case '>':
          parnt=FALSE;
          putchar(x);
          break;
      case '\"':
          putchar(x);
         comillas++;
          break;

       case '\'':
          putchar(x);
          comillas++;
          break;

      default:
        if(x!='.'&&x!=':'&&x!='\?'&&x!='!'&&x!='-'&&x!=';'&&x!='_')  /*Se le quita la puntuacion al texto*/
        {                                                                 
            if (parnt==TRUE||comillas==TRUE)
            {
            putchar(x);
            }
            else{
                if (comillas==2)
                {
                    comillas=0;
                }
                if (x=='1'||x=='2'||x=='3'||x=='4'||x=='5'||x=='6'||x=='7'||x=='8'||x=='9'||x=='0')
                {
                    n++;
                }else{
                  n=0;
                }
                if (n==1)
                {
                    putchar('X');
                }
                if (n==0)
                {
                    putchar(x);
                }
            }
        }
        }
    }
    return 0;
  }
