#include <stdio.h>

void floatToBinary(float flt, char bin[33])
{
    FILE *out = fopen("fl.bin", "wb");
    int sign = (int)flt >> 31;
    if(sign == -1) flt *= -1;    
    fwrite(&flt, sizeof(float), 1, out);
    fclose(out);
    FILE *in = fopen("fl.bin", "rb");
    int _flt;
    fread(&_flt, sizeof(float), 1, in);
    int i = 31;    
    while(_flt) {
	bin[i] = (_flt & 1)+'0';
	_flt >>= 1;
	i--;
    }
    if(sign == -1)
	bin[0] = 1+'0';
    else
	bin[0] = 0+'0';    
    bin[32] = '\0';
    fclose(in);
    remove("fl.bin");
}

float binaryToFloat(char bin[32])
{
    FILE *out = fopen("fl.bin", "wb");
    int sign;
    if(bin[0])
	sign = 1;
    else
	sign = -1;
    
    int dec=0;
    for(int i=0; i<32; i++) {
	dec <<= 1;
	dec |= (bin[i]-'0');
    }
    fwrite(&dec, sizeof(float), 1, out);
    fclose(out);    
    FILE *in = fopen("fl.bin", "rb");
    float flt;
    fread(&flt, sizeof(float), 1, in);
    fclose(in);
    remove("fl.bin");
    return flt;
}

int main()
{
    while(1) {
	printf("\nВыберите действие:\n[1] Из десятичного в двоичный\n[2] Из двоичного в десятичный\n[0] Выход\nВвод: ");
	int key;
	scanf("%d", &key);
	switch(key) {
	case 1:
	{
	    float flt = -12.5;
	    printf("Введите число: ");
	    scanf("%f", &flt);
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
	    char bin[32];
	    printf("Введите двоичный код числа: ");
	    scanf("%*c");
	    scanf("%s", bin);
	    printf("%s\n", bin);
	    float flt = binaryToFloat(bin);
	    printf("Результат: %f\n", flt);    
	    break;
	}
	
	default:
	    return 0;
	}
    }    
}
