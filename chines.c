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
int main()
{
  //os 6 numeros representantes
  /*exemplo
  x congruente 2 mod(3)--2 Numeros
  x congruente 4 mod(5)--2 Numeros
  x congruente 6 mod(7)--2 Numeros*/
  int x = 1;
  int arr[6];
  for(int i = 0;i < 6;i++)
  {
    scanf("%d",&arr[i]);
  }
  for(int i = 0;i < 6;i++)
  {
    if(i % 2 != 0)
    {
      x = x*arr[i];
    }
  }
  int mone = x/arr[0];
  int mtwo = x/arr[2];
  int mthree =x/arr[4];
  int v1 = arr[1];
  int v2 = arr[3];
  int v3 = arr[5];
/////////////////////////////////
///CALCULAR O 1
  int array[100];
  memset(array,-1,sizeof(array));//declaração do array inicial
  mdc(mone,v1,0,array,0);//a função pra iniciar tudo
  int n = 0;
  int xlinha;
  int multi1;
  n = check(array,n);//o numero necessario

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
   if(v1*arr1[1] + mone*arr1[0] == maior_divisor(v1,mone))
   {
     xlinha = arr1[1];
   }
   else if(v1*arr1[0]+ mone*arr1[1] == maior_divisor(v1,mone))
   {
      xlinha = arr1[1];
   }
   else if(mone*arr1[1] + v1*arr1[0] == maior_divisor(v1,mone))
   {
      xlinha = arr1[1];
   }
   else if(mone*arr1[0] + v1*arr1[1] == maior_divisor(v1,mone))
   {
      xlinha = arr1[1];
   }

   multi1 = xlinha*1;
   multi1 = multi1 % v1;
   printf("%d",multi1);
//CALCULAR 0 2
   int array2[100];
   memset(array2,-1,sizeof(array));//declaração do array inicial
   mdc(mtwo,v2,0,array,0);//a função pra iniciar tudo
   int n = 0;
   int xlinha;
   int multi2;
   n = check(array,n);//o numero necessario

   int arr2[n];
   memset(arr2,-1,sizeof(arr2));
     for(int i = n-1;i >= 0;i--)
     {
       if(i == n-1)
       {
         arr2[n-1] = 1*arr[n-1];
       }
      else if(i == n-2)
      {
        arr2[n-2] = arr2[n-1]*arr[n-2]+1;
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
    if(v2*arr1[1] + mtwo*arr2[0] == maior_divisor(v2,mtwo))
    {
      xlinha = arr2[1];
    }
    else if(v2*arr2[0]+ mtwo*arr2[1] == maior_divisor(v2,mtwo))
    {
       xlinha = arr2[1];
    }
    else if(mtwo*arr2[1] + v2*arr2[0] == maior_divisor(v2,mtwo))
    {
       xlinha = arr1[1];
    }
    else if(mtwo*arr1[0] + v2*arr1[1] == maior_divisor(v2,mtwo))
    {
       xlinha = arr1[1];
    }

    multi2 = xlinha*1;
    multi2 = multi2 % v2;
    printf("%d",multi2);
}
