#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define SIZE 10
#define TYPE int

typedef struct
{
	int priority;
	int data;
} Dict;

Dict *arr[SIZE];

TYPE stack[SIZE];
int cur = -1;

int items;
int end;

void init()
{
	for (int i = 0; i < SIZE; ++i) {
		arr[i] = NULL;
	}
	items = 0;

}

void insert(int priority, int data)
{
	if(items == SIZE)
	{
		printf("Очередь переполнена.\n");
		return;
	}
	Dict *tmp = (Dict *)malloc(sizeof(Dict));;
	tmp->priority = priority;
	tmp->data = data;
	arr[items] = tmp;
	items++;
}

Dict* popQ()
{
	if(items == 0)
	{
		return NULL;
	}
	
	int tmpPriority = 0;
	int index = 0;
	for (int i = 0; i < items; ++i)
	{
		if(arr[i]->priority > tmpPriority)
		{
			tmpPriority = arr[i]->priority;
			index = i;
		}

	}
	Dict *tmp = arr[index];
	for (int i = index; i < items - 1; ++i)
	{
		arr[i] = arr[i+1];
	}	
	arr[--items] = NULL;
	return tmp;
}

void printQueue()
{
	printf("[ ");
	for (int i = 0; i < SIZE; ++i)
	{
		if (arr[i] == NULL)
			printf("[*, *] ");
		else
			printf("[%d, %d] ", arr[i]->priority, arr[i]->data);
	}
	printf(" ]\n");
}

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

void dec2bin(int x)
{
	while(x > 0 )
	{
		push(x%2);
		x /= 2;
	}
}

void printStack()
{
	while (cur != -1)
		printf("%d ", pop());
	printf("\n");
}

int main(int argc, char const *argv[])
{
	// Task 1
	init();
	for (int i = 0; i < SIZE; ++i)
	{
		int pr = rand()%30;
		int d = rand()%100;
		insert(pr, d);
	}
	

	printQueue();
	Dict *n = popQ();
	printf("Приоритет = %d, значение = %d\n", n->priority, n->data);
	printQueue();

	insert(7, 782);
	insert(3, 245);
	insert(25, 78);

	printQueue();

	for (int i = 0; i < SIZE; ++i)
	{
		Dict *n = popQ();
		printf("Приоритет = %d, значение = %d\n", n->priority, n->data);
		printQueue();
	}


// Task 2

	int a = 25;
	int b = 15;

	dec2bin(a);
	printf("%d\t->\t", a);
	printStack();
	printf("%d\t->\t", b);
	dec2bin(b);
	printStack();



	return 0;
}