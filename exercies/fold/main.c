#include <stdio.h>
#include <string.h>

#define MAX 100
#define LONGTXT 10

int main() {
  char text[MAX] = "";
  char lines[MAX][MAX] = {};
  int linesindex = 0;

  char c;
  int index = 0;
  int spaceindex = -1;

  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      strcpy(lines[linesindex], text);
      memset(text, 0, strlen(text));
      index = 0;
      linesindex++;
      spaceindex = -1;
    } else {
      text[index] = c;
      index++;

      if (index >= LONGTXT && spaceindex == -1) {
        strcpy(lines[linesindex], text);
        memset(text, 0, strlen(text));
        linesindex++;
        index = 0;
      } else if (index >= LONGTXT && spaceindex > -1) {
        char temp[MAX] = "";

        for (int i = 0; i < spaceindex - 1; i++) {
          if (i == spaceindex && text[i] == ' ') {
            continue;
          }

          temp[i] = text[i];
        }

        strcpy(lines[linesindex], temp);
        linesindex++;
        memset(temp, 0, strlen(temp));

        if (index > spaceindex) {
          int j = 0;
          for (int i = spaceindex; i < index; i++) {
            if (i == index && text[i] == ' ') {
              continue;
            }

            temp[j] = text[i];
            j++;
          }

          printf("\nJ: %d\n", j);
          memset(text, 0, strlen(text));
          strcpy(text, temp);
          index = j;
        } else {
          memset(text, 0, strlen(text));
          index = 0;
        }

        spaceindex = -1;
      } else if (c == ' ') {
        spaceindex = index;
      }
    }
  }

  if (index > 0) {
    strcpy(lines[linesindex++], text);
  }

  for (int i = 0; i < linesindex; i++) {
    if (lines[i][strlen(lines[i]) - 1] == ' ') {
      lines[i][strlen(lines[i]) - 1] = 0;
    }
  }

  printf("\n");
  for (int i = 0; i < linesindex; i++) {
    printf("%s\"\n", lines[i]);
  }

  return 0;
}
