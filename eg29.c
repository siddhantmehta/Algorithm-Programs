#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

long saveThePrisoner(long n, long m, long s){
    // Complete this function
    long t,i;
    t=m%n;
    if(t+s-1==0) return n;
    else return t+s-1;
}

int main() {
    int t; 
    scanf("%d", &t);
int a0;
    for(a0 = 0; a0 < t; a0++){
        long n; 
        long m; 
        long s; 
        scanf("%ld %ld %ld", &n, &m, &s);
        long result = saveThePrisoner(n, m, s);
        printf("%ld\n", result);
    }
    return 0;
}