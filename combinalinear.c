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
int maior_divi(int a,int b)
{
  if(b == 0)
  {
    return(a);
  }
  else
  {
    return(maior_divi(b,a%b));
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
int main()
{
  int a,b;
  scanf("%d%d",&a,&b);
  if(a > b)//ajustando quem eh o maior
  {
    int aux = b;
    b = a;
    a = aux;

  }
  if(a == 0 || b == 0)//o caso de zero
  {
   printf("1*%d - 1*%d",b,a);
   return(0);
  }
  int arr[100];//array irnicial
  memset(arr,-1,sizeof(arr));//declara��o do array inicial
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
puts("BEFORE:");
printf("%d\n",maior_divi(b,a));
printf("%d %d\n",a,b);
printf("%d %d\n",arr1[0],arr1[1]);
puts("-------");
if(b*arr1[1] + a*arr1[0] == maior_divi(b,a))
{
    if(arr1[1] > arr[0])
    {

    }
    else
    {

    }

}
else if(b*arr1[0]+ a*arr1[1] == maior_divi(b,a))
{
  printf("%d*%d - %d*%d",arr1[0],b,arr1[1]*-1,a);
}
else if(a*arr1[1] + b*arr1[0] == maior_divi(b,a))
{
  printf("%d*%d - %d*%d",arr1[1],a,arr1[0]*-1,b);
}
else if(a*arr1[0] + b*arr1[1] == maior_divi(b,a))
{
  printf("%d*%d - %d*%d",arr1[0],a,arr1[1]*-1,b);
}

  return(0);
}
