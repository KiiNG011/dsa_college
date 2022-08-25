#include <stdio.h>
#include <stdlib.h>
typedef struct deq
{
	int front;
	int rear;
	int *a;
	int n;
} de;
void del_f(de *);
void del_r(de *);
void insert_f(de *);
void insert_r(de *);
void disp(de *);
int main()
{
	int c, ch, z;
	de s;
	s.rear = -1;
	s.front = -1;
	printf("ENTER LENGTH OF QUEUE ");
	scanf("%d", &s.n);
	s.a = (int *)malloc(sizeof(int) * s.n);
	printf("MENU TO RESTRICT:\n");
	printf("\nENTER 1 TO RESTRICT INSERT ELEMENT FROM FRONT\nENTER 2 TO RESTRICT DELETE ELEMENT FROM FRONT\nENTER 3 TO RESTRICT INSERT ELEMENT FROM REAR\nENTER 4 TO RESTRICT DELETE ELEMENT FROM REAR\n");
	printf("\nENTER CHOICE \n");
	scanf("%d", &c);
	switch (c)
	{
	case 1:
		printf("\nENTER 0 TO EXIT\nENTER 1 TO INSERT ELEMENT FROM REAR\nENTER 2 TO DELETE ELEMENT FROM FRONT\nENTER 3 TO DELETE ELEMENT FROM REAR\nENTER 4 TO DISPLAY ELEMENTS\n");
		do
		{
			printf("\nENTER CHOICE \n");
			scanf("%d", &ch);
			switch (ch)
			{
			case 1:
				insert_r(&s);
				break;
			case 2:
				del_f(&s);
				break;
			case 3:
				del_r(&s);
				break;
			case 4:
				disp(&s);
				break;
			case 0:
				break;
			default:
				printf("WRONG INPUT");
			}
		} while (ch != 0);
		break;
	case 2:
		printf("\nENTER 0 TO EXIT\nENTER 1 TO INSERT ELEMENT FROM REAR\nENTER 2 TO DELETE ELEMENT FROM REAR\nENTER 3 TO INSERT ELEMENT FROM FRONT\nENTER 4 TO DISPLAY ELEMENTS\n");
		do
		{
			printf("\nENTER CHOICE \n");
			scanf("%d", &ch);
			switch (ch)
			{
			case 1:
				insert_r(&s);
				break;
			case 2:
				del_r(&s);
				break;
			case 3:
				insert_f(&s);
				break;
			case 4:
				disp(&s);
				break;
			case 0:
				break;
			default:
				printf("WRONG INPUT");
			}
		} while (ch != 0);
		break;
	case 3:
		printf("\nENTER 0 TO EXIT\nENTER 1 TO INSERT ELEMENT FROM FRONT\nENTER 2 TO DELETE ELEMENT FROM FRONT\nENTER 3 TO DELETE ELEMENT FROM REAR\nENTER 4 TO DISPLAY ELEMENTS\n");
		do
		{
			printf("\nENTER CHOICE \n");
			scanf("%d", &ch);
			switch (ch)
			{
			case 1:
				insert_f(&s);
				break;
			case 2:
				del_f(&s);
				break;
			case 3:
				del_r(&s);
				break;
			case 4:
				disp(&s);
				break;
			case 0:
				break;
			default:
				printf("WRONG INPUT");
			}
		} while (ch != 0);
		break;
	case 4:
		printf("\nENTER 0 TO EXIT\nENTER 1 TO INSERT ELEMENT FROM REAR\nENTER 2 TO DELETE ELEMENT\nENTER 3 TO INSERT ELEMENT FROM FRONT\nENTER 4 TO DISPLAY ELEMENTS\n");
		do
		{
			printf("\nENTER CHOICE \n");
			scanf("%d", &ch);
			switch (ch)
			{
			case 1:
				insert_r(&s);
				break;
			case 2:
				del_f(&s);
				break;
			case 3:
				insert_f(&s);
				break;
			case 4:
				disp(&s);
				break;
			case 0:
				break;
			default:
				printf("WRONG INPUT");
			}
		} while (ch != 0);
		break;
	}
}
void insert_r(de *s)
{
	int i, k;
	if (s->front == 0 && s->rear == s->n - 1)
	{
		printf("QUEUE IS FULL\n");
		return;
	}
	if (s->front == -1)
		s->front = 0;
	if (s->rear == s->n - 1 && s->front != 0)
	{
		for (i = s->front - 1; i < s->rear; i++)
			s->a[i] = s->a[i + 1];
		s->front -= 1;
	}
	else
		s->rear += 1;
	printf("Enter element:\n");
	scanf("%d", &k);
	s->a[s->rear] = k;
}

void insert_f(de *s)
{
	int i, k;
	if (s->front == 0 && s->rear == s->n - 1)
	{
		printf("QUEUE IS FULL\n");
		return;
	}
	if (s->front == -1)
		s->front = 0;
	if (s->rear != s->n - 1 && s->front == 0)
	{
		for (i = s->rear + 1; i > s->front; i--)
			s->a[i] = s->a[i - 1];
		s->rear += 1;
	}
	else
		s->front -= 1;
	printf("Enter element:\n");
	scanf("%d", &k);
	s->a[s->front] = k;
}

void del_f(de *s)
{
	if (s->front == -1)
		printf("QUEUE IS EMPTY\n");
	else
	{
		printf("POPPED ITEM IS :- %d", s->a[s->front]);
		if (s->front == s->rear)
			s->front = s->rear = -1;
		else
			s->front += 1;
	}
}

void del_r(de *s)
{
	if (s->front == -1)
		printf("QUEUE IS EMPTY\n");
	else
	{
		printf("POPPED ITEM IS :- %d", s->a[s->rear]);
		if (s->front == s->rear)
			s->front = s->rear = -1;
		else
			s->rear -= 1;
	}
}

void disp(de *s)
{
	int i;
	if (s->front == -1)
		printf("QUEUE IS EMPTY\n");
	else
	{
		i = s->front;
		while (i <= s->rear)
		{
			printf("%d ", s->a[i]);
			i += 1;
		}
	}
}