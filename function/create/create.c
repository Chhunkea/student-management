#include "create.h"
#include "../util/util.h"
#include <stdio.h>
#include <string.h>

void addStudent(struct Student students[], int *count) {
  if (*count >= MAX_STUDENTS) {
    printf("Cannot add more students. Limit reached.\n");
    return;
  }

  printf("\nEnter Student ID: ");
  scanf("%d", &students[*count].id);
  clearInputBuffer();

  printf("Enter Student Name: ");
  fgets(students[*count].name, MAX_NAME, stdin);
  students[*count].name[strcspn(students[*count].name, "\n")] = 0;

  printf("Enter Student Grade (0-100): ");
  scanf("%f", &students[*count].grade);
  clearInputBuffer();

  (*count)++;
  saveStudents(students, *count);
  printf("Student added successfully!\n");
}