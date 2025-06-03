#include "delete.h"
#include "../util/util.h"
#include <stdio.h>

void deleteStudent(struct Student students[], int *count) {
  int id;
  int found = 0;

  while (1) {
    printf("\nEnter Student ID to delete: ");
    scanf("%d", &id);
    clearInputBuffer();

    for (int i = 0; i < *count; i++) {
      if (students[i].id == id) {
        found = 1;
        for (int j = i; j < *count - 1; j++) {
          students[j] = students[j + 1];
        }
        (*count)--;
        saveStudents(students, *count);
        printf("Student deleted successfully!\n");
        return;
      }
    }
    printf("Student ID was invalid. Please input again.\n");
  }
}