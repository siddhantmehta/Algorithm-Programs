#include<stdio.h>
struct abc
{
char c1;
};
int main()
{
/*char c;
printf("%d\n",sizeof(c));
struct abc i;
printf("%d\n",sizeof(struct abc));
*/
char *name[]={"adsf","werioe","oowwqlsk"};
printf("%s",*(name+1));
return 0;
}