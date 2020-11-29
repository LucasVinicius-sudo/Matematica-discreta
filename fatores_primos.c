#include <stdio.h>
int prime(int a)
{int resultado = 0;
   if(a == 1)
   {
     return 0;
   }
   if(a == 2)
   {
     return 1;
   }
   for(int i = 2;i <= a/2;i++)
   {
     if(a % i == 0)
     {
       resultado = resultado + 1;
     }
   }
   if(resultado == 0)
   {
     return 1;
   }
   else
   {
     return 0;
   }
}

void analise(int num,int sum)
{
   if(sum == num)
   {
     //rintf("%d ",sum);
     return;
   }
   else if(prime(sum)==1 && num % sum == 0)
   {
     printf("%d ",sum);
     analise(num,sum=sum + 1);
   }
   else if(prime(sum)!= 1)
   {
     //printf("%d ",sum);
     analise(num,sum=sum + 1);
   }
}
int main()
{
  int number;
  scanf("%d",&number);
  analise(number,2);
  return(0);
}
