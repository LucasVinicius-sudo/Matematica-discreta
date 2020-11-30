#include <stdio.h>
int  prime(int a)
{int resultado = 0;
   for(int i = 2;i <= a/2;i++)
   {
     if(a % i == 0)
     {
       resultado++;
     }
   }
   if(resultado == 0)
   {
     //printf("Prime");
     return(1);
   }
   else
   {
    //printf("%d",resultado);
    //printf("Nothing");
    return(0);
   }
}



int main()
{
  for(int i = 0;i < 100000;i++)
  {

    if(prime(i) == 1)
    {
      printf("%d\n",i);
    }


  }
}
