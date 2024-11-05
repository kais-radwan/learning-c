#include <stdio.h>

#define IN 1
#define OUT 0

int main() {

  int c, nc, nw, nl;
  int state = OUT;

  int words[32] = {};
  int charss[64] = {};
  int charss_l = 0;
  int charss_i = 0;
  int u_chars[64] = {};

  int all_chars = 0;
  int iword = 0;
  int current_c = 0;

  nc = nw = nl = 0;

  while ((c = getchar()) != EOF) {
    ++nc;
    current_c++;
    words[iword] = current_c;
    int exist = 0;

    if (c != ' ' && c != '\n' && c != '\t') {
      for (int i = 0; i <= charss_l; i++) {
        if (charss[i] == c) {
          exist = 1;
        }
      }

      if (exist == 0) {
        u_chars[charss_i] = c;
        charss_i++;
      }
      charss[charss_l] = c;
      charss_l++;
    }

    if (c == '\n') {
      nl++;
    }

    if (c == ' ' || c == '\n' || c == '\t') {
      state = OUT;
      iword++;
    } else if (state == OUT) {
      state = IN;
      current_c = 0;
      nw++;
    }
  }

  printf("\n");
  for (int i = 0; i <= iword; i++) {
    for (int j = 0; j <= words[i]; j++) {
      printf("*");
    }
    printf("\n");
  }

  int unique_c[64] = {};
  int unique[64] = {};
  int current_t = 0;

  for (int i = 0; i < charss_i; i++) {
    int c = u_chars[i];
    unique_c[i] = c;
    current_t = 0;

    for (int j = 0; j <= charss_l; j++) {
      if (c == charss[j]) {
        current_t++;
      }
    }

    unique[i] = current_t;
  }

  printf("\n---\n");
  for (int i = 0; i < charss_i; i++) {
    printf("%c: ", unique_c[i]);
    for (int j = 0; j < unique[i]; j++) {
      printf("*");
    }
    printf("\n");
  }

  printf("\n");
  printf("%d unique characters\n", charss_i);
  printf("%d characters\n", nc);
  printf("%d words\n", nw);
  printf("%d lines\n", nl);

  return 0;
}
