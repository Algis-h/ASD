#include <stdio.h>
#include <math.h>

int main ()
{
	int d;

	printf("Введите целое число больше 0.\n");
	scanf("%d", &d);

	char *flag = "простое";

	if (d > 2)
	{
		for (int i = 2; i <= sqrt(d); i++)
		{
			if (d % i == 0)
			{
				flag = "составное";
				break;
			}
		}
		printf("Число %d %s.\n", d, flag);
	} else
	{
		printf("Число %d %s.\n", d, flag);
	}
  return 0;
}