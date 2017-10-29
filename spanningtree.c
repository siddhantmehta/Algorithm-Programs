#include <stdio.h>
#include<string.h>
int g=0;
void sort(int *b,int n)
{
int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(b[j]>b[j+1])
            {
                int t=b[j];
                b[j]=b[j+1];
                b[j]=t;
            }
        }
    }
}

void findNeighbor(int a[g][3],int n,int temp[g][2],int t)
{
    int i,j=0;
    for(i=0;i<n;i++)
    {
        if(a[i][0]==t)
        {
            temp[j][0]=a[i][1];
            temp[j][1]=a[i][2];
            j++;
        }
    }
}

int main()
{
    printf("sdfsdfsdf\n");
    int n,m;
    scanf("%d",&n);
    scanf("%d",&m);
    g=m;
    int a[m][3];
	int i;
    for(i=0;i<m;i++)
    {
        scanf("%d",&a[i][0]);
        scanf("%d",&a[i][1]);
        scanf("%d",&a[i][2]);
    }
    int q;
    scanf("%d",&q);
    int b[q];
    for(i=0;i<q;i++)
    {
        scanf("%d",&b[i]);
    }
        printf("sdfsdfweq\n");
/*    for(int i=0;i<m;i++)
    {
        printf("%d %d %d\n",a[i][0],a[i][1],a[i][2]);
    }
    */
        printf("sdfsdf\n");
    sort(b,q);
    int temp[m][2];
    memset(temp,-1,sizeof(temp[0][0])*m*2);
    int result[n];
    int cost[n];
    for(i=0;i<n;i++)
    {
        result[i]=-1;
        cost[i]=0;
    }
    for(i=0;i<n;i++)
    {
        findNeighbor(a,m,temp,i+1);
/*        for(int k=0;k<m;k++)
        {
            printf("%d %d\n",temp[k][0],temp[k][1]);
        }
*/
        result[i]=i+1;
        int j=0;
        while(temp[j][0]!=-1)
        {
            if(result[temp[j][0]-1]==-1)
            {
                result[temp[j][0]-1]=temp[j][0];
                cost[temp[j][0]-1]=temp[j][1];
            }
            else
            {
                if(cost[temp[j][0]-1]>temp[j][1])
                {
                    cost[temp[j][0]-1]=temp[j][1];
                }
            }
            j++;
        }
    }
    sort(cost,n);
    int j=0,sum=0;
    for(i=n-1;i>0;i--)
    {
        if(cost[i]>b[j])
        {
            cost[i]=b[j];
            j++;
        }
        sum=sum+cost[i];
    }
    printf("%d\n",sum);
    return 0;
}
