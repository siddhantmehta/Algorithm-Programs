#include<stdio.h>
#include<malloc.h>
int main()
{
int n,k,i;
char *s;
char t;
scanf("%d",&n);
if(n<1 && n>100) return;
s=(char *)malloc((n+1)*sizeof(char));
scanf("%s",s);
scanf("%d",&k);
if(k<0 && k>100) return;
k=k%26;
for(i=0;i<n;i++)
{
if((s[i]<65)||(s[i]>90 && s[i]<97)||(s[i]>122)) continue;
if(s[i]>=65 && s[i]<=90)
{
s[i]=s[i]+k;
printf("%c----%d\n",s[i],s[i]);
if(s[i]>90) s[i]=s[i]-26;
}
else
{
printf("Lower Before---%c----%d\n",s[i],s[i]);
s[i]=s[i]+k;
printf("Lower after addition ---- %c----%d\n",s[i],s[i]);
if(s[i]>122) {s[i]=s[i]-26;printf("Lower after adjustment ---- %c----%d\n",s[i],s[i]);}
}
}
t='Ç';
printf("%d-----%c-----size---%d",t,t,sizeof(char));
printf("sdfsdf----%c----%d \n ",128,(t<122));
printf("%s",s);
return 0;
}