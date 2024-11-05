#include <stdio.h>
# include <stdlib.h>

int main(int argc, char *argv[]) {
  double num1;
  double num2;
  char p;

  printf("Enter a number: ");
  scanf("%lf", &num1);

  printf("Enter operator: ");
  scanf(" %c", &p);

  printf("Enter another number: ");
  scanf("%lf", &num2);

  if (p == '+') {
    double res = num1 + num2;
    printf("%lf", res);
    
    return EXIT_SUCCESS;
  }

  switch (p) {
  case '-':
    printf("%lf", num1 - num2);
    break;
  case '*':
    printf("%lf", num1 * num2);
    break;
  case '/':
    printf("%lf", num1 / num2);
    break;
  default:
    printf("Invalid operation");
  }

  return EXIT_SUCCESS;
}

