#include <stdio.h>

union X {
  float fl;
  int integ;
};

char FloatToBin(char bin[33], float f) {
  float result;
  union X x;
  int buf, n;
  x.fl=f;
  int i;

  for (i=0; i<32; i++) {
      buf = x.integ;
      buf>>=(31-i);
      if (buf) {
        bin[i]='1';
        x.integ = (x.integ^(1<<(31-i)));
      } else
        bin[i]='0';

  }
  bin[32]='\0';
  return *bin;
}

float BinToFloat (int buf) {
  union X x;
  float f;
  x.integ = buf;
  f = x.fl;
  return f;
}

int main () {
  union X x;
  int menu, buf;
  char bin[33];
  float result, bufFloat;
  int i;
  x.integ = 0;
  printf ("Select 1 or 2:\n");
  printf ("\t1)from Binary to Float \n");
  printf ("\t2)from Float to Binary \n");
  scanf("%d", &menu);
  switch (menu) {
    case 1: {
      printf ("Write a 32 bytes:  ");
      for (i=0; i<32; i++) {
          scanf ("%d", &buf);
          x.integ=x.integ << 1;
          if (buf==1)
            x.integ+=1;
      }
      printf("\n");
      result = BinToFloat(x.integ);
      printf ("INT %d\n", x.integ);
      printf("RESULT: %f\n", result);
      break;
    }
    case 2: {
      printf ("Write a number with a floating point: ");
      scanf ("%f", &bufFloat);
      printf ("\n");
      *bin = FloatToBin (bin, bufFloat);
      printf ("RESULT: %s\n", bin);
      break;
    }
    default:
      break;
  }
  return 0;
}
