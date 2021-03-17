#include <stdio.h>
 
int dec2bin(int dec)
{
	if (dec >= 2)
	{
		dec2bin( dec/2 );
	}
	printf("%d", dec % 2);
 
}

int power(int a, int b)
{
    if(b == 0) return 1;
    return a * power(a, b - 1);

}

int power2(int c, int d)
{
	if(d == 0) return 1;
	if(d == 1) return c;
	if(d % 2 == 0) 
		{
			return power2(c * c, d / 2);
		}else
		{
			return c * power2(c, d - 1);
		}
}


int main ()
{
// Task_1

int dec;
printf("Введите целое число.\n");
scanf("%d", &dec);
printf("Двоичное представление числа %d -> ", dec);
dec2bin(dec);
printf("\n");



// Task 2

int a, b;
printf("Введите число:\n");
scanf("%d", &a);
printf("Введите степень:\n");
scanf("%d", &b);
printf("%d в степени %d равно: %d\n", a, b, power(a, b));


// Task 3

int c, d;
printf("Введите число:\n");
scanf("%d", &c);
printf("Введите степень:\n");
scanf("%d", &d);
printf("%d в степени %d равно: %d\n", c, d, power(c, d));

 
return 0;
 
}