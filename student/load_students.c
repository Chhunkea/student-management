// student/load_students.c
#include "../student_management.h"

void loadStudents() {
    FILE *file = fopen(STUDENTS_FILE, "r");
    if (file == NULL) return; // File doesn't exist yet
    while (student_count < MAX_STUDENTS) {
        char buffer[MAX_LINE_LENGTH];
        if (fgets(buffer, MAX_LINE_LENGTH, file) == NULL) break;
        int id;
        char name[MAX_NAME_LENGTH];
        float score;
        if (sscanf(buffer, "%d %s %f", &id, name, &score) != 3) continue; // Skip malformed lines
        if (checkDuplicateID(id)) continue; // Skip duplicates
        if (score < 0.0 || score > 10.0) continue; // Skip invalid scores
        students[student_count].id = id;
        strncpy(students[student_count].name, name, MAX_NAME_LENGTH - 1);
        students[student_count].name[MAX_NAME_LENGTH - 1] = '\0';
        students[student_count].score = score;
        student_count++;
    }
    fclose(file);
}