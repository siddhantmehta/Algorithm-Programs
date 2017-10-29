#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int s; 
    int t; 
    scanf("%d %d",&s,&t);
    if(s<1 || s>100000) return 0;
    if(t<1 || t>100000) return 0;
    if(s>=t) return 0;
    int a; 
    int b; 
    scanf("%d %d",&a,&b);
    if(a<1 || a>100000) return 0;
    if(b<1 || b>100000) return 0;
    if(a>=b) return 0;
    if(a>s>t>b) return 0;
    int m; 
    int n; 
    scanf("%d %d",&m,&n);
    if(m<1 || m>100000) return 0;
    if(n<1 || n>100000) return 0;
    int *apple = malloc(sizeof(int) * m);
    for(int apple_i = 0; apple_i < m; apple_i++){
       scanf("%d",&apple[apple_i]);
        if(apple[apple_i]<-100000 || apple[apple_i]>100000) return 0;
    }
    int *orange = malloc(sizeof(int) * n);
    for(int orange_i = 0; orange_i < n; orange_i++){
       scanf("%d",&orange[orange_i]);
        if(orange[orange_i]<-100000 || orange[orange_i]>100000) return 0;
    }
    long i,z,aCount,oCount;
    aCount=0;
    i=0;
    z=0;
    while(i<m)
    {
        z=a+apple[i];
        if(z>=s && z<=t) aCount++;
        i++;
    }
    i=0;
    z=0;
    oCount++;
    while(i<n)
    {
        z=b+apple[i];
        if(z>=s && z<=t) oCount++;
        i++;
    }
    printf("%ld\n",aCount);
    printf("%ld",oCount);
    return 0;
}
