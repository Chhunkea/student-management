#include "util.h"
#include <stdio.h>
#include <string.h>

// Clear the input buffer by reading characters until EOF is encountered
void clearInputBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

void loadStudents(struct Student students[], int *count) {
  // Open the students.txt file in read mode
  FILE *file = fopen("students.txt", "r");
  if (file == NULL) {
    // If file cannot be opened, set count to 0 and exit
    *count = 0;
    return;
  }

  // Initialize count to 0 for a fresh load
  *count = 0;

  // Read student records from the file until MAX_STUDENTS is reached or EOF
  while (*count < MAX_STUDENTS &&
         fscanf(file, "%d,%[^,],%d,%[^,],%[^,],%[^,],%f,%f,%f\n",
                &students[*count].id, students[*count].name,
                &students[*count].age, students[*count].province,
                students[*count].phone, students[*count].major,
                &students[*count].math, &students[*count].science,
                &students[*count].english) == 9) {
    // Calculate the average grade
    students[*count].average =
        (students[*count].math + students[*count].science +
         students[*count].english) /
        3.0;
    (*count)++; // Increment count for the next student
  }

  fclose(file);
}

void saveStudents(struct Student students[], int count) {
  // Open the students.txt file in write mode to overwrite existing data
  FILE *file = fopen("students.txt", "w");
  // If file cannot be opened, print error and exit
  if (file == NULL) {
    printf("Error saving to file.\n");
    return;
  }

  // Write each student's data to the file in CSV format
  for (int i = 0; i < count; i++) {
    fprintf(file, "%d,%s,%d,%s,%s,%s,%.2f,%.2f,%.2f\n", students[i].id,
            students[i].name, students[i].age, students[i].province,
            students[i].phone, students[i].major, students[i].math,
            students[i].science, students[i].english);
  }

  fclose(file);
}

void importStudentsFromFile(struct Student students[], int *count,
                            const char *filename) {
  // Open the specified file in read mode for importing
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error: Could not open file %s for import.\n", filename);
    return;
  }

  // Read student records from the file until MAX_STUDENTS is reached or EOF
  while (*count < MAX_STUDENTS &&
         fscanf(file, "%d,%[^,],%d,%[^,],%[^,],%[^,],%f,%f,%f\n",
                &students[*count].id, students[*count].name,
                &students[*count].age, students[*count].province,
                students[*count].phone, students[*count].major,
                &students[*count].math, &students[*count].science,
                &students[*count].english) == 9) {
    students[*count].average =
        (students[*count].math + students[*count].science +
         students[*count].english) /
        3.0;
    (*count)++;
  }

  fclose(file);
  // Save the updated student list to the default students.txt file
  saveStudents(students, *count);
  printf("Successfully imported students from %s.\n", filename);
}