#include<stdio.h>
#include<malloc.h>
int main()
{
int testcases,h,i,j,expression;
int *n,*k,*max,*s;
scanf("%d",&testcases);
if(testcases<1 && testcases>1000) return;
n=(int *)malloc(testcases*sizeof(int));
k=(int *)malloc(testcases*sizeof(int));
for(i=0;i<testcases;i++)
{
scanf("%d %d",&n[i],&k[i]);
}
for(i=0;i<testcases;i++)
{
if(n[i]<2 && n[i]>1000) return;
if(k[i]<2 && k[i]>n[i]) return;
}
max=(int *)malloc(testcases*sizeof(int));
for(i=0;i<testcases;i++)
{
max[i]=0;
s=(int *)malloc(n[i]*sizeof(int));
for(j=0;j<n[i];j++)
{
s[j]=(j+1);
}
for(j=0;j<n[i];j++)
{
for(h=0;h<n[i];h++)
{
if(j<h)
{
expression=s[j]&s[h];
if((expression<k[i]) && (expression>max[i])) max[i]=expression;
}
}
}
free(s);
printf("%d\n",max[i]);
}
free(n);
free(k);
free(max);
return 0;
}