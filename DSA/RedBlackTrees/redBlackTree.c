/* Red Black Trees for insertion and deletion */

#include <stdio.h>
#include <stdlib.h>

struct node{
	int key, size;
	char* color;
	struct node *left, *right, *parent;
	} *root;

/**********************************Rotate******************************************************************************************/

//Left Rotate

void LeftRotate(struct node *x)
{
	struct node *y;
	y = (struct node *)malloc(sizeof(struct node));
	y = x->right;			//set y
	x->right = y->left;		//turn y's left subtree into x's right subtree
	if (y->left != NULL)
		y->left->parent = x;
	y->parent = x->parent;		//link x's parent to y
	if (x->parent == NULL)
		root = y;
	else if (x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;
	y->left = x;			//put x on y's left
	x->parent = y;
  	x->size = 1 + x->left->size + x->right->size;
  	y->size = 1 + y->left->size + y->right->size;
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
  	x->size = 1 + x->left->size + x->right->size;
  	y->size = 1 + y->left->size + y->right->size;
}
/**********************************Rotate Ends*************************************************************************************/

/**********************************Display*****************************************************************************************/

//Inorder traversal
void RBDisplay(struct node *temp)
{
	if (temp != NULL)
	{
		RBDisplay(temp->left);
		printf("%d\t %s\t %d\n", temp->key, temp->color, temp->size);
		RBDisplay(temp->right);
	}
}

/**********************************Display Ends************************************************************************************/

/**********************************Delete******************************************************************************************/

void RBDeleteFixup(struct node *x)
{

	struct node *w;
	while((root != x) && (x->color == "BLACK"))
	{
		if(x == x->parent->left)
		{
			w = x->parent->right;     

			if(w->color == "RED")            
			{
				w->color = "BLACK";       
				x->parent->color = "RED";    
				LeftRotate(x->parent);
				w = x->parent->right;      

			}
			if((w->left->color == "BLACK") && (w->right->color == "BLACK"))            
			{
				w->color = "RED";          
				x = x->parent;          
			}
			else                  
			{
				if(w->right->color == "BLACK") 
				{
					w->left->color = "BLACK";            
					w->color = "RED";                
					RightRotate(w);           
					w = x->parent->right;           
				}
				
			
				
				w->color = x->parent->color;             
				w->right->color = "BLACK";                 
				x->parent->color = "BLACK";           
				LeftRotate(w);
				x = root;                   
			}
		}
		else       
		{
			w = x->parent->left;
			if(w->color == "RED")             
			{
				w->color = "BLACK";
				x->parent->color = "RED";
				RightRotate(x->parent);
				w = x->parent->left;   
			}
			if((w->right->color == "BLACK") && (w->left->color == "BLACK"))    
			{
				w->color = "RED";
				x = x->parent;
			}
			else 
			{
				if(w->left->color == "BLACK")         
				{
					w->right->color = "BLACK";
					w->color = "RED";
					LeftRotate(w);
					w = x->parent->left;
				}

				

				w->color = x->parent->color;
				w->left->color = "BLACK";
				x->parent->color = "BLACK";
				RightRotate(w);
				x = root;
			}

		
		}
	}

	x->color = "BLACK"; 
}

void RBTransplant(struct node *u, struct node *v)
{
	if (u->parent == NULL)
		root = v;
	else if (u == u->parent->left)
		u->parent->left = v;
	else
		u->parent->right = v;
	if(v != NULL)
		v->parent = u->parent;
}

struct node TreeMin(struct node *x)
{
	//x->size=x->size-1;
	while( x->left != NULL)
	{
		x = x->left ;
    		//x->size=x->size-1;
	}
	return *x;

}

void RBDelete(int key)
{
	struct node *z, *temp, *y, *x;
	z = (struct node *)malloc(sizeof(struct node));	
	temp = root;
	while(temp != NULL)
	{
		if(key == temp->key)
		{
			z = temp;
			break;
		}
		else
		{
			if(key > temp->key)
			{
				temp = temp->right;
			}
			else
			{
				temp = temp->left;
			}
		}
	}

	y = z;
	char* yOriginalColor = y->color;
	if (z->left == NULL)
	{
		x = z->right;
		RBTransplant(z, z->right);
	}
	else if(z->right == NULL)
	{
		x = z->left;
		RBTransplant(z, z->left);	
	}
	else
	{
		*y = TreeMin(z->right);
		yOriginalColor = y->color;
		x = y->right;
		if ((y->parent == z) && (x != NULL))
			x->parent = y;
		else
		{
			RBTransplant(y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}
		RBTransplant(z,y);
		y->left = z->left;
		y->left->parent = y;
		y->color = z->color;
    		//y->size=y->size-1;
	}
	if ((yOriginalColor == "BLACK") && (x != NULL)) 
		RBDeleteFixup(x);

	temp = y;
	while(temp!=NULL)
	{
		//printf("Checking\n");
		if((temp->left == NULL) && (temp->right == NULL))
		{
			temp->size = 1;
			temp = temp->parent;
			continue;
		}
		if((temp->left == NULL) && (temp->right != NULL))
		{
			temp->size = 1 + temp->right->size;
			temp = temp->parent;
			continue;
		}
		if((temp->right == NULL) && (temp->left != NULL))
		{
			temp->size = 1 + temp->left->size;
			temp = temp->parent;
			continue;
		}
		temp->size = 1 + temp->left->size + temp->right->size;
		temp = temp->parent;
	}
}

/**********************************Delelte Ends************************************************************************************/

/**********************************Insert******************************************************************************************/

void RBInsertFixup(struct node *z)
{
	struct node *y;
	y = (struct node *)malloc(sizeof(struct node));
	
	while ((z->parent != NULL) && (z->parent->color == "RED"))
	{
		if ((z->parent) == (z->parent->parent->left))
		{
			y = (z->parent->parent->right);
			if ((y != NULL) && (y->color == "RED"))		//this is for case 1
			{
				z->parent->color = "BLACK";
				y->color = "BLACK";
				z->parent->parent->color = "RED";
				z = z->parent->parent;
			}
			else 
			{
				if (z == z->parent->right)//this is case 2. where the z is the right child of parent. R(child) <-> L(rotate)
				{
					z = z->parent;
					LeftRotate(z);
				}
				if (z->parent != NULL)
				{
					z->parent->color = "BLACK";			//case 3
					if (z->parent->parent !=NULL)
					{
						z->parent->parent->color = "RED";	//case 3
					}
				}
				if ((z->parent != NULL) && (z->parent->parent != NULL))
				{
					RightRotate(z->parent->parent);			//case 3
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
	struct node *y, *x, *z, *temp;
	z = (struct node *)malloc(sizeof(struct node));
	y = (struct node *)malloc(sizeof(struct node));
	x = (struct node *)malloc(sizeof(struct node));
	temp = (struct node *)malloc(sizeof(struct node));
	z->key = num;
	z->size = 1;
	y = NULL;
	x = root;
	while(x != NULL)
	{
		y = x;
		if ((z->key) < (x->key))
			x = x->left;
		else
			x = x->right;
		//y->size=y->size+1;
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
	temp = z;
	while(temp!=NULL)
	{
		//printf("Checking\n");
		if((temp->left == NULL) && (temp->right == NULL))
		{
			temp->size = 1;
			temp = temp->parent;
			continue;
		}
		if((temp->left == NULL) && (temp->right != NULL))
		{
			temp->size = 1 + temp->right->size;
			temp = temp->parent;
			continue;
		}
		if((temp->right == NULL) && (temp->left != NULL))
		{
			temp->size = 1 + temp->left->size;
			temp = temp->parent;
			continue;
		}
		temp->size = 1 + temp->left->size + temp->right->size;
		temp = temp->parent;
	}
	RBInsertFixup(z); 
}

/**********************************Insert Ends*************************************************************************************/

/**********************Find rank of Given number**********************************************************************************/

void findRank(struct node *x, int num)
{
	int rank=0;
	while(x!=NULL)
	{
		if(num==x->key)
		{
			if(x->right == NULL)
			{
				break; 
			}
			rank=rank+x->right->size;
			break;
		}
		else if(num>x->key)
		{
			if(x->right == NULL)
			{
				break; 
			}
			x=x->right;
		}
		else
		{
			if((x->right == NULL) || (x->left == NULL) )
			{
				break; 
			}
			rank=rank+x->right->size+1;
			x=x->left;
		}
	}
	printf("The rank of the number is %d\n", rank+1);
	return;
}

/*****************Find rank of Given number Ends**********************************************************************************/

/********************Find number of given rank********************************************************************************************/

void findNum(struct node *x, int rank)
{
	int r;
	//printf("%d\n", x->key); 
	while(x!=NULL)
	{
		//printf("Checking\n");
		if(x->right == NULL)
		{
			printf("The number is %d\n", x->key);
			return; 
		}
		r=x->right->size+1;
		if(r==rank)
		{
			printf("The number is %d\n", x->key);
			return;
		}
		else if(r>rank)
		{
			if(x->right == NULL)
			{
				printf("The number is %d\n", x->key);
				return; 
			}
			x=x->right;
		}
		else
		{
			if(x->left == NULL)
			{
				printf("The number is %d\n", x->key);
				return; 
			}
			rank=rank-r;
			x=x->left;
		}
	}
	printf("Can't find\n");
	return;
}

/*******************Find number of given rank Ends***************************************************************************************/

/************************************************Prefix Sum******************************************************************************/

int add(struct node *temp)
{
	if (temp == NULL)
		return 0;
	//printf("%d\t", temp->key);
	return  add(temp->left) + (temp->key) + add(temp->right) ;

}

void prefixSum(int num)
{
	struct node *temp;
	temp = root;
	while(temp!=NULL)
	{
		if(num == (temp->key))
		{
			int sum = (temp->key) + add(temp->left);
			printf("The prefix sum is %d\n", sum);
			return;
		}
		else if(num < (temp->key))
		{
			temp = temp->left;
		}
		else
		{
			temp = temp->right;
		}
	}	
}

/************************************************Prefix Sum Ends************************************************************************/

/************************************************Minimum in range***********************************************************************/

/*
void nextPrint(struct node *x, int Lnum, int Hnum)
{
	while(x!=NULL)
	{
		if((x->key) < Hnum)
		{
			printf("%d\t", x->key);
		}
		x = x->left;
	}
}

void print(struct node *x, int Lnum, int Hnum)
{
	while(x!=NULL)
	{
		if((x->key) < Hnum)
		{
			printf("%d\t", x->key);
		}
		x = x->left;
	}
	struct node *y;
	if (x->parent == root)
	{
		nextPrint((y->right), Lnum, Hnum);
		return;
	}
	x = x->parent;
	if (x->parent == root)
	{
		nextPrint((y->right), Lnum, Hnum);
		return;
	}
	y = x->parent;
	while(x!=root)
	{
		if((x == y->right) || (y == root))
		{
			nextPrint((y->right), Lnum, Hnum);
			return;
		}
		else
		{
			x = x->parent;
			y = y->parent;
		}
	}
}
*/

void print(struct node *x, int Lnum, int Hnum)
{
	while(x!=NULL)
	{
		if((x->key) < Hnum)
		{
			printf("%d\t", x->key);
		}
		x = x->left;
	}
	printf("\n");
}

void min(int Lnum, int Hnum)
{
	struct node *temp;
	temp = root;
	while(temp!=NULL)
	{
		if(Lnum == (temp->key))
		{
			printf("The numbers are:");
			print((temp->right), Lnum, Hnum); 
			return;
		}
		else if(Lnum < (temp->key))
		{
			temp = temp->left;
		}
		else
		{
			temp = temp->right;
		}
	}	
}

/************************************************Minimum in range ends******************************************************************/



int main()
{
	int opt, num, Lnum, Hnum;
	root = NULL;
	while (1)
	{
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Display\n");
		printf("4. Find rank of Given number\n");
		printf("5. Find number of given rank\n");
		printf("6. Prefix Sum\n");
		printf("7. Minimum in range\n");
		printf("8. Exit\n");
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
			printf("Deleting a node\n");
			printf("Enter the node to be deleted:");
			scanf("%d", &num);
			RBDelete(num);
		}
		else if (opt == 3)
		{
			printf("Displaying\n");
			RBDisplay(root);
		}
		else if (opt == 4)
		{
			printf("Enter the number to find its rank:");
			scanf("%d", &num);
			findRank(root, num);
		}
		else if (opt == 5)
		{
			printf("Enter the rank to find the number:");
			scanf("%d", &num);
			findNum(root, num);
		}
		else if (opt == 6)
		{
			printf("Enter the number to find the prefix sum:");
			scanf("%d", &num);
			prefixSum(num);
		}
		else if (opt == 7)
		{
			printf("Enter the lowest number in the range:");
			scanf("%d", &Lnum);
			printf("Enter the highest number in the range:");
			scanf("%d", &Hnum);
			min(Lnum, Hnum);
		}
		else if (opt == 8)
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
