// student/update_student.c
#include "../student_management.h"

void updateStudent() {
    int id;
    if (!validateNumericInput("Enter ID to update: ", &id, 1, 9999)) return;
    int index = -1;
    for (int i = 0; i < student_count; i++) {
        if (students[i].id == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Student with ID %d not found.\n", id);
        return;
    }
    printf("Student found: ID: %d, Name: %s, Score: %.2f\n", students[index].id, students[index].name, students[index].score);
    if (!validateStringInput("Enter new Name: ", students[index].name, MAX_NAME_LENGTH)) return;
    if (!validateFloatInput("Enter new Score (0.0-10.0): ", &students[index].score, 0.0, 10.0)) return;
    printf("Student updated successfully!\n");
}