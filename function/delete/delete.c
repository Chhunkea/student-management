#include "delete.h"
#include "../util/util.h"
#include <stdio.h>

void deleteStudent(struct Student students[], int *count) {
  int id;
  int found = 0;

  // Continuously for an ID until a valid one is found or the loop is exited
  while (1) {
    printf("\nEnter Student ID to delete: ");
    scanf("%d", &id);
    clearInputBuffer();

    // Search through the array to find the student with the matching ID
    for (int i = 0; i < *count; i++) {
      if (students[i].id == id) {
        found = 1;

        // Shift the remaining students down in the array
        for (int j = i; j < *count - 1; j++) {
          students[j] = students[j + 1];
        }

        // Decrease the count to reflect the removal of a student
        (*count)--;

        // Save the updated student list to the file
        saveStudents(students, *count);
        printf("Student deleted successfully!\n");
        return;
      }
    }
    printf("Student ID was invalid. Please input again.\n");
  }
}