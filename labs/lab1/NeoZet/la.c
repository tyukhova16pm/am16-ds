#include <stdio.h>

void floatToBinary(float *flt, char bin[33])
{
    if(*flt < 0) {
	bin[0] = 1+'0';
	*flt *= -1;
    }
    else
	bin[0] = 0+'0';
    int *_flt = (int*)flt; 
    int i = 31;
    while(i) {
	bin[i] = (*_flt & 1)+'0';
	*_flt >>= 1;
	i--;
    }
    bin[32] = '\0';
}

float binaryToFloat(char bin[32])
{
    int sign = 0;
    int dec=0;
    for(int i=1; i<32; i++) {
	dec <<= 1;
	dec |= (bin[i]-'0');
    }
    int *_flt = &dec;
    float *flt = (float*)_flt;
    if(bin[0] == '1')
	*flt *= -1;
    return *flt;
}

int main()
{
    
    printf("\nВыберите действие:\n[1] Из десятичного в двоичный\n[2] Из двоичного в десятичный\n[0] Выход\nВвод: ");
    int key;
    scanf("%d", &key);
    scanf("%*c");
    switch(key) {
    case 1:
    {
	printf("Введите число: ");
	float ft;
        scanf("%f", &ft);
	float *flt = &ft;
	char bin[32];
	floatToBinary(flt, bin);
	printf("Результат(s|e|m):  %c|", bin[0]);
	for(int i=1; i<9; i++) {
	    printf("%c", bin[i]);
	}
	printf("|");
	for(int i=9; i<32; i++) {
	    printf("%c", bin[i]);
	}
	printf("\n");
	break;
    }

    case 2:
    {
	char bin[33];
	printf("Введите двоичный код числа: ");
	scanf("%s", bin);
	float flt = binaryToFloat(bin);
	printf("Результат: %f\n", flt);
	break;
    }

    }
    return 0;	
}
