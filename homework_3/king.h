#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void clearArray(int,  int, int**);
int getValue(int, int, int**);
int move(int, int, int**);
int** createArray(int, int, int **);
void setValue(int, int, int, int **);
int getValue(int, int, int **);
void printArray(int, int, int **);
void setObstacle(int, int, int, int **);

int move(int x, int y, int** arr)
{
	if(getValue(y, x, arr) == 1) return 0;
	if(x == 0 && y == 0) return 0;
	else if (x == 0)
	{
		if(move(x, y - 1, arr) == 0 && y !=1)
		{
			return 0;
		}
		return 1;
	}else if(y == 0)
	{
		if(move(x - 1, y, arr) == 0 && x != 1)
		{
			return 0;
		}
		return 1;
	}

	return move(x, y - 1, arr) + move(x - 1, y, arr);
	
}



int** createArray(const int x, const int y, int **arr)
{
	arr = (int**) calloc(sizeof(int*), x);
	for (int i = 0; i < x; ++i)
	 {
	 	*(arr + i) = (int *) calloc(sizeof(int), y);
	 }
	 clearArray(x, y, arr);
	 return arr; 
}



void clearArray(const int x, const int y, int** arr)
{
	for (int i = 0; i < x; ++i)
	{
		for (int j = 0; j < y; ++j)
		{
			*(*(arr + i) + j) = 0;
		}
	}
}


void setValue(const int x, const int y, int value,  int** arr)
{

	*(*(arr + y) + x) = value;

}



int getValue(const int x, const int y, int** arr)
{
	return *(*(arr + y) + x);
}



void printArray(const int x, const int y, int** arr)
{
	char symbol[7];
	sprintf(symbol, "%%%dd", 3);
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			printf(symbol, getValue(i, j, arr));

		}
		printf("\n");
	}
}



void setObstacle(int countObstacle, const int x, const int y, int** arr)
{
	srand(time(NULL));
	for (int i = 0; i < countObstacle; ++i)
	{
		*(*(arr + rand()%y) + rand()%x) = 1;
		if(getValue(0, 0, arr) != 0) setValue(0, 0, 0, arr);
	}
}