#include <stdio.h>
#include <string.h>

#define MAX 1000

int define_errors(char, char[], int, char[], int);

int main() {

  char c;
  char last;

  char openers[3] = {'{', '(', '['};
  char closers[3] = {'}', ')', ']'};

  int escaped = 0;
  int quoted = 0;
  int commented = 0;

  char opened[MAX];
  int opened_index = 0;

  char closed[MAX];
  char closed_index = 0;

  char open_store[MAX];
  int open_store_index = 0;

  char close_store[MAX];
  int close_store_index = 0;

  char not_closed[MAX];
  int not_closed_index = 0;

  char errors[MAX];
  int errors_index = 0;

  while ((c = getchar()) != EOF) {
    if (commented == 1 && c == '\n') {
      commented = 0;
    } else if (c == '/' && last == '/' && quoted == 0) {
      commented = 1;
    } else if ((c == '\"' || c == '\'') && last != '\\' && commented == 0) {
      if (quoted == 0) {
        quoted = 1;
        opened[opened_index] = c;
        opened_index++;
        errors[errors_index] = c;
        errors_index++;
      } else {
        quoted = 0;
        closed[closed_index] = c;
        closed_index++;
        opened[opened_index--] = 0;

        int j = define_errors(c, not_closed, not_closed_index, errors,
                              errors_index);

        errors_index = j;
      }
    } else if (quoted == 1 && c == '\n' && last != '\\') {
      printf("\n\033[0;31m x");
      printf("\033[0;37m Syntax error: \n\tdidn't close %c\n",
             opened[opened_index - 1]);
      return 0;
    } else if (commented == 0) {
      int is_opener = -1;
      int is_closer = -1;

      for (int i = 0; i < 3; i++) {
        if (openers[i] == c) {
          is_opener = i;
        }
      }

      for (int i = 0; i < 3; i++) {
        if (closers[i] == c) {
          is_closer = i;
        }
      }

      if (is_opener != -1 && quoted == 0) {
        opened[opened_index] = c;
        opened_index++;
        not_closed[not_closed_index] = c;
        not_closed_index++;
        open_store_index++;
      }

      if (is_closer != -1 && quoted == 0) {
        int opener;
        close_store_index++;

        for (int i = 0; i < 3; i++) {
          if (openers[i] == opened[opened_index - 1]) {
            opener = i;
          }
        }

        if (opener != is_closer) {
          printf("\n\033[0;31m x");
          printf("\033[0;37m Syntax error: \n\t%c closed before %c\n",
                 closers[is_closer], openers[opener]);
          return 0;
        } else {
          opened[opened_index - 1] = 0;
          opened_index--;
          not_closed[not_closed_index--] = 0;

          int j = define_errors(c, not_closed, not_closed_index, errors,
                                errors_index);
          errors_index = j;
        }
      }
    }

    last = c;
  }

  if (quoted == 1) {
    printf("\nSyntax error, didn't close %c\n", opened[opened_index - 1]);
    return 0;
  }

  if (open_store_index != close_store_index) {
    printf("\n\033[0;31m x");
    printf("\033[0;37m Syntax error: \n\tMake sure all scopes are closed\n");
    return 0;
  }

  if (errors_index > 0) {
    printf("\n\033[0;31m x");
    printf("\033[0;37m Syntax error(s):\n");

    for (int i = 0; i < errors_index; i++) {
      printf("\tdidn't close %c\n", errors[i]);
    }

  } else {
    printf("\nThere is no errors\n");
  }

  return 0;
}

int define_errors(char c, char not_closed[], int not_closed_index,
                  char errors[], int errors_index) {
  char temp[MAX];
  int did = 0;
  int j = 0;

  for (int i = 0; i < not_closed_index; i++) {
    if (not_closed[i] != c || did == 0) {
      temp[j] = not_closed[i];
      j++;
    } else if (not_closed[i] == c) {
      did = 1;
    }
  }

  memset(errors, 0, errors_index);
  strcpy(errors, temp);

  return j;
}
