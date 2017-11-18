#include<stdio.h>
#include<stdlib.h>
struct Node 
{
	int vertexNumber;
	char color;
	struct Node *next;
};
int top=-1;
void push(struct Node *t,struct Node **last)
{
	last[++top]=t;
}
struct Node *pop(struct Node **last)
{
	return last[top--];
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
	
	struct Node **deleted=(struct Node **)malloc(sizeof(struct Node)*n);
	temp=graph[0];
	push(temp,last);
	temp->color='B';
	deleted[0]=temp;
	t=temp->next;
	printf("One\n");
	int i=1;
	while(top!=-1)
	{
		if(t!=NULL)
		{
			while(t!=NULL)
			{
				if(graph[t->vertexNumber-1]->color=='R')
				{
					push(graph[t->vertexNumber-1],last);
					graph[t->vertexNumber-1]->color='B';
					deleted[i++]=graph[t->vertexNumber-1];
					break;
				}
				t=t->next;
			}
			if(t==NULL)
			{
				t=pop(last);
			}
			else
			{
				t=graph[t->vertexNumber-1]->next;
			}
		}
		else
		{
			t=pop(last);
		}

	}
	for (int i = 0; i < n; ++i)
	{
		printf("%d\n",deleted[i]->vertexNumber);
	}
	return 0;
}