#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int* solve(int grades_size, int* grades, int *result_size){

    // Complete this function
    *result_size=grades_size;
    int i,t;
    i=0;
t=0;
    while(i<grades_size)
    {
t=0;
        if(grades[i]<38)
{
i++;
continue;
} 
        if((grades[i]%5)==0)
        {
i++;
            continue;
        }
        else
        {
            t=grades[i]/5;
            if((((t+1)*5) - grades[i])<3)
            {
                grades[i]=(t+1)*5;
            }
            else
            {
i++;
                continue;
            }
        }
i++;
    }
    return grades;
}

int main() {
    int n; 
    scanf("%d", &n);
    int *grades = malloc(sizeof(int) * n);
int grades_i;
    for(grades_i = 0; grades_i < n; grades_i++){
       scanf("%d",&grades[grades_i]);
    }
    int result_size;
    int* result = solve(n, grades, &result_size);
int result_i;
    for(result_i = 0; result_i < result_size; result_i++) {
        if(result_i) {
            printf("\n");
        }
        printf("%d", result[result_i]);
    }
    puts("");
    

    return 0;
}