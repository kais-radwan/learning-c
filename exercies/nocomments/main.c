#include <stdio.h>

#define MAX 1000

int main() {

  char c;
  char last;
  char text[MAX];
  int index = 0;
  int commented = 0;
  int escaped = 0;
  char escape;

  while ((c = getchar()) != EOF) {
    if (commented == 1 && c == '\n') {
      text[index] = '\n';
      commented = 0;
      index++;
    } else if (c == '/' && last == '/' && escaped == 0) {
      commented = 1;
      text[index--] = 0;
      if (text[index - 1] == '\n') {
        text[index--] = 0;
      }
    } else if (escaped == 1 && escape == c && last != '\\') {
      escaped = 0;
      escape = 0;
      text[index] = c;
      index++;
    } else if ((c == '\"' || c == '\'') && commented == 0) {
      escaped = 1;
      escape = c;
      text[index] = c;
      index++;
    } else if (commented == 0) {
      text[index] = c;
      index++;
    }

    last = c;
  }

  text[index] = '\0';

  printf("\n%s\n", text);

  return 0;
}
