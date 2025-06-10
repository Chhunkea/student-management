#include "create.h"
#include "../util/util.h"
#include <stdio.h>
#include <string.h>

void addStudent(struct Student students[], int *count) {
  if (*count >= MAX_STUDENTS) {
    printf("Cannot add more students. Limit reached.\n");
    return;
  }

  // Generate new unique ID by incrementing it
  int newId = 1;
  for (int i = 0; i < *count; i++) {
    if (students[i].id >= newId)
      newId = students[i].id + 1;
  }
  students[*count].id = newId;

  // Display the auto-generated student ID to the user
  printf("\nAuto-generated Student ID: %d\n", students[*count].id);

  // Read the student's name, removing the newline character
  printf("Enter Student Name: ");
  fgets(students[*count].name, MAX_NAME, stdin);
  students[*count].name[strcspn(students[*count].name, "\n")] = 0;

  // Read the student's age, clearing the input buffer afterward
  printf("Enter Student Age: ");
  scanf("%d", &students[*count].age);
  clearInputBuffer();

  // Read the student's province, removing the newline character
  printf("Enter Student Province: ");
  fgets(students[*count].province, MAX_PROVINCE, stdin);
  students[*count].province[strcspn(students[*count].province, "\n")] = 0;

  printf("Enter Student Phone Number: ");
  fgets(students[*count].phone, MAX_PHONE, stdin);
  students[*count].phone[strcspn(students[*count].phone, "\n")] = 0;

  printf("Enter Student Sex: ");
  fgets(students[*count].major, MAX_MAJOR, stdin);
  students[*count].major[strcspn(students[*count].major, "\n")] = 0;

  printf("Enter Math Grade (0-100): ");
  scanf("%f", &students[*count].math);
  clearInputBuffer();

  printf("Enter Science Grade (0-100): ");
  scanf("%f", &students[*count].science);
  clearInputBuffer();

  printf("Enter English Grade (0-100): ");
  scanf("%f", &students[*count].english);
  clearInputBuffer();

  // Calculate the average grade
  students[*count].average = (students[*count].math + students[*count].science +
                              students[*count].english) /
                             3.0;
                             
  // Increment the student count and save the updated student list to file
  (*count)++;
  saveStudents(students, *count);
  printf("Student added successfully!\n");
}