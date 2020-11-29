#include <stdio.h>
void prime(int a)
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
     printf("Prime");
     return;
   }
   else
   {
    //printf("%d",resultado);
    printf("Nothing");
    return;
   }
}



int main()
{
  int number;
  scanf("%d",&number);
   prime(number);
  return(0);
}
