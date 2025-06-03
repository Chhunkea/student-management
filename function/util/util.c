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
         fscanf(file, "%d,%[^,],%f\n", &students[*count].id,
                students[*count].name, &students[*count].grade) == 3) {
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
    fprintf(file, "%d,%s,%.2f\n", students[i].id, students[i].name,
            students[i].grade);
  }

  fclose(file);
}