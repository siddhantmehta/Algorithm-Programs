#include<stdio.h>
int main()
{
/*int a[2][3][2]={{{1,2},{9,8},{3,7}},{{2,2},{1,4},{5,4}}};
printf("%d %d %d",(a[1]-a[0]),(a[1][0]-a[0][0]),(a[1][0][0]-a[0][0][0]));
*/
int p,i,q;
p=2;
q=2;
for(i=0;i<4;i++)
{
p<<1;
q=p+i;
}
printf("%d %d",p,q);
return 0;
}