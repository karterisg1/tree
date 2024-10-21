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
struct node * treesearch(struct node *, int);
struct node * tmin(struct node* root);
struct node *newNode(int x);
void myfun(struct node * p);
int pl(struct node * p, int lv);

	
int main()
{
	struct node *root = NULL, *p;
	int i, x, pos;

	for(i = 1; i <= 10; i++)
	{
		printf("Enter number: ");
		scanf("%d", &x);
		root = add2tree(root, x);
	}
	inorder(root);
	putchar('\n');
	preorder(root);
	putchar('\n');
	postorder(root);
	p = tmin(root);
		if (p != NULL)
		printf("%d", p->x);
	return 1;
	printf("Enter number: ");
	scanf("%d", &x);
	p = treesearch(root, x);
	if (p == NULL)
	{
		printf("Not found.\n");
	}
	else
	{
		printf("Found.\n");
	}
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

struct node * treesearch(struct node *root, int x)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (x == root->x)
	{
		return root;
	}
	else if (x < root->x)
	{
		return treesearch(root->left, x);
	}
	else
	{
		return treesearch(root->right, x);
	}
}

struct node * tmin(struct node* root)
{
	if (root == NULL)
	{
		return NULL;
	}
    if (root->left == NULL)
	{
        return root;
	}
    return tmin(root->left);
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
		printf("%d ", p->value);
		return 1;
	}
	return (pl(p->left, lv-1) | pl(p->right, lv-1));
}
