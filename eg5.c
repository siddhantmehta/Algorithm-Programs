#include<stdio.h>
int n=1;
void test()
{
n=190;
{
int n;
n=210;
printf("%d\n",n);
}
printf("%d\n",n);

}
int main()
{
test();
//n=50;
printf("%d\n",n);
return 0;
}