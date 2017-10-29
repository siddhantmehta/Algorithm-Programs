#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char *text,*pattern;
	text=(char *)malloc(sizeof(char)*512000);
	pattern=(char *)malloc(sizeof(char)*256000);
	scanf("%s",text);
	scanf("%s",pattern);
	int i,j,n,m;
	n=strlen(text);
	m=strlen(pattern);
	int prefix[m];
	i=1;
	j=0;
	prefix[0]=0;
	while(i<m)
	{
		if(pattern[j]!=pattern[i])
		{
			if(j>0)
			{
				j--;
				j=prefix[j];
				i--;
			}	
			else
			{
				prefix[i]=0;
			}
		}
		else
		{
			prefix[i]=j+1;
			j++;
		}
		i++;
	}
	i=0;
	j=0;
	int z=0;
	while(text[i]!='\0')
	{
		if(text[i]==pattern[j])
		{
			j++;
		}
		else
		{
			if(j>0)
			{
				j--;
				j=prefix[j];
				i--;
			}
		}
		if(j==m)
		{
			z=1;
			printf("YES at index %d\n",i-m+1);
			j--;
			j=prefix[j];
			
		}	
		i++;
	}
	if(z==0) printf("NO\n");
	return 0;
}