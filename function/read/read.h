#ifndef READ_H
#define READ_H

#include "../../student.h"

void displayStudents(struct Student students[], int count);
void searchStudentById(struct Student students[], int count, int id);
void searchStudentByProvince(struct Student students[], int count, const char *province);


#endif