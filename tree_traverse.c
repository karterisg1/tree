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