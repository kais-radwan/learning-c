#include <stdio.h>
#include <string.h>

#define MAX 64

int any(char s1[], char s2[]) {
  int res = -1;

  for (int i = 0; i < strlen(s1); i++) {
    int valid = 0;

    for (int j = 0; j < strlen(s2); j++) {
      if (s1[i] == s2[j]) {
        valid = 1;
        break;
      }
    }

    if (valid) {
      res = i;
      break;
    }
  }

  return res;
}

int main() {
  char s1[MAX], s2[MAX];

  printf("First string: ");
  scanf("%s", s1);

  printf("\nSecond string: ");
  scanf("%s", s2);

  int index = any(s1, s2);
  printf("\nFirst Index: %d\n", index);

  return 0;
}
