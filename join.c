struct node * join(struct node *L1, struct node *L2)
{
	struct node *q, *t;
	
	if (L1 == NULL)
		return L2;
	
	for(q = L1; q != NULL; q=q->next)
	{
		t = q;
	}
	t->next = L2;
	return L1;
}