#include<stdio.h>
#include<malloc.h>
int main()
{
char *t=(char *)malloc(sizeof(char)*100);
scanf("%s",t);
printf("%s",t);
return 0;
}