#include <stdio.h>
    void F2B(float ch){
    char* b_ry; //4 bytes of char
    int buf1, buf2;
    b_ry = (char*)&ch; //1 float  -> 4 char
        for (buf1=3; buf1>=0;buf1--)
            for (buf2=7; buf2>=0;  buf2--) {
                if(buf1==3 && buf2 == 7)     printf("sign = ");
                if(buf1==3 && buf2 == 6)     printf("\nmantissa = ");
                if(buf1==2 && buf2 == 6)     printf("\nexponenta = ");
                    printf("%d", (b_ry[buf1]>>buf2)&1); //swipe
              }
              printf("\n");
    }
    
    void B2F(char* b_ry){
    int buf1;
    int buf2 = 0;
    for (buf1=0; buf1<32; buf1++){
    buf2<<=1;
    buf2|=(b_ry[buf1]-'0');//symbol - > number 0/1/
    }
    float r_lt = *(float*)&buf2;
        printf("number = %f\n",r_lt);
  
    }

int main(){
int key;
printf("1. Float -> Binary\n");
printf("2. Binary -> Float\n");
scanf("%d", &key);
    switch(key) {
    case 1:
    {
    float ch;
    printf("Enter the number:\n");
    scanf("%f",&ch);
    F2B(ch);
    break;
    }
    case 2:
   {
   char* b_ry;
   printf("Enter binary code:");
   scanf("%s",b_ry);
   B2F(b_ry);
   break;
   }
    }
}
