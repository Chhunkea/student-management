#include "read.h"
#include <stdio.h>
#include <strings.h>

void displayStudents(struct Student students[], int count) {
  // Check if there are no students to display and exit early if true
  if (count == 0) {
    printf("\nNo students to display.\n");
    return;
  }

  // Print the header for the student list with column labels
  printf("\nStudent List:\n");
  printf("%-8s %-20s %-8s %-20s %-15s %-20s %-10s %-10s %-10s %-10s\n", "ID",
         "Name", "Age", "Province", "Phone", "Sex", "Math", "Science",
         "English", "Average");
  printf("---------------------------------------------------------------------"
         "---------------------------\n");

  // Iterate through all students and print their details in a formatted table
  for (int i = 0; i < count; i++) {
    printf(
        "%-8d %-20s %-8d %-20s %-15s %-20s %-10.2f %-10.2f %-10.2f %-10.2f\n",
        students[i].id, students[i].name, students[i].age, students[i].province,
        students[i].phone, students[i].major, students[i].math,
        students[i].science, students[i].english, students[i].average);
  }
}

void searchStudents(struct Student students[], int count,
                    const void *searchValue, int searchById,
                    const char *searchLabel) {
  // Initialize flag to track if any students are found
  int found = 0;

  // Print the header with the search context and column labels
  printf("\nStudents with %s %s:\n", searchLabel,
         searchById ? "ID" : "Province");
  printf("%-8s %-20s %-8s %-20s %-15s %-20s %-10s %-10s %-10s %-10s\n", "ID",
         "Name", "Age", "Province", "Phone", "Sex", "Math", "Science",
         "English", "Average");
  printf("---------------------------------------------------------------------"
         "---------------------------\n");

  // Iterate through all students to find matches based on the search criterion
  for (int i = 0; i < count; i++) {
    int match = 0;
    if (searchById) {
      // Compare student ID with the search value
      if (students[i].id == *((int *)searchValue)) {
        match = 1;
      }
    } else {
      // Compare province (case-insensitive) with the search value
      if (strcasecmp(students[i].province, (char *)searchValue) == 0) {
        match = 1;
      }
    }

    if (match) {
      // Print the details of the matching student
      printf(
          "%-8d %-20s %-8d %-20s %-15s %-20s %-10.2f %-10.2f %-10.2f %-10.2f\n",
          students[i].id, students[i].name, students[i].age,
          students[i].province, students[i].phone, students[i].major,
          students[i].math, students[i].science, students[i].english,
          students[i].average);
      found = 1;
      if (searchById) {
        break; // Stop after finding the first match for ID search
      }
    }
  }

  // Notify the user if no students were found
  if (!found) {
    printf("No students found with %s %s.\n", searchLabel,
           searchById ? "ID" : "Province");
  }
}

void searchStudentById(struct Student students[], int count, int id) {
  // Search function for ID-based search
  searchStudents(students, count, &id, 1, "ID");
}

void searchStudentByProvince(struct Student students[], int count,
                             const char *province) {
  // Search function for province-based search
  searchStudents(students, count, province, 0, "Province");
}