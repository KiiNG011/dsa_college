#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *link;
};
void insert(struct node **, int);
void display(struct node *);
void del(struct node **, int);
void reverse(struct node **);

int main()
{
	struct node *p;
	p = NULL;
	int ch, x;
	printf("ENTER 0 TO END \nENTER 1 TO INSERT \nENTER 2 TO DELETE \nENTER 3 TO REVERSE \nENTER 4 TO DISPLAY\n");
	do
	{
		printf("\nEnter Choice : ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 0:
			break;
		case 1:
			printf("ENTER DATA : ");
			scanf("%d", &x);
			insert(&p, x);
			break;
		case 2:
			printf("ENTER DATA TO DELETE: ");
			scanf("%d", &x);
			del(&p, x);
			break;
		case 3:
			reverse(&p);
			break;
		case 4:
			display(p);
			break;
		}
	} while (ch != 0);
}
void insert(struct node **q, int num)
{
	struct node *temp, *r, *old;
	old = NULL;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->link = NULL;
	temp->data = num;
	if (*q == NULL)
	{
		*q = temp;
	}
	else
	{
		r = *q;
		while (r != NULL && r->data < num)
		{
			old = r;
			r = r->link;
		}
		if (r == NULL)
			old->link = temp;
		else
		{
			old->link = temp;
			temp->link = r;
		}
	}
}

void display(struct node *q)
{
	printf("\n");
	if (q == NULL)
	{
		printf("LinkedList is empty");
		return;
	}
	while (q != NULL)
	{
		printf("%d ", q->data);
		q = q->link;
	}
}

void del(struct node **q, int a)
{
	if (*q == NULL)
	{
		printf("LinkedList is empty");
		return;
	}
	struct node *temp, *old;
	old = NULL;
	temp = *q;
	while (temp != NULL && temp->data != a)
	{
		old = temp;
		temp = temp->link;
	}
	if (temp == NULL && temp->data != a)
		printf("ELEMENT NOT PRESENT\n");
	else
	{
		if (old != NULL)
			old->link = temp->link;
		else
			*q = temp->link;
	}
	if (*q == temp)
		*q = NULL;
	free(temp);
}

void reverse(struct node **q)
{
	struct node *prvNode, *nextNode, *currentNode;
	currentNode = *q;
	prvNode = NULL;
	while (currentNode != NULL)
	{
		nextNode = prvNode;
		prvNode = currentNode;
		currentNode = currentNode->link;
		prvNode->link = nextNode;
	}
	*q = prvNode;
}
