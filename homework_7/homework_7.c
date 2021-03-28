#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "list.h"

#define SIZE 10
#define TYPE char

char pairBrace(char c);


TYPE stack[SIZE];
int cur = -1;

bool push(TYPE data)
{
	if (cur < SIZE)
	{
		stack[++cur] = data;
		return true;
	}
	else
	{
		printf("Переполнение стека.\n");
		return false;
	}
}

TYPE pop()
{
	if (cur != -1)
		return stack[cur--];
	else
	{
		printf("Стек пуст.\n");
		return -1;
	}
}

void printStack()
{
	while (cur != -1)
		printf("%c ", pop());
	printf("\n");
}

bool braces(char * str)
{
	bool flag = false;
	for (int i = 0; i < strlen(str); ++i)
	{
		char litera = str[i];
		if(litera == '(' || litera == '[' || litera == '{')
		{
			push(str[i]);
		}
		else if(litera == ')' || litera == ']'  || litera == '}')
		{
			char pair = pairBrace(str[i]);
			if (cur == -1)
			{
				return false;
			}
			else if (pop() != pair)
			{
				cur = -1;
				return false;
			}
		}
	}
	if (cur != -1)
	{
		cur = -1;
		return false;
	}
	cur = -1;
	return true;
}

char pairBrace(char brace)
{
    switch(brace)
    {
    case '}':
        return '{';
    case ')':
        return '(';
    case ']':
        return '[';
    }
    return 0;
}
/*----------------------------------------------------------------------*/
void fillRandom(List * list, int count, int border)
{
	for (int i = 0; i < count; ++i)
	{
		insertItems(list, rand()%border);
	}
}

void fillCount(List * list, int count)
{
	for (int i = 0; i < count; ++i)
	{
		insertItems(list, i);
	}
}

bool isSort(List *list)
{
	Node *cur = list->head;
	while(cur->next!=NULL)
	{
		if(cur->data > cur->next->data)
		{
			// printf("%d\t%d\n", cur->data, cur->next->data);
			return false;
		}
		cur = cur->next;
	}
	return true;
}

void copyList(List * src, List * dst)
{
	Node * srcHead = src->head;

	for (int i = 0; i < src->size; ++i)
	{
		Node *cur = dst->head;
		Node *new = (Node *)malloc(sizeof(Node));
		new->data = srcHead->data;
		new->next = NULL;
		if (cur == NULL)
		{
			dst->head = new;
			dst->size++;
		}	
		else
		{
			while (cur->next != NULL)
				cur = cur->next;
			cur->next = new;
			dst->size++;
		}
		srcHead = srcHead->next;
	}
}

int main(int argc, char const *argv[])
{
	// Task 1
	char * braces1 = "(2+(2*2))";
	char * braces2 = "{2/{5*(4+7)]";
	char * braces3 = "{[([{((([{}])))}])]}(){}[{}][]";
	printf("Скобочная последовательность %s %sправильная.\n", braces1, ((braces(braces1)==0)?"не":""));
	printf("Скобочная последовательность %s %sправильная.\n", braces2, ((braces(braces2)==0)?"не":""));
	printf("Скобочная последовательность %s %sправильная.\n", braces3, ((braces(braces3)==0)?"не":""));

	// Task 2

	List *src = (List *)malloc(sizeof(List));
	List *dst = (List *)malloc(sizeof(List));
	init(src);
	init(dst);
	// fillRandom(src, 25, 15);
	fillCount(src, 25);

	printf("src\n");
	printList(src);
	copyList(src, dst);
	printf("dst\n");
	printList(dst);
	removeItems(src, 1);

	printf("src\n");
	printList(src);
	printf("dst\n");	
	printList(dst);
	printf("Список %sотсортирован.\n", isSort(src)?"":"не");


	return 0;
}