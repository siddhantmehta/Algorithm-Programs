#include<stdio.h>
#include<malloc.h>
int main()
{
int *S;
int numberOfInputs,primeNumber,x,y,count;
scanf("%d",&numberOfInputs);
if(numberOfInputs>100) return;
S=(int *)malloc(sizeof(int)*numberOfInputs);
x=0;
while(x<numberOfInputs)
{
scanf("%d",&S[x]);
if(S[x]<1 || S[x]>1000000) return;
x++;
}
x=0;
while(x<numberOfInputs)
{
y=0;
count=0;
while(y<numberOfInputs)
{
if(S[x]%S[y]==0)
{
count++;
}
y++;
}
if(count==1)
{
printf("%d ",S[x]);
}
x++;
}
return 0;
}