#include <stdio.h>
#include <stdlib.h>

struct node
{
	int x;
	struct node *next;
};

struct node *add2start(struct node *, int);
struct node *add2end(struct node *, int);
void print(struct node *);
		
int main()
{
	struct node *head = NULL;
	int i, x, pos;
	
	for(i = 1; i <= 5; i++)
	{
		printf("Enter number: ");
		scanf("%d", &x);
		printf("\nEnter point of insertion (1 for start 2 for end): ");
		scanf("%d", &pos);
		if (pos == 1)
		{
			head = add2start(head, x);
		}
		else
		{
			head = add2end(head, x);
		}
		print(head);
	}
}

struct node *add2start(struct node *head, int x)
{
	struct node *p;
	
	p = (struct node *)malloc(sizeof(struct node));
	if (p == NULL)
	{
		fprintf(stderr, "Cannot allocate memory.\n");
		exit(1);
	}
	p->x = x;
	p->next = head;
	head = p;
	return head;
}

struct node *add2end(struct node *head, int x)
{
	struct node *p, *t = NULL, *q;
	
	if (head == NULL)
	{
		head = add2start(head, x);
		return head;
	}
	p = (struct node *)malloc(sizeof(struct node));
	if (p == NULL)
	{
		fprintf(stderr, "Cannot allocate memory.\n");
		exit(1);
	}
	p->x = x;
	p->next = NULL;
	
	for (q = head; q->next != NULL; q = q->next);
	q->next = p;
	return head;
}

void print(struct node *head)
{
	struct node *q;
	
	for (q = head; q != NULL; q = q->next)
	{
		printf("Number is %d\n", q->x);
	}
}
