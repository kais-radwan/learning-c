#include <stdio.h>

int main() {

  int arr[] = {0, 1, 2};

  printf("Enter your name: ");
  char name[20];
  fgets(name, 20, stdin);

  printf("Enter your age: ");
  int age;
  scanf("%d", &age);

  printf("Hello world, %s, %d!\n", name, age);


  return 0;

}
