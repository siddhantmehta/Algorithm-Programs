#include<stdio.h>
int main()
{
int number,x,counter;
scanf("%d",&number);
if(number<=0 || number>1000) return;
counter=0;
x=number/5;
while(x)
{
counter=counter+x;
x=x/5;
}
printf("%d",counter);
return 0;
}