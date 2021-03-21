#include <math.h>
#include "lib_arr.h"

#define SIZE_X 3
#define SIZE_Y 3

void bubbleSort(int x, int y, int *arr)
{
	for (int k = 0; k < x * y; ++k)
	{
		for (int i = 0; i < x; ++i)
		{
			for (int j = 0; j < y; ++j)
			{
				
				if (j + 1 <= y)
				{
					if(arr[i * x + j] > arr[i * x + j + 1])
					{ 
						swap(&(arr[i * x + j]), &(arr[i * x + j + 1]));
					}

				}
			}
		}
	}
}


int func(int x)
{
	int result = sqrt(fabs(x)) + 5 * pow(x, 3);

	return result;
}

int main(int argc, char const *argv[])
{
	
	// Task 1

	const int x = SIZE_X;
	const int y = SIZE_Y;

	int sourceArray[SIZE_X][SIZE_Y] = {{1, 9, 2}, {5, 7, 6}, {4, 3, 8}};

	printf("\n\nНеотсортированный массив:\n\n");
	printArray(x, y, *sourceArray);
	bubbleSort(x, y, *sourceArray);
	printf("\n\nОтсортированный массив:\n\n");
	printArray(x, y, *sourceArray);


	// Task 2

	const int size = 11;
	int array[size];
	for (int i = 0; i < size; ++i)
	{
		printf("Введите число %d\n", i);
		scanf("%d", &array[i]);
	}
	
	printArray(1, size, array);
	printf("\n");
	reverse(size, array);
	printArray(1, size, array);

	for (int i = 0; i < size; ++i)
	{
		int result = func(array[i]);
		if (result > 400)
		{
			printf("Alarm!!!!\t%6d\t%6d\n", result, array[i]);
		}else
		{
			printf("\t\t%6d\t%6d\n", result, array[i]);
		}
	}
	return 0;
}