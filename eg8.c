#include<stdio.h>
int main()
{

printf("%d\n",foo(1));
return 0;
}
int foo(int count)
{
printf("%d\n",count);
if(count<3)
{
foo(foo(foo(++count)));
}
return count;
}