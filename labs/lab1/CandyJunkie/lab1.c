#include <stdio.h>

void FloatToBinaryAndPrintIt (float f);
void BinaryToFloatAndPrintIt (const char * b);

int main () {

	int mode = 0;
	float num;
	char s_e_m[33];
	int i = 0;
	int err = 0;
	char c_temp = 0;

	while (1) {
		printf ("Choose mode: 1 for decimal to binary mode, 2 for binary to decimal mode.\n");
		err = scanf ("%d", &mode);
		if (0 == err) { // scanf ничего не прочел.
			fprintf (stderr, "Error. 1 or 2 required.\n");
			continue;
		}
		switch (mode) {
			case 1: 
				printf ("Decimal to binary mode. Input a floating-point number .\n");
				while (1) {
					err = 0;
					err = scanf ("%f", &num);
					if (0 == err) { // scanf ничего не прочел.
						fprintf (stderr, "Error. Floating-point number required.\n");
					}
					else break;
				}
				FloatToBinaryAndPrintIt (num);
				break;
			case 2:
				while (1) {
					err = 0;
					printf ("binary to decimal mode. Input a binary code of the number (32 bits)\n");
					getc (stdin); // непонятный символ, который все руинит. Возможно это mode или перенос строки.
					for (i = 0; i < 32; ++i) {
						s_e_m[i] = getc (stdin);
					}
					s_e_m[32] = '\0';	
					break;
				}
				BinaryToFloatAndPrintIt (s_e_m);
				break;
			default:
				fprintf (stderr, "Error. 1 or 2 required.\n");
		}
		printf ("----------------------------------------------------------------------------\n");
	}

	return 0;
}

void FloatToBinaryAndPrintIt (float f) 
{
	char result[32];
	int i = 0;
	int binary = 0;

	binary = *(int *)(&f);
	for (i = 31; i >= 0; --i) {
		result[i] = (char)(binary & 0x00000001) + '0';
		binary >>= 1;
	}
	printf ("Number %f in s|e|m format: ", f);
	for (i = 0; i < 32; ++i) {
		putc (result[i], stdout);
		if ((0 == i) || (8 == i)) { // после вывода знака и экспоненты
			printf (" | ");
		}
	}
	printf ("\n");
	return;
}

void BinaryToFloatAndPrintIt (const char * b) 
{
	float result = 0;
	int temp = 0;
	int i = 0;
	int sign = b[0] - '0';

	for (i = 1; i < 32; ++i) {
		if (('0'== b[i]) || ('1' == b[i])) {
			temp <<= 1;
			temp |= (b[i] - '0');
		}
		else {
			fprintf (stderr, "Error. Array of 0s and 1s required.\n");
		}
	}
	result = *(float *)(&temp);
	printf ("Number ");
	for (i = 0; i < 32; ++i) {
		putc (b[i], stdout);
		if ((0 == i) || (8 == i)) { // после вывода знака и экспоненты
			printf (" | ");
		}
	}
	printf (" => ");
	if (sign) {
		putc ('-', stdout);
	}
	printf("%f\n", result);
	return;
}
