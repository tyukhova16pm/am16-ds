#include <malloc.h>
#include "transcoding.h"


int main() {

  FILE *f;
  f = fopen("source.txt", "r");

  char c;

  int flag=1;
  int i, n=0;

  char *source, *win, *cp;
  char *winCp, *cpWin, *winWin, *cpCp;

  char *winCpCp, *winCpWin, *cpWinWin, *cpWinCp;
  char *winWinCp, *winWinWin, *cpCpWin, *cpCpCp;

  char *winCpCp1, *winCpWin1, *cpWinWin1, *cpWinCp1;
  char *winWinCp1, *winWinWin1, *cpCpWin1, *cpCpCp1;

  if (f!=NULL) {

    printf ("ERROR file is not opened!\n");

  } else {

    // считаем,сколько символов в файле
    if (feof(f)==0) {
      fscanf ("%c", &c);
      n++;
    }

    fclose(f);

    // выделяем память под массивы символов
    source = (char*)malloc(n * sizeof(char));

    win = (char*)malloc(n * sizeof(char));
    cp = (char*)malloc(n * sizeof(char));

    winCp = (char*)malloc(n * sizeof(char));
    cpWin = (char*)malloc(n * sizeof(char));
    winWin = (char*)malloc(n * sizeof(char));
    cpCp = (char*)malloc(n * sizeof(char));

    winCpCp = (char*)malloc(n * sizeof(char));
    winCpWin = (char*)malloc(n * sizeof(char));
    cpWinWin = (char*)malloc(n * sizeof(char));
    cpWinCp = (char*)malloc(n * sizeof(char));
    winWinCp = (char*)malloc(n * sizeof(char));
    winWinWin = (char*)malloc(n * sizeof(char));
    cpCpWin = (char*)malloc(n * sizeof(char));
    cpCpCp = (char*)malloc(n * sizeof(char));

    winCpCp1 = (char*)malloc(n * sizeof(char));
    winCpWin1 = (char*)malloc(n * sizeof(char));
    cpWinWin1 = (char*)malloc(n * sizeof(char));
    cpWinCp1 = (char*)malloc(n * sizeof(char));
    winWinCp1 = (char*)malloc(n * sizeof(char));
    winWinWin1 = (char*)malloc(n * sizeof(char));
    cpCpWin1 = (char*)malloc(n * sizeof(char));
    cpCpCp1 = (char*)malloc(n * sizeof(char));

    // открываем файл-ресурс для чтения заново

    f = fopen("source.txt", "r");
    for (i=0; i<n; i++) {

      fscanf("%c", &c);
      source[i]=c;

      win[i] = ToWin1251(source[i]);
      cp[i] = ToCp866(source[i]);

      winCp[i] = ToCp866(win[i]);
      cpWin[i] = ToWin1251(cp[i]);
      winWin[i] = ToWin1251(win[i]);
      cpCp[i] = ToCp866(cp[i]);

      winCpCp[i] = ToCp866(winCp[i]);
      winCpWin[i] = ToWin1251(winCp[i]);
      cpWinWin[i] = ToWin1251(cpWin[i]);
      cpWinCp[i] = ToCp866(cpWin[i]);
      winWinCp[i] = ToCp866(winWin[i]);
      winWinWin[i] = ToWin1251(winWin[i]);
      cpCpWin[i] = ToWin1251(cpCp[i]);
      cpCpCp[i] = ToCp866(cpCp[i]);

      winCpCp1[i] = CpToKoi8(winCpCp[i]);
      winCpWin1[i] = CpToKoi8(winCpWin[i]);
      cpWinWin1[i] = CpToKoi8(cpWinWin[i]);
      cpWinCp1[i] = CpToKoi8(cpWinCp[i]);
      winWinCp1[i] = CpToKoi8(winWinCp[i]);
      winWinWin1[i] = CpToKoi8(winWinWin[i]);
      cpCpWin1[i] = CpToKoi8(cpCpWin[i]);
      cpCpCp1[i] = CpToKoi8(cpCpCp[i]);

      winCpCp[i] = WinToKoi8(winCpCp[i]);
      winCpWin[i] = WinToKoi8(winCpWin[i]);
      cpWinWin[i] = WinToKoi8(cpWinWin[i]);
      cpWinCp[i] = WinToKoi8(cpWinCp[i]);
      winWinCp[i] = WinToKoi8(winWinCp[i]);
      winWinWin[i] = WinToKoi8(winWinWin[i]);
      cpCpWin[i] = WinToKoi8(cpCpWin[i]);
      cpCpCp[i] = WinToKoi8(cpCpCp[i]);

      winCpCp1[i] = Koi8ToUtf8(winCpCp1[i]);
      winCpWin1[i] = Koi8ToUtf8(winCpWin1[i]);
      cpWinWin1[i] = Koi8ToUtf8(cpWinWin1[i]);
      cpWinCp1[i] = Koi8ToUtf8(cpWinCp1[i]);
      winWinCp1[i] = Koi8ToUtf8(winWinCp1[i]);
      winWinWin1[i] = Koi8ToUtf8(winWinWin1[i]);
      cpCpWin1[i] = Koi8ToUtf8(cpCpWin1[i]);
      cpCpCp1[i] = Koi8ToUtf8(cpCpCp1[i]);

      winCpCp[i] = Koi8ToUtf8(winCpCp[i]);
      winCpWin[i] = Koi8ToUtf8(winCpWin[i]);
      cpWinWin[i] = Koi8ToUtf8(cpWinWin[i]);
      cpWinCp[i] = Koi8ToUtf8(cpWinCp[i]);
      winWinCp[i] = Koi8ToUtf8(winWinCp[i]);
      winWinWin[i] = Koi8ToUtf8(winWinWin[i]);
      cpCpWin[i] = Koi8ToUtf8(cpCpWin[i]);
      cpCpCp[i] = Koi8ToUtf8(cpCpCp[i]);

    }

    free(source);
    free(winWin);
    free(cpCp);
    free(cpWin);
    free(winCp);
    free(cp);
    free(win);
    fclose(f);

    // Имеем раскодированные массивы
    // Осталось найти осмысленный текст среди них и вывести на экран

    //------------------------------------------------

    // 1

    if (SearchForMeaning(winWinWin, n)){
      printf("\n");
      for (i=0; i<n; i++){
        win[i] = Koi8ToUtf8(win[i]);
        printf("%c", win[i]);
      }
    }
    free(winWinWin);

    // 2

    if (SearchForMeaning(cpCpCp, n)){
      printf("\n");
      for (i=0; i<n; i++){
        cp[i] = Koi8ToUtf8(cp[i]);
        printf("%c", cp[i]);
      }
    }
    free (cpCpCp);

    // 3

    if (SearchForMeaning(winWinCp, n)){
      printf("\n");
      for (i=0; i<n; i++){
        winCp[i] = Koi8ToUtf8(winCp[i]);
        printf("%c", winCp[i]);
      }
    }
    free (winWinCp);

    // 4

    if (SearchForMeaning(cpCpWin, n)){
      printf("\n");
      for (i=0; i<n; i++){
        cpWin[i] = Koi8ToUtf8(cpWin[i]);
        printf("%c", cpWin[i]);
      }
    }
    free (cpCpWin);

    // 5

    if (SearchForMeaning(cpWinWin, n)){
      printf("\n");
      for (i=0; i<n; i++){
        win[i] = Koi8ToUtf8(win[i]);
        printf("%c", win[i]);
      }
    }
    free (cpWinWin);

    // 6

    if (SearchForMeaning(cpWinCp, n)){
      printf("\n");
      for (i=0; i<n; i++){
        cpWinCp[i] = Koi8ToUtf8(cpWinCp[i]);
        printf("%c", cpWinCp[i]);
      }
    }
    free (cpWinCp);

    // 7

    if (SearchForMeaning(winCpCp, n)){
      printf("\n");
      for (i=0; i<n; i++){
        cp[i] = Koi8ToUtf8(cp[i]);
        printf("%c", cp[i]);
      }
    }
    free (winCpCp);

    // 8

    if (SearchForMeaning(winCpWin, n)){
      printf("\n");
      for (i=0; i<n; i++){
        cp[i] = Koi8ToUtf8(cp[i]);
        printf("%c", cp[i]);
      }
    }
    free (winCpWin);

    //------------------------------------------------

    // 1

    if (SearchForMeaning(winWinWin1, n)){
      printf("\n");
      for (i=0; i<n; i++){
        winWinWin1[i] = Koi8ToUtf8(winWinWin1[i]);
        printf("%c", winWinWin1[i]);
      }
    }
    free(winWinWin1);

    // 2

    if (SearchForMeaning(cpCpCp1, n)){
      printf("\n");
      for (i=0; i<n; i++){
        cpCpCp1[i] = Koi8ToUtf8(cpCpCp1[i]);
        printf("%c", cpCpCp1[i]);
      }
    }
    free (cpCpCp1);

    // 3

    if (SearchForMeaning(winWinCp1, n)){
      printf("\n");
      for (i=0; i<n; i++){
        winWinCp1[i] = Koi8ToUtf8(winWinCp1[i]);
        printf("%c", winWinCp1[i]);
      }
    }
    free (winWinCp1);

    // 4

    if (SearchForMeaning(cpCpWin1, n)){
      printf("\n");
      for (i=0; i<n; i++){
        cpCpWin1[i] = Koi8ToUtf8(cpCpWin1[i]);
        printf("%c", cpCpWin1[i]);
      }
    }
    free (cpCpWin1);

    // 5

    if (SearchForMeaning(cpWinWin1, n)){
      printf("\n");
      for (i=0; i<n; i++){
        cpWinWin1[i] = Koi8ToUtf8(cpWinWin1[i]);
        printf("%c", cpWinWin1[i]);
      }
    }
    free (cpWinWin1);

    // 6

    if (SearchForMeaning(cpWinCp1, n)){
      printf("\n");
      for (i=0; i<n; i++){
        cpWinCp1[i] = Koi8ToUtf8(cpWinCp1[i]);
        printf("%c", cpWinCp1[i]);
      }
    }
    free (cpWinCp1);

    // 7

    if (SearchForMeaning(winCpCp1, n)){
      printf("\n");
      for (i=0; i<n; i++){
        winCpCp1[i] = Koi8ToUtf8(winCpCp1[i]);
        printf("%c", winCpCp1[i]);
      }
    }
    free (winCpCp1);

    // 8

    if (SearchForMeaning(winCpWin1, n)){
      printf("\n");
      for (i=0; i<n; i++){
        winCpWin1[i] = Koi8ToUtf8(winCpWin1[i]);
        printf("%c", winCpWin1[i]);
      }
    }
    free (winCpWin1);

  }
  return 0;
}
