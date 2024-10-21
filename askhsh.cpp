#include <stdio.h>
#include <stdlib.h>

struct node
{
	int x;
	struct node *left;
	struct node *right;
};

struct node *add2tree(struct node *, int);
void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);
struct node *newNode(int x);
void myfun(struct node * p);
int pl(struct node * p, int lv);

	
int main()
{
	struct node *root = NULL;

/*	for(i = 1; i <= 10; i++)
	{
		printf("Enter number: ");
		scanf("%d", &x);
		root = add2tree(root, x);
	} */
	root = add2tree(root, 100); //examples
	root = add2tree(root, 200);
	root = add2tree(root, 150);
	root = add2tree(root, 300);
	root = add2tree(root, 250);
	root = add2tree(root, 30);
	root = add2tree(root, 10);
	root = add2tree(root, 80);
	root = add2tree(root, 15);
	root = add2tree(root, 70);
	root = add2tree(root, 90);
	root = add2tree(root, 60);
	printf("Inorder: ");
	inorder(root);
	printf("\nPreorder: ");
	preorder(root);
	printf("\nPostorder: ");
	postorder(root);
	printf("\nmyfun: ");
	myfun(root);
}

struct node *newNode(int x)
{
	struct node *p;
	
	p = (struct node *)malloc(sizeof(struct node));
	if (p == NULL)
	{
		fprintf(stderr, "Cannot allocate memory.\n");
		exit(1);
	}
	p->x = x;
	p->left = NULL;
	p->right = NULL;
	return p;
}

struct node *add2tree(struct node *root, int x)
{
	struct node *p;
	
	p = newNode(x);
	
	if (root == NULL)
	{
		root = p;
	}
	else if (x < root->x)
	{
		root->left = add2tree(root->left, x);
	}
	else
	{
		root->right = add2tree(root->right, x);
	}
	return root;
}

void inorder(struct node* root) 
{
	if (root == NULL)
 	{
  		return;
 	}
  	inorder(root->left);
 	printf("%d ->", root->x);
  	inorder(root->right);
}

void preorder(struct node* root) 
{
	if (root == NULL)
 	{
  		return;
 	}
	printf("%d ->", root->x);
	preorder(root->left);
	preorder(root->right);
}

void postorder(struct node* root) 
{
	if (root == NULL)
 	{
  		return;
 	}
	postorder(root->left);
	postorder(root->right);
	printf("%d ->", root->x);
}


void myfun(struct node * p)
{
	int lv = 0;
	while (pl(p, lv))
		lv++;
}

int pl(struct node * p, int lv)
{ 
	if (p == NULL) return 0;
	if (!lv) 
	{
		printf("%d ", p->x);
		return 1;
	}
	return (pl(p->left, lv-1) | pl(p->right, lv-1));
}
