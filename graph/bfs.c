#include<stdio.h>
#include<stdlib.h>
struct Node 
{
	int vertexNumber;
	char color;
	struct Node *next;
};
int rear,front;
void enqueue(struct Node *t, struct Node **last)
{
	last[++rear]=t;
	if(front==-1) front=0;
}
struct Node * dequeue(struct Node **last)
{
	struct Node *t=last[front];
	front++;
	return t;
}
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
		temp->vertexNumber=i+1;
		temp->color='R';
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
		temp->vertexNumber=y;
		temp->color='R';
		temp->next=NULL;
		t=last[x-1];
		t->next=temp;
		last[x-1]=temp;
		temp=(struct Node *)malloc(sizeof(struct Node));
		temp->vertexNumber=x;
		temp->color='R';
		temp->next=NULL;

		t=last[y-1];
		t->next=temp;
		last[y-1]=temp;
	}
	rear=-1;
	front=-1;
	struct Node **deleted=(struct Node **)malloc(sizeof(struct Node)*n);
	temp=graph[0];
	enqueue(temp,last);
	temp->color='Y';
	for (int i = 0; i < n; i++)
	{
		temp=dequeue(last);
		t=graph[temp->vertexNumber-1];
		while(t!=NULL)
		{
			if(graph[t->vertexNumber-1]->color=='R')
			{
				enqueue(graph[t->vertexNumber-1],last);
				graph[t->vertexNumber-1]->color='Y';
			}
			t=t->next;
		}
		graph[temp->vertexNumber-1]->color='B';
		deleted[i]=graph[temp->vertexNumber-1];
	}

	for (int i = 0; i < n; ++i)
	{
		/* code */
		printf("%d\n",deleted[i]->vertexNumber);
	}
	return 0;
}
