#include <stdio.h>

Void dectobin() { // преобразование десятичного в двоичное
	
	
    float dec;
		printf("Введите десятичное число:\n");
		scanf("%f",&dec);
	int d=*(int*)&dec;
	int binary[32]; 
		for(int i = 0; i < 32; i++)
			{
				binary[j] = (d >>32-i-1) & 1;
				printf(" %d", binary[i]);
			}
	
		printf("\n--------------------\n");



}

Void bintodec(){   //преобразование двоичного в десятичное 
    
    
    char binary;
    	printf("Введите десятичное число:\n");\
    	scanf("%s",&binary);	
	int i;
	int f=0;
     	for (i=0; i<32; i++)
			{
				 f<<= 1;
				 f |= (binary[i] - '0');
			}
	float ff;
	ff = *(float*)&f;
	printf (ff);
	
	printf("\n--------------------\n");



}


int main (){
    int key
	printf ("Выберите действие: 1) из десятичного в двоичное 2) из двоичного в десятичное 3) выход");
	scanf("%d", &key);
	{
			
			case 1:
			{
				dectobin(dec);
				
				break;
			}
			
			case 2:
			{
				bintodec(binary);
				
				break;
			}
			
			case 3:
				
				break;
			
		}
	}
return 0; 

}




