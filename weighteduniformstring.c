#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    char* s = (char *)malloc(512000 * sizeof(char));
    scanf("%s",s);
    int n; 
    scanf("%d",&n);
    int count[26];
    int a[26];
int i;
    for(i=0;i<26;i++)
    {
        count[i]=0;
        a[i]=i+1;
    }
i=0;
    while(s[i]!='\0')
    {
        count[s[i]-97]++;
        i++;
     }
int a0;
    for(a0 = 0; a0 < n; a0++){
        long x; 
        scanf("%ld",&x);
        long temp;
        // your code goes here
        for(i=0;i<26;i++)
        {
            if(count[i]!=0)
            {
                temp=count[i]*a[i];
                if(temp>=x)
                {
                    if(x%a[i]==0)
                    {
                        printf("Yes\n");
                        break;
                    }
                }
            }
        }
        if(i==26) printf("No\n");
    }
    return 0;
}
