// student/delete_student.c
#include "../student_management.h"

void deleteStudent() {
    int id;
    if (!validateNumericInput("Enter ID to delete: ", &id, 1, 9999)) return;
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
    for (int i = index; i < student_count - 1; i++) {
        students[i] = students[i + 1];
    }
    student_count--;
    printf("Student deleted successfully!\n");
}