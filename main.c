// main.c
#include "student_management.h"

int main() {
    createStoreDirectory();
    loadCredentials();
    if (!authenticate()) return 1; // Exit if authentication fails

    loadStudents(); // Load student data

    int choice;
    do {
        printf("\n=== Student Management System ===\n");
        printf("1. Add Student\n");
        printf("2. Show Students\n");
        printf("3. Update Student\n");
        printf("4. Delete Student\n");
        printf("5. Generate Grade Report\n");
        printf("6. Search Student by Name\n");
        printf("7. Update Credentials\n");
        printf("8. Exit\n");
        if (!validateNumericInput("Enter choice: ", &choice, 1, 8)) continue;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: showStudents(); break;
            case 3: updateStudent(); break;
            case 4: deleteStudent(); break;
            case 5: generateGradeReport(); break;
            case 6: searchStudentByName(); break;
            case 7: updateCredentials(); break;
            case 8: 
                saveStudents();
                printf("Goodbye!\n");
                break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 8);

    return 0;
}