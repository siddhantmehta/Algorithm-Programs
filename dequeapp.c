#include <stdio.h>
#include<string.h>
int findMin(int *a,int start,int end)
{
    int min=a[start];
    int i=start+1;
    while(i<=end)
    {
        if(min>a[i])
        {
            min=a[i];
        }
        i++;
    }
    return min;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n;
        scanf("%d",&n);
        int a[n];
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[j]);
        }
        int minElements[n][n];
        memset(minElements,-1,sizeof(minElements[0][0])*n*n);
        int temp,k;
        temp=0;
        for(int j=0;j<n;j++)
        {
            temp=j;
            for(int k=n-1;k>=j;k--)
            {
                minElements[j][temp]=findMin(a,j,k);
                //printf("%d ",minElements[j][temp]);
                temp++;
            }
            //printf("\n");
        }
        int j;
        long min,start,end,alphaValue,max=0;
        j=0;
        while(j<n)
        {
            start=j;
            end=n-1;
            min=minElements[j][n-(end-start+1)];
            alphaValue=min*(end-start+1);
            end--;
            while(end>=start)
            {
                min=minElements[j][n-(end-start+1)];
                temp=min*(end-start+1);
                if(alphaValue<temp)
                {
                    alphaValue=temp;
                }
                end--;
            }
            if(max<alphaValue)
            {
                max=alphaValue;
            }
            j++;
        }
        printf("%ld\n",max);
    }
    return 0;
}
