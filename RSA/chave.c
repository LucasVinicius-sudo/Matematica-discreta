#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int check_prime(int a)
{
  if(a == 1 || a == 0 )
  {
    return(0);
  }
  else if(a == 2)
  {
    return(1);
  }
  else if(a % 2 == 0)
  {
    return(0);
  }

  for(int i = 3;i <= a;i++)
  {
    if(a % i == 0)
    {
      return(0);
    }
    if(i == a)
    {
      return(1);
    }
  }

}

int mdc(int a,int b)
{
  if(a % b == 0)
  {
    return(b);
  }
  else
  {
    return mdc(b,a%b);
  }
}

int main()
{

  char  p[200];//O numero p
  char  q[200];//O numero q
  char  e[200];//O expoente e
  puts("Digite o p:");
  scanf("%s",p);
  puts("Digite o q:");
  scanf("%s",q);
  puts("Digite o expoente e");
  scanf("%s",e);

  char n[600];
  //n = p*q;
  //int x = (p-1)*(q-1);
  int cont = 0;
  if(check_prime(p)==0)
  {
    puts("p não é primo");
    cont = cont + 1;
  }
  if(check_prime(q)==0)
  {
    puts("q não é primo");
    cont = cont + 1;
  }
  if(n < 26)
  {
    cont = cont + 1;
  }
  if(mdc(e,x)!=1)
  {
    cont = cont +  1;

  }
  if(cont > 0)
  {
    printf("Não tem como gerar arquivo");
    return(0);
  }
  if(cont == 0)
  {

  }

  return(0);
}
