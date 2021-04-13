#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>


// Task 1

char * caesar(char* str, int key, bool encrypt)
{
	int i =0;
	int sign = 1 - (1 - encrypt) * 2;
	char *tmp =  calloc(strlen(str) + 1, sizeof(char));
	while(str[i])
	{
		tmp[i] = (str[i]  + key * sign) % 256; 
		//tmp[i] = str[i] -32 + key * sign) % (256 - 32) + 32; 
		//Хотел ограничить печатными символами, но выдает очень странный результат. 
		//Не понятно как с русскими буквами работать.
		//Деление на 256 для русских букв.)) Так это не работает. ((
		i++;
	}
	return tmp;
}

// Task 2

char * shuffle(char* str, int key, bool encrypt)
{
	int len = strlen(str);
	int col = len/key + (len%key)/(len/key);
	char *tmp = calloc(len + 1, sizeof(char));
	int k = 0;
	if (encrypt)
	{
		for (int i = 0; i < key; ++i)
		{
			int j = i;
			while(j < len)
			{
				tmp[k] = str[j];
				j += key;
				k++;
			}

		}
	}
	else
	{
		for (int i = 0; i < key; ++i)
		{
			int j = i;
			while(j < len)
			{
				tmp[j] = str[k];
				j += key;
				k++;
			}

		}
	}
	return tmp;
}

int main(int argc, char const *argv[])
{
	setlocale(LC_ALL, "RU");
	
	// Task 1
	// printf("Task 1\n");

	int key = 5;	
	char* str1 = "Test string. Тестовая строка.";
	printf("Исходный текст '%s'\t\n", str1); //Исходный текст 'Test string Тестовая строка'
	char *crypt = caesar(str1, key, true);
	printf("Зашифрованый тест: '%s'\n", crypt); //Зашифрованый тест: 'Yjxy%xywnsl%էպֆև��շյ֔%ֆևօ��տյ'
	char* encrypt = caesar(crypt, key, false);
	printf("Расшифрованый текст: '%s'\n", encrypt); //Расшифрованый текст: 'Test string Тестовая строка'
	free(crypt);
	free(encrypt);
	
	//Task 2
	printf("\n\nTask 2\n");

	key = 5;
	char* str2 ="This is a secret message. Это секретное сообщение.";
	printf("Исходный текст '%s'\t\n", str2); //Исходный текст 'This is a secret message. Это секретное сообщение.'		
	char *crypt2 = shuffle(str2, key, true);
	printf("Зашифрованый тест: '%s'\n", crypt2); //Зашифрованый тест: 'Tists �Ѐе�ѽ.hse aо�н Љ�i cmg� е�Ѿиsaree�ѺѾ�е�  es.��т�бе'
	char *encrypt2 = shuffle(crypt2, key, false);
	printf("Расшифрованый тест: '%s'\n", encrypt2); //Расшифрованый тест: 'This is a secret message. Это секретное сообщение.'
	free(crypt2);
	free(encrypt2);
	return 0;
}