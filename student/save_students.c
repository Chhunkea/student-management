// student/save_students.c
#include "../student_management.h"

void saveStudents() {
    FILE *file = fopen(STUDENTS_FILE, "w");
    if (file == NULL) {
        printf("Error: Cannot write to students file.\n");
        exit(1);
    }
    for (int i = 0; i < student_count; i++) {
        fprintf(file, "%d %s %.2f\n", students[i].id, students[i].name, students[i].score);
    }
    fclose(file);
}