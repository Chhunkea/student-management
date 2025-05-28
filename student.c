#include "student.h"
#include <stdio.h>
#include <string.h>

// Function to clear input buffer
void clearInputBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

// Function to load students from file
void loadStudents(struct Student students[], int *count) {
  FILE *file = fopen("students.txt", "r");
  if (file == NULL) {
    // If file doesn't exist, start with an empty list
    *count = 0;
    return;
  }

  *count = 0;
  while (*count < MAX_STUDENTS &&
         fscanf(file, "%d,%[^,],%f\n", &students[*count].id,
                students[*count].name, &students[*count].grade) == 3) {
    (*count)++;
  }

  fclose(file);
}

// Function to save students to file
void saveStudents(struct Student students[], int count) {
  FILE *file = fopen("students.txt", "w");
  if (file == NULL) {
    printf("Error saving to file.\n");
    return;
  }

  for (int i = 0; i < count; i++) {
    fprintf(file, "%d,%s,%.2f\n", students[i].id, students[i].name,
            students[i].grade);
  }

  fclose(file);
}

// Function to add a student
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
  students[*count].name[strcspn(students[*count].name, "\n")] =
      0; // Remove newline

  printf("Enter Student Grade (0-100): ");
  scanf("%f", &students[*count].grade);
  clearInputBuffer();

  (*count)++;
  saveStudents(students, *count);
  printf("Student added successfully!\n");
}

// Function to display all students
void displayStudents(struct Student students[], int count) {
  if (count == 0) {
    printf("\nNo students to display.\n");
    return;
  }

  printf("\nStudent List:\n");
  printf("ID\tName\t\tGrade\n");
  printf("--------------------------------\n");
  for (int i = 0; i < count; i++) {
    printf("%d\t%s\t\t%.2f\n", students[i].id, students[i].name,
           students[i].grade);
  }
}

// Function to update a student
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

// Function to delete a student
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
        // Shift remaining students to fill the gap
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