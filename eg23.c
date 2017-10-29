#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
// 07:05:45PM
// 19:05:45
char * timeConversion(char* s) {
    // Complete this function
char t;
int i,j;
if('P'==s[8])
{
i=(int)(s[0]-48);
j=(i*10)+(int)(s[1]-48);
printf("%d\n",j);
if(j==12) return s;
j=j+12;
i=j%10;
s[1]=i+48;
j=j/10;
s[0]=j+48;
s[8]='\0';
}
return s;
}

int main() {
    char* s = (char *)malloc(512000 * sizeof(char));
    scanf("%s", s);
        int result_size;
char * result=timeConversion(s);
printf("%s\n",result);
    return 0;
}