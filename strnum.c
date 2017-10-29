#include<stdio.h>
int main()
{
int t;
scanf("%d",&t);
int i=0;
for(i=0;i<t;i++)
{
int n;
scanf("%d",&n);
int a[26];
int f;
for(f=0;f<26;f++)
{
a[f]=-1;
}
int j=0;
for(j=0;j<n;j++)
{
char o,p;
scanf("%c",&o);
scanf("%c",&p);
if(p>=97 && p<=122)
{
a[o-97]=p-97;
}
else
{
a[o-97]=p-48+26;
}
}
int k;
scanf("%d",&k);
int p=0;
char *b=(char *)malloc(sizeof(char)*512000);
for(p=0;p<k;p++)
{
scanf("%s",b);
int ii=0;
char c;
while(b[ii]!='\0')
{
replace(b[ii],a);
ii++;
}
}
}

return 0;
}
void replace(char t,char *a)
{
if(t>=97 && t<=122) 
{

}
else
{
}
}