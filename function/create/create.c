#include "create.h"
#include "../util/util.h"
#include <stdio.h>
#include <string.h>

void addStudent(struct Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Cannot add more students. Limit reached.\n");
        return;
    }

    int newId = 1;
    for (int i = 0; i < *count; i++) {
        if (students[i].id >= newId) newId = students[i].id + 1;
    }
    students[*count].id = newId;

    printf("\nAuto-generated Student ID: %d\n", students[*count].id);

    printf("Enter Student Name: ");
    fgets(students[*count].name, MAX_NAME, stdin);
    students[*count].name[strcspn(students[*count].name, "\n")] = 0;

    printf("Enter Student Age: ");
    scanf("%d", &students[*count].age);
    clearInputBuffer(); // Clear buffer after scanf

    printf("Enter Student Province: ");
    fgets(students[*count].province, MAX_PROVINCE, stdin);
    students[*count].province[strcspn(students[*count].province, "\n")] = 0;

    printf("Enter Student Phone Number: ");
    fgets(students[*count].phone, MAX_PHONE, stdin);
    students[*count].phone[strcspn(students[*count].phone, "\n")] = 0;

    printf("Enter Student School: ");
    fgets(students[*count].major, MAX_MAJOR, stdin);
    students[*count].major[strcspn(students[*count].major, "\n")] = 0;

    printf("Enter Math Grade (0-100): ");
    scanf("%f", &students[*count].math);
    clearInputBuffer(); // Clear buffer after scanf

    printf("Enter Science Grade (0-100): ");
    scanf("%f", &students[*count].science);
    clearInputBuffer(); // Clear buffer after scanf

    printf("Enter English Grade (0-100): ");
    scanf("%f", &students[*count].english);
    clearInputBuffer(); // Clear buffer after scanf

    students[*count].average = (students[*count].math + students[*count].science + students[*count].english) / 3.0;

    (*count)++;
    saveStudents(students, *count);
    printf("Student added successfully!\n");
}