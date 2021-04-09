#include <stdio.h>
#include <string.h>

int sHash(char* str)
{
	int size = strlen(str);
	int sum = 0;
	for (int i = 0; i < size; ++i)
	{
		sum += str[i];
	}
	return sum;
}

void exchange(int* money, int size, int sum)
{
	int result = 0;
	int index = 0;

	printf("Сумма %d набрана монетами: ", sum);
	while(result < sum )
	{
		while (result + money[index] > sum)
		{
			index++;
		}
		result += money[index];
		printf("[%d], ", money[index]);
	}

}

int main(int argc, char const *argv[])
{
	// Task 1
	printf("Task 1\n");
	char* str = "abcdef";
	printf("Hash '%s' = %d\n", str, sHash(str));
	printf("\n");



	// Task 2

	printf("Task 2\n");
	int sum = 98;
	int money[] = {50, 10, 5, 2, 1};
	int size = 5;

	exchange(money, 5, sum);


	return 0;
}