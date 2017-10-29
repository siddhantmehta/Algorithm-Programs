#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left,*right;
};
struct Node *start;

void preOrder(struct Node *t)
{
    if(t==NULL) return;
    printf("%d\n",t->data);
    preOrder(t->left);
    preOrder(t->right);
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int n,a,b,front=-1,rear=-1;
    scanf("%d",&n);
    struct Node *queue[2*n];
    start=(struct Node*)malloc(sizeof(struct Node));
    start->data=1;
    start->left=NULL;
    start->right=NULL;
    queue[++rear]=start;
    struct Node *t,*j;
    front++;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a);
        scanf("%d",&b);
        if(front<=rear)
        {
            j=queue[front++];
        }
        if(a!=-1)
        {
            t=(struct Node*)malloc(sizeof(struct Node));
            t->data=a;
            t->left=NULL;
            t->right=NULL;
            queue[++rear]=t;
            j->left=t;
        }
        if(b!=-1)
        {
            t=(struct Node*)malloc(sizeof(struct Node));
            t->data=b;
            t->left=NULL;
            t->right=NULL;
            queue[++rear]=t;
            j->right=t;            
        }
    }
    int k;
    scanf("%d",&k);
    int test[k];
    for(int i=0;i<k;i++)
    {
        scanf("%d",&test[i]);
    }
    
    return 0;
}
