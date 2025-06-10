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

    // Search through the array to find the student with the matching ID
    for (int i = 0; i < count; i++) {
      if (students[i].id == id) {
        found = 1;

        // Update the student's name, removing the newline character
        printf("Enter New Student Name: ");
        fgets(students[i].name, MAX_NAME, stdin);
        students[i].name[strcspn(students[i].name, "\n")] = 0;

        // Update the student's age, clearing the input buffer afterward
        printf("Enter New Student Age: ");
        scanf("%d", &students[i].age);
        clearInputBuffer();

        printf("Enter New Student Province: ");
        fgets(students[i].province, MAX_PROVINCE, stdin);
        students[i].province[strcspn(students[i].province, "\n")] = 0;

        printf("Enter New Student Phone Number: ");
        fgets(students[i].phone, MAX_PHONE, stdin);
        students[i].phone[strcspn(students[i].phone, "\n")] = 0;

        printf("Enter New Student Major: ");
        fgets(students[i].major, MAX_MAJOR, stdin);
        students[i].major[strcspn(students[i].major, "\n")] = 0;

        printf("Enter New Math Grade (0-100): ");
        scanf("%f", &students[i].math);
        clearInputBuffer();

        printf("Enter New Science Grade (0-100): ");
        scanf("%f", &students[i].science);
        clearInputBuffer();

        printf("Enter New English Grade (0-100): ");
        scanf("%f", &students[i].english);
        clearInputBuffer();

        // Calculate average
        students[i].average =
            (students[i].math + students[i].science + students[i].english) /
            3.0;

        // Save the updated student list to the file
        saveStudents(students, count);
        printf("Student info updated successfully!\n");
        return;
      }
    }
    printf("Student ID was invalid. Please input again.\n");
  }
}