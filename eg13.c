#include<stdio.h>
#include<malloc.h>
int main()
{
int a[]={1,2,3,4,5};
int *ptr=(int *)(&a+1);
printf("%d\n",&a+2);
printf("%d %u",(ptr-1),&a[1]);
printf("%d %d",*(a+1),*(ptr-1));
return 0;
}
