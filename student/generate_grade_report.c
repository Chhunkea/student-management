// student/generate_grade_report.c
#include "../student_management.h"

void generateGradeReport() {
    if (student_count == 0) {
        printf("No students to generate report for.\n");
        return;
    }
    printf("\n--- Grade Report ---\n");
    for (int i = 0; i < student_count; i++) {
        const char *status = students[i].score >= 5.0 ? "Pass" : "Fail";
        printf("ID: %d, Name: %s, Score: %.2f, Status: %s\n", students[i].id, students[i].name, students[i].score, status);
    }
}