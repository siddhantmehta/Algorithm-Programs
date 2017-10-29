#include<stdio.h>
int main()
{
char ch;
printf("Press any key...");
ch=getch();
if(ch==122)
{
printf("\nascii code = %d",ch);
ch=getch();
printf("\nscan code = %d",ch);
}
else
{
printf("\nascii code = %d",ch);
}
return 0;
}