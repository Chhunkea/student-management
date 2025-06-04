Student Management System
This is a simple student management system implemented in C, designed to handle basic CRUD (Create, Read, Update, Delete) operations for student records. The system stores data in a text file (students.txt) and includes an authentication module.
Folder Structure
NEW_FILE_OF_STUDENT_MANAGEMENT/
├── Auth/
│ ├── auth.c
│ └── auth.h
├── function/
│ ├── createStudent.h
│ ├── createStudent.c
│ ├── read.h
│ ├── read.c
│ ├── update.h
│ ├── update.c
│ ├── delete.h
│ ├── delete.c
│ ├── utils.h
│ └── utils.c
├── main.c
├── README.md
├── student_management
├── student.c
├── student.h
└── students.txt

Auth/: Contains authentication-related files (auth.c and auth.h) for user login functionality.
function/: Houses the CRUD operation implementations and utility functions.
create._: Handles adding new students.
read._: Manages displaying student records.
update._: Updates existing student records.
delete._: Deletes student records.
util.\*: Provides utility functions like file I/O and input buffer clearing.

main.c: The main program entry point.
student.c and student.h: Core files defining the Student struct and including function headers.
students.txt: Stores student data in CSV format (ID, Name, Grade).
README.md: This file.

Prerequisites

A C compiler (e.g., gcc).
Basic knowledge of compiling and running C programs.

Setup and Compilation

Clone or download the repository to your local machine.
Navigate to the project directory:cd NEW_FILE_OF_STUDENT_MANAGEMENT

Compile the program using gcc:gcc main.c Auth/auth.c function/\*.c -o student_management

Run the compiled executable:./student_management

Usage

Authentication: The program starts with a login function defined in auth.c. Follow the prompts to log in.
Menu Options: After logging in, you can:
Add a new student (via create.c).
Display all students (via read.c).
Update a student's details (via update.c).
Delete a student (via delete.c).
Data is saved to and loaded from students.txt using utility functions in util.c.

Follow the on-screen prompts to input student details (ID, Name, Grade).


Chhunkea
