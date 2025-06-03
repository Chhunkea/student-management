#ifndef UTILS_H
#define UTILS_H

#include "../../student.h"

void clearInputBuffer();
void loadStudents(struct Student students[], int *count);
void saveStudents(struct Student students[], int count);

#endif