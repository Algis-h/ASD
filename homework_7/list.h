#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;
} Node;

typedef struct
{
	Node *head;
	int size;
} List;

void init(List *lst)
{
	lst->head = NULL;
	lst->size = 0;
}

void insertItems(List *lst, int data)
{
	Node *new = (Node *)malloc(sizeof(Node));
	new->data = data;
	new->next = NULL;

	Node *current = lst->head;
	if (current == NULL)
	{
		lst->head = new;
		lst->size++;
		return;
	}
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = new;
		lst->size++;
		// printf("aaaaaaaaaaaaaaaaaaaaaaaaaa\n");
	}
}

Node *removeItems(List *lst, int data)
{
	Node *current = lst->head;
	Node *parent = NULL;
	if (current == NULL)
		return NULL;

	while (current->next != NULL && current->data != data)
	{
		parent = current;
		current = current->next;
	}
	if (current->data != data)
		return NULL;
	if (current == lst->head)
	{
		lst->head = current->next;
		lst->size--;
		return current;
	}
	parent->next = current->next;
	lst->size--;
	return current;
}


void printNode(Node *n)
{
	if (n == NULL)
	{
		printf("[]");
		return;
	}
	printf("[%d] ", n->data);
}

void printList(List *lst)
{
	Node *current = lst->head;
	if (current == NULL)
		printNode(current);
	else
	{
		do
		{
			printNode(current);
			current = current->next;
		} while (current != NULL);
	}
	printf(" Size: %d\n", lst->size);
}

