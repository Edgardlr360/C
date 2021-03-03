#include<stdio.h>
#include<math.h>
#define K 13                /* Los primeros 13 numeros primos */

void primo(int n);
void binario(int j);
int main()
{
  primo(K);                /*Esto llama a la función*/
  return 0;
}

void binario(int j)
{
    int i=0;               /* El contador del codigo*/
    int base[7]={0};       /* numero de ceros */
   
    while(j>0)             /* Saca el residuo y lo ubica en la posicion, divide el numero y aumenta la posicion*/
    {
	base[i]= j%2;          /* residuo de la division*/
	j/=2;                  /* division*/
	++i;                   /* aumenta en 1 la posicion*/
    }
    for(int x=6;x>=0;--x)  /* numero de arriba menos 1*/
    {
       printf("%01d",base[x]);
    }
     printf("\n");        /* al terminar de imprimir, salto de linea*/
}

void primo(int k)             /*Helped by Orla Gomez and rulgamer*/
{
  int i, contador, x, flag;
  int n=1;
  contador = 1;

  while(contador <= k)
  {
    x = sqrt(n);
    flag = 0;              /*Tengo como si ya tuviera un numero primo*/
    for(i=2; i<= x; i++)
    {
      if(n%i==0)
      {
        flag = 1;         /*Si no es primo flag = 1 y no se cumple el siguiente if*/
        break;
      }
    }

    if(flag==0)          /*si es primo*/
    { 
      binario(n);        /* usa la funcion y transforma a binario*/
      contador++;        /*Conteo para no pasarse del limite*/
    }
    n++; 
  }
}
