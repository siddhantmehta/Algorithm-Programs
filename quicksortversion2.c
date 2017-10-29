#include<stdio.h>
#include<stdlib.h>
int rPivot(int i,int j)
{
int x = i + rand()%(j-i+1);
printf("Random %d\n",x);
return x;
}
int partition(int *a,int i,int j,int p)
{
int e,f,m,t;
e=i;
f=j;
m=p;
while(1)
{
//e=i;
while(e<j && a[e]<a[m]) e++;
//f=j;
while(f>i && a[f]>=a[m]) f--;
if(e<f)
{
t=a[e];
a[e]=a[f];
a[f]=t;
e++;
f--;
}
else
{
t=a[f];
a[f]=a[m];
a[m]=t;
break;
}
}
return f; 
}
void quicksort(int *a,int i,int j)
{
if(j<=i) return;
//int p=rPivot(i,j);
int p=i;
int k=partition(a,i,j,p);
quicksort(a,i,k);
quicksort(a,k+1,j);
}
int main()
{
int a[10],i;
for(i=0;i<10;i++)
{
scanf("%d",&a[i]);
}
quicksort(a,0,9);
for(i=0;i<10;i++)
{
printf("%d\n",a[i]);
}
return 0;
}