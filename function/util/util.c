#include "util.h"
#include <stdio.h>
#include <string.h>

void clearInputBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

void loadStudents(struct Student students[], int *count) {
  FILE *file = fopen("students.txt", "r");
  if (file == NULL) {
    *count = 0;
    return;
  }

  *count = 0;
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
}

void saveStudents(struct Student students[], int count) {
  FILE *file = fopen("students.txt", "w");
  if (file == NULL) {
    printf("Error saving to file.\n");
    return;
  }

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
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error: Could not open file %s for import.\n", filename);
    return;
  }

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
  saveStudents(students, *count);
  printf("Successfully imported students from %s.\n", filename);
}