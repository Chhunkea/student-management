#ifndef STUDENT_H
#define STUDENT_H

#define MAX_STUDENTS 50
#define MAX_NAME 50

// Define the Student structure
struct Student {
    int id;
    char name[MAX_NAME];
    float grade;
};

// Function prototypes
void clearInputBuffer();
void loadStudents(struct Student students[], int *count);
void saveStudents(struct Student students[], int count);
void addStudent(struct Student students[], int *count);
void displayStudents(struct Student students[], int count);
void updateStudent(struct Student students[], int count);
void deleteStudent(struct Student students[], int *count);

#endif