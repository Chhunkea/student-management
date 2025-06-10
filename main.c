#include "./Auth/auth.h"
#include "./function/create/create.h"
#include "./function/delete/delete.h"
#include "./function/read/read.h"
#include "./function/update/update.h"
#include "./function/util/util.h"
#include "student.h"
#include <stdio.h>
#include <string.h>

int main() {
  struct Student students[MAX_STUDENTS];
  int count = 0;
  int choice;
  char filename[100];
  int searchId;
  char searchProvince[MAX_PROVINCE];

  // Load students from file at the start
  loadStudents(students, &count);

  // Check login
  if (!login()) {
    printf("Invalid login. Exiting program.\n");
    return 1;
  }

  // Main menu loop
  while (1) {
    printf("\nStudent Management System\n");
    printf("1. Add Student\n");
    printf("2. Display Students\n");
    printf("3. Update Student\n");
    printf("4. Delete Student\n");
    printf("5. Import Students from File\n");
    printf("6. Search Student by ID\n");
    printf("7. Search Students by Province\n");
    printf("8. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    clearInputBuffer();

    switch (choice) {
    case 1:
      addStudent(students, &count);
      break;
    case 2:
      displayStudents(students, count);
      break;
    case 3:
      if (count == 0) {
        printf("\nNo students to update.\n");
      } else {
        updateStudent(students, count);
      }
      break;
    case 4:
      if (count == 0) {
        printf("\nNo students to delete.\n");
      } else {
        deleteStudent(students, &count);
      }
      break;
    case 5:
      printf("Enter the filename to import from: ");
      fgets(filename, 100, stdin);
      filename[strcspn(filename, "\n")] = 0;
      importStudentsFromFile(students, &count, filename);
      break;
    case 6:
      if (count == 0) {
        printf("\nNo students to search.\n");
      } else {
        printf("Enter Student ID to search: ");
        scanf("%d", &searchId);
        clearInputBuffer();
        searchStudentById(students, count, searchId);
      }
      break;
    case 7:
      if (count == 0) {
        printf("\nNo students to search.\n");
      } else {
        printf("Enter Province to search: ");
        fgets(searchProvince, MAX_PROVINCE, stdin);
        searchProvince[strcspn(searchProvince, "\n")] = 0;
        searchStudentByProvince(students, count, searchProvince);
      }
      break;
    case 8:
      printf("Exiting program.\n");
      return 0;
    default:
      printf("Invalid choice. Please try again.\n");
    }
  }
  return 0;
}