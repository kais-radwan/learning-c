#include <stdio.h>
#include <string.h>

#define MAX 64

void squeeze(char s1[], char s2[]) {
  char res[64];
  int resindex = 0;
  char found[64][64] = {};

  for (int i = 0; i < strlen(s1); i++) {
    int valid = 1;

    if (s1[i] == '\0')
      break;

    for (int j = 0; j < strlen(s2); j++) {
      if (s1[i] == s2[j]) {
        valid = 0;
        break;
      }
    }

    if (valid) {
      res[resindex] = s1[i];
      resindex++;
    }
  }

  memset(s1, 0, strlen(s1));
  res[resindex] = '\0';

  if (resindex) {
    strcpy(s1, res);
  } else {
    strcpy(s1, "");
  }
}

int main() {

  char s1[64];
  char s2[64];

  printf("\nFirst string: ");
  scanf("%s", s1);

  printf("\nSecond string: ");
  scanf("%s", s2);

  squeeze(s1, s2);
  printf("Result: %s\n", s1);

  return 0;
}
