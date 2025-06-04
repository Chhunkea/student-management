# Student Management System

This is a simple Student Management System implemented in **C**, designed to handle basic CRUD (Create, Read, Update, Delete) operations for student records. The system stores data in a text file (`students.txt`) and includes an authentication module.

## Folder Structure

```plaintext
NEW_FILE_OF_STUDENT_MANAGEMENT/
├── Auth/
│   ├── auth.c
│   └── auth.h
├── function/
│   ├── createStudent.c
│   ├── createStudent.h
│   ├── read.c
│   ├── read.h
│   ├── update.c
│   ├── update.h
│   ├── delete.c
│   ├── delete.h
│   ├── utils.c
│   └── utils.h
├── main.c
├── README.md
├── student_management
├── student.c
├── student.h
└── students.txt


## Running Tests

To run tests, run the following command

```bash
  ./student_management
```

## Functionality information

- **Auth/**: Contains authentication-related files (`auth.c` and `auth.h`) for user login functionality.
- **function/**: Houses the CRUD operation implementations and utility functions.
  - `createStudent.*`: Handles adding new students.
  - `read.*`: Manages displaying student records.
  - `update.*`: Updates existing student records.
  - `delete.*`: Deletes student records.
  - `utils.*`: Provides utility functions like file I/O and input buffer clearing.
- **main.c**: The main program entry point.
- **student.c** and **student.h**: Core files defining the `Student` struct and including function headers.
- **students.txt**: Stores student data in CSV format (`ID, Name, Grade`).

## Usage

- **Authentication**: The program starts with a login function defined in `auth.c`. Follow the prompts to log in.
- **Menu Options**: After logging in, you can:
  - **Add a new student** (via `createStudent.c`).
  - **Display all students** (via `read.c`).
  - **Update a student’s details** (via `update.c`).
  - **Delete a student** (via `delete.c`).
- Data is saved to and loaded from `students.txt` using utility functions in `utils.c`.

## Author

Chhunkea