#include <stdio.h>
int eucli(int a,int b)
{
  if(b == 0)
  {
    return a;
  }
  else
  {
    return eucli(b,a%b);
  }
}
int main()
{
  int a,b;
  scanf("%d%d",&a,&b);
  int resu = eucli(a,b);
  printf("%d",resu);
  return 0;
}
