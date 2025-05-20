// student/show_students.c
#include "../student_management.h"

void showStudents() {
    if (student_count == 0) {
        printf("No students to display.\n");
        return;
    }
    printf("\n--- Student List ---\n");
    for (int i = 0; i < student_count; i++) {
        printf("ID: %d, Name: %s, Score: %.2f\n", students[i].id, students[i].name, students[i].score);
    }
}