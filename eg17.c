#include<stdio.h>
int main(){
    int c;
    while(c = getchar() != '\n')
        printf("%s",c);
return 0;
}