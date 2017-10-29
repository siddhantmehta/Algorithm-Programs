#include<stdio.h>
/*int findMajorityElement(int* arr, int size) { 
    int count = 0, i, majorityElement;
    for (i = 0; i < size; i++) {
        if (count == 0)
            majorityElement = arr[i];
        if (arr[i] == majorityElement) 
            count++;
        else
            count--;
    }
    count = 0;
    for (i = 0; i < size; i++)
        if (arr[i] == majorityElement)
            count++;
    if (count > size/2)
        return majorityElement;
    return -1;
}*/
int main()
{
int arr[]={2,3,3,5,7,4,3,1};
int n=8;
printf("%d\n",majorityElement(arr,n));
return 0;
}