#include <stdio.h>

#define convertToString(a) #a

#define merge(a, b) a##b

int main()

{
    
char *s=convertToString(Hello);
    
printf("%s\n",s);
printf("%s ", merge(A,B));
return 0;

}