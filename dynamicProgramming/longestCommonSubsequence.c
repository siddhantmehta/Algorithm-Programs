#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char *s,*t;
	s=(char *)malloc(sizeof(char)*100000);
	t=(char *)malloc(sizeof(char)*100000);
	printf("Enter first string:");
	scanf("%s",s);
	printf("Enter secong string:");
	scanf("%s",t);
	int lens,lent;
	lens=strlen(s);
	lent=strlen(t);
	int dpTable[lent+1][lens+1];
/*	for(int i=0;i<lens;i++)
	{
		if(t[0]==s[i])
		{
			dpTable[0][i]=1;
		}
		else
		{
			dpTable[0][i]=0;
		}
	}
	for(int i=1;i<lent;i++)
	{
		if(s[0]==t[i])
		{
			dpTable[i][0]=1;
		}
		else
		{
			dpTable[i][0]=0;
		}
	}*/
	for(int i=0;i<lens+1;i++)
	{
		dpTable[0][i]=0;
	}
	for (int i = 0; i < lent+1; ++i)
	{
		dpTable[i][0]=0;
	}
	int i,j;
	i=1;
	j=1;
	while(i<lent+1)
	{
		j=1;
		while(j<lens+1)
		{
			if(s[j-1]==t[i-1])
			{
				dpTable[i][j]=1+dpTable[i-1][j-1];
			}
			else
			{
				if(dpTable[i-1][j]>dpTable[i][j-1])
				{
					dpTable[i][j]=dpTable[i-1][j];
				}
				else
				{
					dpTable[i][j]=dpTable[i][j-1];
				}
			}
			j++;
		}
		i++;
	}
	for(i=0;i<lent+1;i++)
	{
		for(j=0;j<lens+1;j++)
		{
			printf("%d ",dpTable[i][j]);
		}
		printf("\n");
	}
	printf("Length of longest common subsequence :%d\n",dpTable[lent][lens]);
	char *subsequence=(char *)malloc(sizeof(char)*dpTable[lent][lens]+1);
	i=lent;
	j=lens;
	int temp=3;
	subsequence[dpTable[lent][lens]]='\0';
	while(i>0 || j>0)
	{
		if(s[j-1]==t[i-1])
		{
			subsequence[temp]=s[j-1];
			temp--;
			i--;
			j--;
		}
		else
		{
			if(dpTable[i-1][j]>dpTable[i][j-1])
			{
				i=i-1;
			}
			else
			{
				j=j-1;
			}
		}
	}
	printf("%s\n",subsequence);
	return 0;
}