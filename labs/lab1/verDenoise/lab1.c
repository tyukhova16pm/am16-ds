#include <stdio.h>

void bynary_form(float *fl) {
	int i;
	int *in = (int *)fl;
	char mass[32];
    for(i=31;i>=0;i--){
        mass[i] = (*(in) & 1) + '0';
       *(in) >>=1;
    }
    for(i=0;i<32;++i){
        if(i == 1 || i == 9) printf("|");
        printf("%c",mass[i]);
    }
	printf("\n");
}

void float_form(char mass[33]) {
    int fl = 0;
    int i;
    for(i = 0; i<32; i++) {
        fl <<= 1;
        fl |= (mass[i] - '0');
    }
    printf("%f\n", *(float*)&fl);
}

int main() {
    int buff;
    printf("1 Вывод float как знак|экспонента|мантисса;\n2 Вывод binary как float;\n");
    scanf("%d", &buff);
    switch(buff){
        case 1: {
            float fl;
            printf("Введите число:\n");
            scanf("%f", &fl);
            bynary_form(&fl);
        break;
        }
        case 2: {
            char mass[33];
            printf("Введите число:\n");
            scanf("%32s", mass);
            float_form(mass);
        break;
        }
        case 3:
            return 0;
        default:
         break;
    }
    return 0;
}

