#include "update.h"
#include "../util/util.h"
#include <stdio.h>
#include <string.h>

void updateStudent(struct Student students[], int count) {
  int id;
  int found = 0;

  while (1) {
    printf("\nEnter Student ID to update: ");
    scanf("%d", &id);
    clearInputBuffer();

    for (int i = 0; i < count; i++) {
      if (students[i].id == id) {
        found = 1;
        printf("Enter New Student Name: ");
        fgets(students[i].name, MAX_NAME, stdin);
        students[i].name[strcspn(students[i].name, "\n")] = 0;

        printf("Enter New Student Grade (0-100): ");
        scanf("%f", &students[i].grade);
        clearInputBuffer();

        saveStudents(students, count);
        printf("Student info updated successfully!\n");
        return;
      }
    }
    printf("Student ID was invalid. Please input again.\n");
  }
}