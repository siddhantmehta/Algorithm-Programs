#include<stdio.h>
#include<malloc.h>
int main()
{
int ed,em,ey,ad,am,ay,i,j,fine;
scanf("%d %d %d",&ad,&am,&ay);
scanf("%d %d %d",&ed,&em,&ey);	
if((ed<0 && ed>31) || (ad<0 && ad>31)) return;
if((em<0 && em>12) || (am<0 && am>12)) return;
if((ey<0 && ey>3000) || (ay<0 && ay>3000)) return;
fine=0;
if(ay<=ey || am<=em || ad<=ed)
{
fine=0;
}
else
{
if(ad>=ed && am<=em && ay<=ey)
{
fine=15*(ad-ed);
}
else
{
if(am>=em && ay<=ey)
{
fine=500*(am-em);
}
else
{
fine=10000;
}
}
}
printf("%d",fine);
return 0;
}