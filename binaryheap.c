#include<stdio.h>
#define N 100000

int heap[N];
int count=0;

int main()
{
	int ch;
	while(1)
	{
	printf("1. Add a number to heap\n");
	printf("3. Exit\n");
	printf("Enter your choice:");
	scanf("%d",&ch);
	if(ch==1)
	{
		int x;
		char c;
		printf("Enter a number :");
		scanf("%d",&x);
		printf("Enter a character :");
		scanf("%c",&c);
		printf("%d %c\n",x,c);
	}
	if(ch==3)
	{
		break;
	}
	}
	return 0;
}