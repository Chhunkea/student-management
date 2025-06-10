#ifndef STUDENT_H
#define STUDENT_H

#define MAX_STUDENTS 100
#define MAX_NAME 50
#define MAX_PROVINCE 50
#define MAX_PHONE 15
#define MAX_MAJOR 50

struct Student {
  int id;              
  char name[MAX_NAME];
  int age;
  char province[MAX_PROVINCE];
  char phone[MAX_PHONE];
  char major[MAX_MAJOR];
  float math;          
  float science;        
  float english;        
  float average;        
};

#endif