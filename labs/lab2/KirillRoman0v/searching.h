#include <string.h>
#include <stdio.h>

int SearchForMeaning(char *array, int n) {
  int i, flag=0;
  float stat;
  // ИЩЕМ СМЫСЛ

  for (i=0; i<n; i++) {
    if (array[i]=='а' || array[i]=='А' || array[i]=='о' || array[i]=='О' ||
        array[i]=='е' || array[i]=='Е' || array[i]=='и' || array[i]=='И' ||
        array[i]=='н' || array[i]=='Н') {
          stat++;
        }
  }

  if ( ((stat / 40 * 100) > (n+10)) && ((stat / 40 * 100) < (n+10))) {
    flag = 1;
  }

  return flag;
}
