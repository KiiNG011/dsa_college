#include <stdio.h>
#include <stdlib.h>
struct node
{
	int d;
	struct node *l;
};
struct node *r = NULL, *f = NULL;
void add(int);
void del(int);
void display();
int main()
{
	int ch, x;
	printf("\n1 to insert\n2 to delete\n3 to display\n0 to exit");
	do
	{
		printf("\nEnter Choice : ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			printf("Enter data : ");
			scanf("%d", &x);
			add(x);
			break;
		case 2:
			printf("Enter data to be deleted : ");
			scanf("%d", &x);
			del(x);
			break;
		case 3:
			display();
			break;
		}
	} while (ch != 0);
	return 0;
}
void add(int num)
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->d = num;
	if (f == NULL)
	{
		f = temp;
		r = temp;
	}
	else
	{
		r->l = temp;
		r = r->l;
		temp->l = f;
	}
}
void del(int a)
{
	if (f == NULL)
	{
		printf("LinkedList is empty");
		return;
	}
	struct node *temp, *old;
	old = NULL;
	temp = f;
	while (temp != r && temp->d != a)
	{
		old = temp;
		temp = temp->l;
	}
	if (temp == r && temp->d != a)
		printf("ELEMENT NOT PRESENT\n");
	else
	{
		if (temp->d == f->d && f != r)
			f = f->l;
		if (old != NULL)
			old->l = temp->l;
		if (temp->d == r->d && f != r)
			r = old;
	}
	if (f == temp && f == r)
	{
		f = NULL;
		r = NULL;
	}

	free(temp);
}

void display()
{
	printf("\n");
	if (f == NULL)
	{
		printf("LinkedList is empty");
		return;
	}
	struct node *q = f;
	while (q != r)
	{
		printf("%d ", q->d);
		q = q->l;
	}
	printf("%d ", q->d);
}
