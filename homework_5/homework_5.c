#include <stdio.h>
#include <stdlib.h>
#include "lib_arr.h"

#define SIZE 12

void blockSort(const int len, int *arr)
{
	const int countBag = 3;

	int block[countBag][len + 1];

	for (int i = 0; i < countBag; ++i)
		block[i][len] = 0;

	for (int digit = 1; digit < 1000000000; digit *= 3)
	{
		for (int i = 0; i < len; ++i)
		{
			if(arr[i]%2 == 0)
			{
				int a = (arr[i] / digit) % countBag;
				int count = block[a][len];
				block[a][count] = arr[i];
				count++;
				block[a][len] = count;
			}

		}
		int index = 0;
		for (int i = 0; i < countBag; ++i)
		{
			for (int j = 0; j < block[i][len]; ++j)
			{
				if(arr[index]%2 == 0)
				{
					arr[index++] = block[i][j];
				}else
				{
					index++;
				}
			}
			block[i][len] = 0;
		}
	}
}


void thick(int left, int right, int *arr)
{
	int a = arr[right];
	if(right <=left) return;

	int i = left;
	int j = right - 1;
	int k = left -1;
	int l = right;

	while(i <= j)
	{			
		while(arr[i] < a) i++;
		while(arr[j] > a) j--;

		if(i>= j) break;
		swap(&arr[i], &arr[j]);

		if(arr[i] == a)
		{
			// k++;
			swap(&arr[++k], &arr[i++]);
			// i++;
		}
		if(arr[j] == a)
		{
			// k--;
			swap(&arr[--l], &arr[j--]);
			// i--;
		}
	}
	swap(&arr[i], &arr[right]);
	j = i - 1;
	i++;
	for (int z = left; z <= k; ++z, --j)
	{
		swap(&arr[z], &arr[j]);
	}
	for (int z = right - 1; z >= l; --z, ++i)
	{
		swap(&arr[z], &arr[i]);	
	}
	thick(left, j, arr);
	thick(i, right, arr);

}

int main(int argc, char const *argv[])
{
	
// Task 1

printf("\nTask 1\n");
int arr1[SIZE];
randArray(SIZE, 25, arr1);
printArray(1, SIZE, arr1);
thick(0, 11, arr1);
printArray(1, SIZE, arr1);


// Task 2

printf("\nTask 1\n");
int arr2[SIZE] = {0, 2, 8, 3, 4, 6, 5, 9, 8, 2, 7, 3};
printArray(1, SIZE, arr2);
blockSort(SIZE, arr2);
printArray(1, SIZE, arr2);

	return 0;
}