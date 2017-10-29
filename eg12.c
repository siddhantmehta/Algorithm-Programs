#include<stdio.h>

int main()
{
char p[]= "me";
int i;
for(i=0;p[i];i++)
printf("%c%c%c%c",p[i],*(i+p),*(p+i),i[p]);
return 0;
}
int main()
{
char *p;
p="Hello";
printf("%c\n",*&*p);
return 0;
}

int main()
{
int i=4,j=2;
int *p=&i, *q=&j;
int k=*p/*q;
printf("%d\n",k);
return 0;
}


int main()
{
int a[2][3][2]={{{1,2},{9,8},{3,7}},{{2,2},{1,4},{5,4}}};
printf("%d %d %d\n",a[1]-a[0],a[1][0]-a[0][0],a[1][0][0]-a[0][0][0]);
return 0;
}


#include<stdio.h>
#define char double
int main()
{
char i=97;
printf("%d",sizeof(i));
return 0;
}

/*Run the below code with commented line and then uncomment it and again run*/
#include<stdio.h>
//#define char int
int main()
{
char i=128;
printf("%c %d\n",i,(i>122));
printf("%d",sizeof(i));
return 0;
}


#include<stdio.h>
#define square(x) x*x
int main()
{
int i,t;
t=square(4);
printf("%d\n",t);
i=8/square(4);
printf("%d\n",i);
return 0;
}