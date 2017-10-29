#include<stdio.h>
#include<malloc.h>
#include<string.h>
int main()
{
	char **a=(char **)malloc(sizeof(char)*120);
	int i=0,dictionarySize=0,z=0,p=0,len1,len2,len,count=0;
	char *str1,*str2;
	while(1)
	{
		char *t=(char *)malloc(sizeof(char)*40);
		scanf("%s",t);
		if(strcmp(t,"END")==0) break;
		a[i]=t;
		i++;
		dictionarySize++;
	}

	str1=(char *)malloc(sizeof(char)*10000);
	str2=(char *)malloc(sizeof(char)*10000);
	scanf("%s",str1);
	scanf("%s",str2);
	for(p=0;p<dictionarySize;p++)
	{
		if(strcmp(a[p],str2)==0) 
		{
			z=1;
			break;
		}
	}
	if(z==0)
	{
		printf("-1");
		return 0;
	}
	len1=strlen(str1);
	len2=strlen(str2);
	if(len1>len2) len=len2;
	else
		{
			z=1;
			len=len1;
		}
	while(p<len)
	{
		if(str1[p]==str2[p])
		{
			p++;
			continue;
		}
		str1[p]=str2[p];
		count++;
		int oo=0;
		for(oo=0;oo<dictionarySize;oo++)
		{
			if(strcmp(a[oo],str1)==0)
			{
				z=1;
				break;
			}
		}
		if(z==0) 
		{
			printf("-1");
			return 0;
		}
		p++;
	}
	if(len1>len2)
	{
		str1[len2-len1]='\0';
		count+=len2-len1;
	}
	else
	{
		while(p<len2)
		{
			str1[p]=str2[p];
			count++;
			p++;
		}
		str1[p]='\0';
	}
	for(p=0;p<dictionarySize;p++)
	{
		if(strcmp(a[p],str1)==0) 
		{
			z=1;
			break;
		}
	}
	if(z==1)
	{
		printf("%d\n",count);
	}
	else
	{
		printf("-1");
	}
	return 0;
}