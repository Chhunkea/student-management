#include "read.h"
#include <stdio.h>
#include <string.h>
#include <strings.h> // For strcasecmp

void displayStudents(struct Student students[], int count) {
  if (count == 0) {
    printf("\nNo students to display.\n");
    return;
  }

  printf("\nStudent List:\n");
  printf("%-8s %-20s %-8s %-20s %-15s %-20s %-10s %-10s %-10s %-10s\n", "ID",
         "Name", "Age", "Province", "Phone", "Major", "Math", "Science",
         "English", "Average");
  printf("---------------------------------------------------------------------"
         "---------------------------\n");
  for (int i = 0; i < count; i++) {
    printf(
        "%-8d %-20s %-8d %-20s %-15s %-20s %-10.2f %-10.2f %-10.2f %-10.2f\n",
        students[i].id, students[i].name, students[i].age, students[i].province,
        students[i].phone, students[i].major, students[i].math,
        students[i].science, students[i].english, students[i].average);
  }
}

void searchStudentById(struct Student students[], int count, int id) {
  int found = 0;
  for (int i = 0; i < count; i++) {
    if (students[i].id == id) {
      printf("\nStudent Found:\n");
      printf("%-8s %-20s %-8s %-20s %-15s %-20s %-10s %-10s %-10s %-10s\n",
             "ID", "Name", "Age", "Province", "Phone", "Major", "Math",
             "Science", "English", "Average");
      printf("-----------------------------------------------------------------"
             "-------------------------------\n");
      printf(
          "%-8d %-20s %-8d %-20s %-15s %-20s %-10.2f %-10.2f %-10.2f %-10.2f\n",
          students[i].id, students[i].name, students[i].age,
          students[i].province, students[i].phone, students[i].major,
          students[i].math, students[i].science, students[i].english,
          students[i].average);
      found = 1;
      break;
    }
  }
  if (!found) {
    printf("\nStudent with ID %d not found.\n", id);
  }
}

void searchStudentByProvince(struct Student students[], int count,
                             const char *province) {
  int found = 0;
  printf("\nStudents in %s:\n", province);
  printf("%-8s %-20s %-8s %-20s %-15s %-20s %-10s %-10s %-10s %-10s\n", "ID",
         "Name", "Age", "Province", "Phone", "Major", "Math", "Science",
         "English", "Average");
  printf("---------------------------------------------------------------------"
         "---------------------------\n");
  for (int i = 0; i < count; i++) {
    if (strcasecmp(students[i].province, province) == 0) {
      printf(
          "%-8d %-20s %-8d %-20s %-15s %-20s %-10.2f %-10.2f %-10.2f %-10.2f\n",
          students[i].id, students[i].name, students[i].age,
          students[i].province, students[i].phone, students[i].major,
          students[i].math, students[i].science, students[i].english,
          students[i].average);
      found = 1;
    }
  }
  if (!found) {
    printf("No students found in %s.\n", province);
  }
}