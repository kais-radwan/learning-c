#include <stdio.h>

double transition(double);

int main() {

  double cel = transition(20);
  printf("%f", cel);

  return 0;
}

double transition(double f) { return 5 * (f - 32) / 9; }
