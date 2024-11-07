#include <stdio.h>

#define NSPACE 8
#define MAXTEXT 64

int main() {
  char c;
  char text[MAXTEXT] = {};
  int index = 0;
  int cursor = 0;
  int blanks = 0;
  char res[MAXTEXT] = {};

  while ((c = getchar()) != EOF) {
    text[index] = c;
    index++;
  }

  text[index] = '\0';
  int resindex = 0;
  for (int in = 0; text[in] != '\0'; in++) {
    char c = text[in];

    if (c != ' ') {
      if (blanks > 0) {
        for (; blanks > 0; blanks--) {
          res[resindex] = ' ';
          resindex++;
        }
      }

      res[resindex] = c;
      resindex++;
      cursor++;
    }

    if (c == '\n') {
      cursor = 0;
    }

    if (c == ' ') {
      blanks++;
      int tabscount = NSPACE - (cursor % NSPACE);

      while (blanks >= tabscount) {
        res[resindex] = '\t';
        resindex++;
        cursor++;
        blanks = blanks - tabscount;
      }
    }
  }

  printf("\n%s\n", res);

  return 0;
}
