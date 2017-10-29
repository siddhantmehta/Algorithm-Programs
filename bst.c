#include<stdio.h>
#include<malloc.h>
struct Node
{
int number;
struct Node *left,*right,*parent;
};
struct Node *start=NULL;
void addNode(int num)
{
struct Node *t,*j;
t=(struct Node *)malloc(sizeof(struct Node));
t->number=num;
t->left=NULL;
t->right=NULL;
t->parent=NULL;
if(start==NULL)
{
start=t;
t->parent=NULL;
return;
}
j=start;
while(1)
{
if(t->number<j->number)
{
if(j->left==NULL)
{
j->left=t;
t->parent=j;
return;
}
else
{
j=j->left;
}
}
else
{
if(j->right==NULL)
{
j->right=t;
t->parent=j;
return;
}
else
{
j=j->right;
}
}
}
}
void removeNode(int num)
{
struct Node * t;
if(start==NULL)
{
printf("Node doesn't exits.");
return;
}
t=start;
while(t!=NULL)
{
if(t->number==num)
{
break;
}
else if(t->number>num)
{
t=t->left;
}//else if ends
else
{
t=t->right;
}//else ends
}//while ends
if(t==NULL)
{
printf("Node doesn't exists.");
return;
}
if(t->left==NULL && t->right==NULL)
{
if(t->number > t->parent->number)
{
t->parent->right=NULL;
free(t);
return;
}
else if(t->number<=t->parent->number)
{
t->parent->left=NULL;
free(t);
return;
}
}//if ends
//either the left or the right of node is not NULL
if(t->left!=NULL && t->right==NULL)
{
if(t->number>t->parent->number)
{
t->parent->right=t->left;
t->left->parent=t->parent;
free(t);
return;
}
else
{
t->parent->left=t->left;
t->left->parent=t->parent;
free(t);
return;
}
}//if ends

if(t->right!=NULL && t->left==NULL)
{
if(t->number>t->parent->number)
{
t->parent->right=t->right;
t->right->parent=t->parent;
free(t);
return;
}
else
{
t->parent->left=t->right;
t->right->parent=t->parent;
free(t);
return;
}
}//if ends

//both left and right nodes are not null
if(t->left!=NULL && t->right!=NULL)
{
struct Node *f=t->left;
while(f->right!=NULL)
{
f=f->right;
}

if(t->number>t->parent->number)
{
if(f->left==NULL && f->right==NULL)
{
t->parent->right=f;
f->left=t->left;
f->right=t->right;
f->parent->right=NULL;
f->parent=t->parent;
t->left->parent=f;
t->right->parent=f;
free(t);
return;
}

if(f->left!=NULL && f->right==NULL)
{
t->parent->right=f;
f->parent->right=f->left;
f->left=t->left;
f->right=t->right;
f->parent=t->parent;
t->left->parent=f;
t->right->parent=f;
free(t);
return;
}
}//if ends 

else
{
if(f->left==NULL && f->right==NULL)
{
t->parent->left=f;
f->left=t->left;
f->right=t->right;
f->parent->right=NULL;
f->parent=t->parent;
t->left->parent=f;
t->right->parent=f;
free(t);
return;
}

if(f->left!=NULL && f->right==NULL)
{
t->parent->left=f;
f->parent->right=f->left;
f->left=t->left;
f->right=t->right;
f->parent=t->parent;
t->left->parent=f;
t->right->parent=f;
free(t);
return;
}
}

}//if ends
}//removeNode ends

void inOrder(struct Node *t)
{
if(t==NULL) return;
inOrder(t->left);
printf("%d\n",t->number);
inOrder(t->right);
}
void preOrder(struct Node *t)
{
if(t==NULL) return;
printf("%d\n",t->number);
preOrder(t->left);
preOrder(t->right);
}
void postOrder(struct Node *t)
{
if(t==NULL) return;
postOrder(t->left);
postOrder(t->right);
printf("%d\n",t->number);
}
int main()
{
int ch,num,height,count;
while(1)
{
printf("1.Add node\n");
printf("2.Remove node\n");
printf("3.Pre-Order traverse\n");
printf("4.In-Order traverse\n");
printf("5.Post-Order traverse\n");
printf("6.Exit\n");
printf("Enter your choice:");
scanf("%d",&ch);
if(ch==1)
{
printf("Enter a number:");
scanf("%d",&num);
addNode(num);
}
if(ch==2)
{
printf("Enter a number you want to remove from tree:");
scanf("%d",&num);
removeNode(num);
}
if(ch==3)
{
preOrder(start);
}
if(ch==4)
{
inOrder(start);
}
if(ch==5)
{
postOrder(start);
}
if(ch==6)
{
break;
}
}
return 0;
}