#include <stdio.h>
#include <stdlib.h>

struct node{
	int key;
	char* color;
	struct node *left, *right, *parent;
	} *root;

//Left Rotate

void LeftRotate(struct node *x)
{
	struct node *y;
	y = (struct node *)malloc(sizeof(struct node));
	y = x->right;
	x->right = y->left;
	if (y->left != NULL)
		y->left->parent = x;
	y->parent = x->parent;
	if (x->parent == NULL)
		root = y;
	else if (x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;
	y->left = x;
	x->parent = y;
}

//Right Rotate

void RightRotate(struct node *y)
{
	struct node *x;
	x = (struct node *)malloc(sizeof(struct node));
	x = y->left;
	y->left = x->right;
	if (x->right != NULL)
		x->right->parent = y;
	x->parent = y->parent;
	if (y->parent == NULL)
		root = x;
	else if (y == y->parent->left)
		y->parent->left = x;
	else
		y->parent->right = x;
	x->right = y;
	y->parent = x;
}

void RBDisplay(struct node *temp)
{
	if (temp != NULL)
	{
		RBDisplay(temp->left);
		printf("%d\t %s\n", temp->key, temp->color);
		RBDisplay(temp->right);
	}
}

void RBInsertFixup(struct node *z)
{
	struct node *y;
	y = (struct node *)malloc(sizeof(struct node));
	
	while ((z->parent != NULL) && (z->parent->color == "RED"))
	{
		if ((z->parent) == (z->parent->parent->left))
		{
			y = (z->parent->parent->right);
			if ((y != NULL) && (y->color == "RED"))
			{
				z->parent->color = "BLACK";
				y->color = "BLACK";
				z->parent->parent->color = "RED";
				z = z->parent->parent;
			}
			else 
			{
				if (z == z->parent->right)
				{
					z = z->parent;
					LeftRotate(z);
				}
				if (z->parent != NULL)
				{
					z->parent->color = "BLACK";
					if (z->parent->parent !=NULL)
					{
						z->parent->parent->color = "RED";
					}
				}
				if ((z->parent != NULL) && (z->parent->parent != NULL))
				{
					RightRotate(z->parent->parent);
				}
			}
		}	
		else
		{
			y = (z->parent->parent->left);
			if ((y != NULL) && (y->color == "RED"))
			{
				z->parent->color = "BLACK";
				y->color = "BLACK";
				z->parent->parent->color = "RED";
				z = z->parent->parent;
			}
			else 
			{
				if (z == z->parent->left)
				{
					z = z->parent;
					RightRotate(z);
				}
				if (z->parent != NULL)
				{
					z->parent->color = "BLACK";
					if (z->parent->parent !=NULL)
					{
						z->parent->parent->color = "RED";
					}
				}
				if ((z->parent != NULL) && (z->parent->parent != NULL))
				{
					LeftRotate(z->parent->parent);
				}
			}			
		}		
	}
	root->color = "BLACK";
}

void RBInsert(int num)
{
	struct node *y, *x, *z;
	z = (struct node *)malloc(sizeof(struct node));
	y = (struct node *)malloc(sizeof(struct node));
	x = (struct node *)malloc(sizeof(struct node));
	z->key = num;
	y = NULL;
	x = root;
	while(x != NULL)
	{
		y = x;
		if ((z->key) < (x->key))
			x = x->left;
		else
			x = x->right;
	}
	z->parent = y;
	if (y == NULL)
	{
		root = z;
	}
	else if ((z->key) < (y->key))
		y->left = z;
	else 
		y->right = z;
	z->left = NULL;
	z->right = NULL;
	z->color = "RED";
	RBInsertFixup(z); 
}

void findPred(struct node *x)
{
	int valuePred;
	if(x->right == NULL)
	{
		if(x->color == "RED")
		{
			printf("The red predecessor is %d\n", x->key);
			return;
		}
	}
	while( x->right != NULL)
	{
		if(x->color == "RED")
		{
			valuePred = x->key;
		}
		x = x->right;
	}
/*	if(valuePred == 1234)
	{
		printf("No red predecessor\n");
	}*/
	printf("The red predecessor is %d\n", valuePred);
	return;
}

void predecessor(struct node *temp, int num)
{
	while(temp!=NULL)
	{
		if((temp->key) == num)
		{
			if(temp->left == NULL)
			{
				if((temp->parent)== NULL)
				{
					predecessor((temp->left), temp->key);
					return;					
				}
				temp = temp->parent;
				predecessor((temp->right), temp->key);
				//printf("%d", temp->key);
			}
			findPred(temp->left);
			return;
		}
		else if((temp->key) < num)
		{
			temp = temp->right;
		}
		else
		{
			temp = temp->left;
		}
	}
	//printf("Could not find red predecessor\n");
}

int main()
{
	int opt, num;
	root = NULL;
	while (1)
	{
		printf("1. Insert\n");
		printf("2. Find the Red Predecessor\n");
		printf("3. Display\n");
		printf("4. Exit\n");
		printf("Enter the option:");
		scanf("%d", &opt);
		if (opt == 1)
		{
			printf("Inserting node\n");
			printf("Enter the node be inserted:");
			scanf("%d", &num);
			RBInsert(num);
		}
		else if (opt == 2)
		{
			printf("Enter the number to find its red predeseccor:");
			scanf("%d", &num);
			predecessor(root, num);
		}
		else if (opt == 3)
		{
			printf("Displaying\n");
			RBDisplay(root);
		}
		else if (opt == 4)
		{
			exit(0);
		}
		else 
		{
			printf("Invalid option\n");
		}
	}
	return 0;
}
