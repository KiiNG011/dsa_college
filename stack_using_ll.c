#include <stdio.h>
#include <stdlib.h>
struct node
{
	int d;
	struct node *l;
};

void push(int, struct node **);
void pop(struct node **);
void disp(struct node *);
int main()
{
	struct node *p;
	int z, ch, n;
	p = NULL;
	printf("\n1 to push\n2 to pop\n3 to display\n4 to exit");
	do
	{
		printf("\nEnter Choice\n");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			printf("\nEnter Value\n");
			scanf("%d", &z);
			push(z, &p);
			break;

		case 2:
			pop(&p);
			break;

		case 3:
			disp(p);
			break;
		}
	} while (ch != 4);
}
void push(int y, struct node **q)
{
	struct node *temp;
	if (*q == NULL)
	{
		temp = (struct node *)malloc(sizeof(struct node *));
		*q = temp;
		temp->d = y;
		temp->l = NULL;
	}
	else
	{
		temp = (struct node *)malloc(sizeof(struct node *));
		temp->d = y;
		temp->l = *q;
		*q = temp;
	}
}
void pop(struct node **q)
{
	if (*q == NULL)
	{
		printf("STACK IS EMPTY");
	}
	else
	{
		struct node *temp = *q, *r = *q;
		r = r->l;
		*q = r;
		printf("DATA DELETED : %d", temp->d);
		free(temp);
	}
}
void disp(struct node *x)
{
	printf("\n");
	if (x == NULL)
	{
		printf("STACK is empty");
		return;
	}
	while (x != NULL)
	{
		printf("%d ", x->d);
		x = x->l;
	}
}
