#include <stdio.h>
#include "./auth/auth.h"
#include "student.h"

int main() {
    struct Student students[MAX_STUDENTS];
    int count = 0;

    // Load students from file at the start
    loadStudents(students, &count);

    // Check login
    if (!login()) {
        printf("Invalid login. Exiting program.\n");
        return 1;
    }

    // Main menu loop
    int choice;
    while (1) {
        printf("\nStudent Management System\n");
        printf("1. Add New Student\n");
        printf("2. View All Students\n");
        printf("3. Update Student Info\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                if (count == 0) {
                    printf("\nNo students to update.\n");
                } else {
                    updateStudent(students, count);
                }
                break;
            case 4:
                if (count == 0) {
                    printf("\nNo students to delete.\n");
                } else {
                    deleteStudent(students, &count);
                }
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}