#include <stdio.h>

void btofloat(char *bin)
	{
		int a;
		int res=0;

		for (a=0; a<32; a++)
			{
				res <<= 1;
				res |= (bin[a] - '0');
			}
		float resf = *(float*)&res;
		printf ("%f\n", resf);
	}

void floattob(float dec)
	{
		int a, b;
		char *bin;
		 
		bin = (char*)&dec;
		for (a=3; a>=0; a--)
			for (b=7; b>=0; b--)
				printf("%d", (bin[a] >> b) & 1);
		printf("\n");
	}
 
int main()
	{
		int k=0;
		printf("Выберите операцию:\n1) Десятичное число в двоичное\n2) Двоичное число в десятичное\n");
		scanf("%d", &k);
		switch(k) {
				case 1:
				{
					float dec;
					printf("Введите число: ");
					scanf("%f",&dec);
					floattob(dec);
					return 0;
					break;
				}
				case 2:
				{
					char* bin; //example - "11000001000101100110011001100110"
					printf("Введите число: ");
					scanf("%s",bin);
					btofloat(bin);
					return 0;
					break;
				}
			  }
	}
