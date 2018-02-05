#include <stdio.h>

void DecInBin(float *dec)
{
    int *_dec = (int*)dec;
    int i;
    char mass[32];
    if((*dec)<0)
    {
        mass[0] = 1 + '0';
        *(dec) *= -1;
    }
    else
    {
        mass[0] = 0 + '0';
    }
    for(i=31;i>0;--i){
        mass[i] = (*(_dec) & 1) + '0';
       *(_dec) >>=1;
    }
    printf("Результат: ");
    for(i=0;i<32;++i){
        printf("%c",mass[i]);
    }
    printf("\n");
}

void BinInDec(char mass[32])
{
    int i;
    int inter = 0;

    for(i=1;i<32;++i)
    {
       inter <<=1;
       inter |= (mass[i] - '0');
    }
    int *_dec = &inter;
    float *dec = (float*)_dec;
    if(mass[0]=='1')
    {
        *(dec) *= -1;
    }
    printf("Результат: %f\n",*(dec));
}

int main()
{
    int i;
    printf("1.Из десятичной в двоичную\n2.Из двоичной в десятичную\n");
    scanf("%d",&i);
    switch (i) {
    case 1:
        printf("Введите число в десятичной сс:");
        float ind;
        scanf("%f",&ind);
        float *index = &ind;
        DecInBin(index);
        break;
    case 2:
        printf("Введите число в двоичной сс:");
        char mass[33];
        scanf("%32s",mass);
        BinInDec(mass);
    default:
        printf("Такого пункта нет");
        break;
    }
   return 0;
}

