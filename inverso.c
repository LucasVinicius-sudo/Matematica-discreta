#include <stdio.h>
#include <string.h>
int check(int arr[],int n)
{
  if(arr[n] == -1)
  {

    return(n);
  }
  else
  {

    return check(arr,n+1);
  }
}
int mdc(int a,int b,int divi,int arr[],int i)
{
  if(a%b == 0)
  {

    return(0);
  }
  else
  {
    divi = a/b;
    arr[i] = divi;

    return mdc(b,a%b,a/b,arr,i+1);
  }
}
int maior_divisor(int a,int b)
{
  if(b == 0)
  {
    return(a);
  }
  else
  {
  return(maior_divisor(b,a%b));
  }

}
//Fazer uma copia da combinalinear
int main()
{
int a,b;
scanf("%d %d",&a,&b);
if(maior_divisor(a,b)==1)
{
    if(a > b)//ajustando quem eh o maior
    {
      int aux = b;
      b = a;
      a = aux;

    }

    if(a == 0 || b == 0)//o caso de zero
    {
      printf("1");
      return(0);
    }
  int arr[100];//array irnicial
  memset(arr,-1,sizeof(arr));//declaração do array inicial
  mdc(a,b,0,arr,0);//a fun��o pra iniciar tudo
  int n = 0;

  n = check(arr,n);//o numero necessario

  int arr1[n];
  memset(arr1,-1,sizeof(arr1));
    for(int i = n-1;i >= 0;i--)
    {
      if(i == n-1)
      {
        arr1[n-1] = 1*arr[n-1];
      }
     else if(i == n-2)
     {
       arr1[n-2] = arr1[n-1]*arr[n-2]+1;
     }
     else if(i < n-2)
     {

       arr1[i] = arr[i]*arr1[i+1]+arr1[i+2];

     }

   }
  if(n % 2 == 0)
  {
    arr1[0] = arr1[0];
    arr1[1] = arr1[1]*-1;
  }
  if(n % 2 != 0)
  {
    arr1[0] = arr1[0]*-1;
    arr1[1] = arr1[1];
  }
  if(b*arr1[1] + a*arr1[0] == maior_divisor(b,a))
  {
    //puts("Test1");
    printf("%d",arr1[1]);
  }
  else if(b*arr1[0]+ a*arr1[1] == maior_divisor(b,a))
  {
    //puts("Test2");
    printf("%d",arr1[1]);
  }
  else if(a*arr1[1] + b*arr1[0] == maior_divisor(b,a))
  {
    //puts("Test3");
    printf("%d",arr1[1]);
  }
  else if(a*arr1[0] + b*arr1[1] == maior_divisor(b,a))
  {
    //puts("Test4");
    printf("%d ",arr1[1]);
  }
}
  return(0);
}
