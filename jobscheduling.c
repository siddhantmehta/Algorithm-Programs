#include<stdio.h>
#include<stdlib.h>

struct Node
{
	char jobId;
	int deadline;
	int profit;
};

void sort(struct Node **jobs,int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(jobs[j]->profit<jobs[j+1]->profit)
			{
				struct Node *t=jobs[j];
				jobs[j]=jobs[j+1];
				jobs[j+1]=t;
			}
		}
	}
}

int main()
{
	int n;
	printf("Enter number of jobs:");
	scanf("%d",&n);
	struct Node *jobs[n];
	int i;
	for(i=0;i<n;i++)
	{
		jobs[i]=(struct Node*)malloc(sizeof(struct Node));
		printf("Enter job id :");
		scanf(" %c",&jobs[i]->jobId);
		printf("Enter deadline :");
		scanf("%d",&jobs[i]->deadline);
		printf("Enter profit :");
		scanf("%d",&jobs[i]->profit);
	}
	sort(jobs,n);
	int t=-1,sum=0,z=0;
	struct Node *temp[n-1];
	for(i=0;i<n-1;i++) temp[i]=NULL;
	for(i=0;i<n;i++)
	{
		//printf("%d %d\n", jobs[i]->deadline,jobs[i]->profit);
		if(jobs[i]->deadline-1>=n-1)
		{
			if(temp[n-2]==NULL)
			{
				temp[n-2]=jobs[i];
				printf("%c\n",jobs[i]->jobId);
				sum=sum+jobs[i]->profit;
			}
			continue;
		}
		if(temp[jobs[i]->deadline-1]!=NULL)
		{
			//printf("Two\n");
			t=jobs[i]->deadline-1;
			while(t>=0)
			{
				//printf("Three\n");
				if(temp[t]==NULL)
				{
					z=1;
					break;
				}
				t--;
			}
			if(z==1)
			{
				temp[t]=jobs[i];
				printf("%c\n",jobs[i]->jobId);
				sum=sum+jobs[i]->profit;
				z=0;
			}
		}
		else
		{
			//printf("ONe\n");
			temp[jobs[i]->deadline-1]=jobs[i];
			printf("%c\n",jobs[i]->jobId);
			sum=sum+jobs[i]->profit;
		}
	}
	printf("Sum %d\n",sum);
/*	for(i=0;i<n;i++)
	{
		printf("%c %d %d\n",jobs[i]->jobId,jobs[i]->deadline,jobs[i]->profit);
	}
*/	
	return 0;
}