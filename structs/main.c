#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_student {
  char name[50];
  int age;
  double gpa;
};
typedef struct s_student Student;

int main() {
  Student student = {.name = "K", .age = 19, .gpa = 4.5};

  strcpy(student.name, "Kais");

  printf("%d", student.age);
  printf("%s", student.name);

  return EXIT_SUCCESS;
}
