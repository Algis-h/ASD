#include <stdlib.h>
#include <stdio.h>


void printArray(int, int, int*);
void swap(int*, int*);
void reverse(int, int *);


void printArray(int x, int y, int *arr)
{
	for (int i = 0; i < x; ++i)
	{
		for (int j = 0; j < y; ++j)
		{
			printf("%d\t", arr[i * x + j]);

		}
	printf("\n");
	}

}
void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;

}

void reverse(int size, int *arr)
{
	for (int i = 0; i < size/2; i++)
	{
		swap(&arr[i], &arr[size - i - 1]);
	}
}

void randArray(const int len, const int border, int *arr)
{
	for (int i = 0; i < len; ++i)
	{
		*(arr + i) = rand() % border;
	}
}