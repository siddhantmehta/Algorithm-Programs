#include <stdio.h>
#include <stdlib.h>
void mostFreq3(int *a, int n, int b[3]) {

// Write your code here
// hint: sort a, find biggest 3 blocks	
  int t,i,j;
  for(i=0; i<n-1; i++)
  {
    for(j=0;j<n-i-1;j++)
    {
      if(a[j]>a[j+1])
      {
        t=a[j];
        a[j]=a[j+1];
        a[j+1]=t;
      }
    }
  }
  t=a[0];
  int d[n][2],count;
  j=0;
  for(i=1; i<n; i++)
  {
    count=1;
    if(t==a[i])
    {
      while(t==a[i])
      {
        count++;
        i++;
      }
      d[j][0]=a[i-1];
      d[j][1]=count;
      j++;
    }
    t=a[i];
  }
t=a[i-1];
if(d[j-1][0]!=a[i-1]) 
{
d[j][0]=a[i-1];
d[j][1]=1;
j++;
}
for(i=0;i<j;i++) printf("%d  %d\n",d[i][0],d[i][1]);
	int index=0,max,p;
  for(i=0;i<3;i++)
  {
    max=0;
	index=0;
    for(p=0; p<j; p++)
    {

      if(d[p][1] > max)
      {
        max= d[p][1];
        index=p;
      }
    }
    b[i]=d[index][0];
    d[index][1]=0;
  }
}


int main()
{
	int n;
	int a[100];
	int b[3];
	int i=0;

	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}

	mostFreq3(a,n,b);
        for(i=0; i<3; i++)
            printf("%d ", b[i]);

	return 0;
}