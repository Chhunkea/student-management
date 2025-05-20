// student_management.h
#ifndef STUDENT_MANAGEMENT_H
#define STUDENT_MANAGEMENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_LINE_LENGTH 256
#define CREDENTIALS_FILE "./store/credentials.txt"
#define STUDENTS_FILE "./store/students_store.txt"

// Structure for student data
struct Student {
    int id;
    char name[MAX_NAME_LENGTH];
    float score;
};

// Structure for credentials
struct Credentials {
    char username[50];
    char password[50];
};

// Function prototypes
void clearInputBuffer();
int validateNumericInput(const char *prompt, int *value, int min, int max);
int validateFloatInput(const char *prompt, float *value, float min, float max);
int validateStringInput(const char *prompt, char *buffer, int max_length);
int checkDuplicateID(int id);
void createStoreDirectory();
void loadCredentials();
void saveCredentials();
int authenticate();
void loadStudents();
void saveStudents();
void addStudent();
void showStudents();
void updateStudent();
void deleteStudent();
void generateGradeReport();
void searchStudentByName();
void updateCredentials();

// Global variable declarations
extern struct Student students[MAX_STUDENTS];
extern int student_count;
extern struct Credentials creds;

#endif