#include <stdio.h>
void bin()	//Функция преобразования десятичного числа в двоичное
{
	float des;
	printf("Введите десятичное число:\n");
	scanf("%f",&des);
	int x=*(int*)&des;
	int bin[32]; 
	for(int j = 0; j < 32; j++)
	{
		bin[j] = (x >>32-j-1) & 1;
		printf(" %d", bin[j]);
	}
	printf("\n");
}
float des()	//Функция преобразования двоичного числа в десятичное
{
	char bin[33];
	int des=0;
	printf("Введите двоичное число:\n");
	scanf("%32s",bin);
	for (int i = 0 ; i < 32; ++i )
	{
		des <<= 1;
		des |= (bin[i] - '0');
	}
		float y=*(float*)&des;
		printf("%f", y);
		printf("\n");
}
int main()
{
	int menu = 0;
	while(menu != 3)
	{
		printf(" 1)Перевести десятичное число в двоичное \n 2) Перевести двоичное число в десятичное \n 3) Выход\n:");
		scanf("%d",&menu);
		switch(menu)
		{
			case 1:
			{
				bin(des);
				break;
			}
			case 2:
			{
				des(bin);
				break;
			}
			case 3:
				break;
			default:
				printf ("Не найдено. Ошибка.");
				break;
		}
	}
return 0; 
}
