#include<stdio.h>
int main()
{
int i,j,k;
int count;
count=0;
for(i=1;i<=3;i++)
{
for(j=1;j<=i*i;j++)
{
if(j%i==0){
for(k=1;k<=j;k++) 
{
count++;
printf("Ravi\n");
}
}
}
}
printf("%d",count);
return 0;
}