#ifndef STUDENT_H
#define STUDENT_H

#define MAX_STUDENTS 100
#define MAX_NAME 50
#define MAX_PROVINCE 50
#define MAX_PHONE 15
#define MAX_MAJOR 50

struct Student {
  int id;               // Auto-generated
  char name[MAX_NAME];
  int age;
  char province[MAX_PROVINCE];
  char phone[MAX_PHONE];
  char major[MAX_MAJOR];
  float math;           // Subject 1
  float science;        // Subject 2
  float english;        // Subject 3
  float average;        // Calculated average
};

#endif