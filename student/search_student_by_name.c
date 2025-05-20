// student/search_student_by_name.c
#include "../student_management.h"

void searchStudentByName() {
    char name[MAX_NAME_LENGTH];
    if (!validateStringInput("Enter Name to search: ", name, MAX_NAME_LENGTH)) return;
    int found = 0;
    printf("\n--- Search Results ---\n");
    for (int i = 0; i < student_count; i++) {
        if (strstr(students[i].name, name) != NULL) { // Case-sensitive substring search
            printf("ID: %d, Name: %s, Score: %.2f\n", students[i].id, students[i].name, students[i].score);
            found = 1;
        }
    }
    if (!found) {
        printf("No students found with name containing '%s'.\n", name);
    }
}