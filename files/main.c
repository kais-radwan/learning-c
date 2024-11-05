#include <stdio.h>

int main() {

  FILE * fpointer = fopen("data.txt", "a");
  fprintf(fpointer, "\nI'm Ang");
  fclose(fpointer);

  char line[255];
  FILE * fpointer2 = fopen("data.txt", "r");

  fgets(line, 255, fpointer2);
  printf("%s", line);

  return 0;
}
