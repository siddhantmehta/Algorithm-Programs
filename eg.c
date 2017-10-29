#include<stdio.h>
int main()
{
int x;
printf("Enter year : ");
scanf("%d",&x);
if(x%4==0) printf("%d is a leap year.",x);
else printf("%d is not leap year.",x);
return 0;
}