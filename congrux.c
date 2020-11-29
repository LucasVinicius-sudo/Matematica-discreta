#include <stdio.h>
int mdc(int a,int b)
{
  if(b == 0)
  {
    return(a);
  }
  else
  {
    return(mdc(b,a%b));
  }
}
int main()
{
  int a,b,c;
  scanf("%dx congruente %d mod(%d)",a,b,c);
  if(mdc(a,c) % b != 0)
  {
    puts("Não tem solução");
  }
  else if(mdc(a,c) % b == 0)
  {
    int d = mdc(a,c);
    a = a/d;
    b = b/d;
    c = c/d;
  }
  return(0);
}
