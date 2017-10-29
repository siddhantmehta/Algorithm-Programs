#include<stdio.h>
#include<stdlib.h>
struct Node 
{
	int jobId;
	int startTime;
	int endTime;
};
void sort(struct Node *a[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]->endTime>a[j+1]->endTime)
			{
				struct Node * temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
int main()
{
	int n;
	printf("Enter the number of jobs:");
	scanf("%d",&n);
	struct Node *jobs[n];
	for(int i=0;i<n;i++)
	{
		jobs[i]=(struct Node*)malloc(sizeof(struct Node));
		printf("Enter job id :");
		scanf(" %d",&jobs[i]->jobId);
		printf("Enter start time :");
		scanf("%d",&jobs[i]->startTime);
		printf("Enter end time :");
		scanf("%d",&jobs[i]->endTime);
	}
	sort(jobs,n);
	/*for(int i=0;i<n;i++)
	{
		printf("%d %d %d \n",jobs[i]->jobId,jobs[i]->startTime,jobs[i]->endTime);
	}*/
	int count=1;
	struct Node *temp=jobs[0];
	printf("%d %d %d \n",jobs[0]->jobId,jobs[0]->startTime,jobs[0]->endTime);	
	for(int i=1;i<n;i++)
	{
		if(jobs[i]->startTime>=temp->endTime)
		{
			count++;
			temp=jobs[i];
			printf("%d %d %d \n",temp->jobId,temp->startTime,temp->endTime);	
		}
	}
	return 0;
}