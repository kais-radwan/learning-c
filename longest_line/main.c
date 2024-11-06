#include <stdio.h>
#include <string.h>

#define MAX 1000

int getnewline(char s[], int);
void copy(char[], char[]);
void reverse(char[]);

int main() {
  int len;
  int max;
  char line[MAX];
  char longest[MAX];
  char lines[MAX][MAX] = {};
  int lines_l[MAX] = {};
  int lines_i = 0;

  max = 0;
  while ((len = getnewline(line, MAX)) > 0) {
    if (len > max) {
      max = len;
      copy(longest, line);
    }

    strcpy(lines[lines_i], line);
    lines_l[lines_i] = len;
    lines_i++;
  }

  if (max > 0) {
    printf("\nLongest: %s\n", longest);
    reverse(longest);
    printf("Longest reverse: %s\n", longest);
  }

  printf("\nlines longer than 80 characters:\n");
  for (int i = 0; i < lines_i; i++) {
    if (lines_l[i] > 80) {
      printf("%s\n", lines[i]);
    }
  }

  return 0;
}

int getnewline(char s[], int lim) {
  int c, i;
  int wrote = 0;

  for (i = 0; (c = getchar()) != EOF && c != '\n' && c != '\b'; i++) {
    if (i < lim - 1 && !(wrote == 0 && c == ' ')) {
      s[i] = c;
      wrote = 1;
    }
  }

  if (c == '\n') {
    s[i] = c;
    i++;
  }

  s[i] = '\0';
  return i;
}

void copy(char to[], char from[]) {
  int i = 0;

  for (int i = 0; from[i] != '\0'; i++) {
    to[i] = from[i];
  }
}

void reverse(char s[]) {
  int len = strlen(s);
  int start = 0;
  int end = len - 1;

  char temp;

  while (start < end) {
    temp = s[start];
    s[start] = s[end];
    s[end] = temp;

    start++;
    end--;
  }
}
