#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int vertextNumber;
	struct Node *next;
};
int main()
{
	int n;
	scanf("%d",&n);
	struct Node **graph = (struct Node **)malloc(sizeof(struct Node)*n);
	struct Node **last = (struct Node **)malloc(sizeof(struct Node)*n);
	struct Node *temp = NULL,*t = NULL;
	for(int i=0;i<n;i++)
	{
		temp=(struct Node *)malloc(sizeof(struct Node));
		temp->vertextNumber=i+1;
		temp->next=NULL;
		graph[i]=temp;
		last[i]=temp;
	}
	int x,y;
	while(1)
	{
		scanf("%d %d",&x,&y);
		if(x==0 || y==0) break;
		temp=(struct Node *)malloc(sizeof(struct Node));
		temp->vertextNumber=y;
		temp->next=NULL;
		t=last[x-1];
		t->next=temp;
		last[x-1]=temp;
		temp=(struct Node *)malloc(sizeof(struct Node));
		temp->vertextNumber=x;
		temp->next=NULL;

		t=last[y-1];
		t->next=temp;
		last[y-1]=temp;
	}
	for(int i=0;i<n;i++)
	{
		t=graph[i];
		while(t!=NULL)
		{
			printf("%d ",t->vertextNumber);
			t=t->next;
		}
		printf("\n");
	}
	return 0;
}