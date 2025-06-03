#include "read.h"
#include <stdio.h>

void displayStudents(struct Student students[], int count) {
  if (count == 0) {
    printf("\nNo students to display.\n");
    return;
  }

  printf("\nStudent List:\n");
  printf("ID\tName\t\tGrade\n");
  printf("--------------------------------\n");
  for (int i = 0; i < count; i++) {
    printf("%d\t%s\t\t%.2f\n", students[i].id, students[i].name, students[i].grade);
  }
}