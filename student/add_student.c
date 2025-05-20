// student/add_student.c
#include "../student_management.h"

void addStudent() {
    if (student_count >= MAX_STUDENTS) {
        printf("Error: Maximum student capacity reached (%d).\n", MAX_STUDENTS);
        return;
    }
    int id;
    if (!validateNumericInput("Enter ID (1-9999): ", &id, 1, 9999)) return;
    if (checkDuplicateID(id)) {
        printf("Error: Student ID %d already exists.\n", id);
        return;
    }
    students[student_count].id = id;

    if (!validateStringInput("Enter Name: ", students[student_count].name, MAX_NAME_LENGTH)) return;

    if (!validateFloatInput("Enter Score (0.0-10.0): ", &students[student_count].score, 0.0, 10.0)) return;

    student_count++;
    printf("Student added successfully!\n");
}