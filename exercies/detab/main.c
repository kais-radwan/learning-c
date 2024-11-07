#include <stdio.h>

#define NSPACE 8
#define MAXTEXT 64

int main() {
  char c;
  char text[MAXTEXT] = {};
  int index = 0;
  int cursor = 0;

  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      int count = NSPACE - (cursor % NSPACE);

      for (int i = 0; i < count; i++) {
        text[index] = ' ';
        index++;
        cursor++;
      }
    } else {
      text[index] = c;
      index++;
      cursor++;
    }

    if (c == '\n') {
      cursor = 0;
    }
  }

  printf("\n%s\n", text);

  return 0;
}
