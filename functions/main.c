#include <stdio.h>

int power(int, int);

int main() {
  int r = power(2, 5);
  printf("%d\n", r);

  return 0;
}

int power(int n, int m) {
  int r = n;

  for (int i = 1; i < m; i++) {
    r = r * n;
  }

  return r;
}
