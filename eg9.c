#include <stdio.h>
int main()
{
printf("fsada %d\n",fun(99));
return 0;
}
int fun(int n)
{
if(n>100) 
{
printf("if %d\n",n);
return n-10;
}
else
{
printf("else %d\n",n);
return fun(fun(n+11));
}
}