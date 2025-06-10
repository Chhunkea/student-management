# Student Management System

This is a simple Student Management System implemented in **C**, designed to handle basic CRUD (Create, Read, Update, Delete) operations for student records. The system stores data in a text file (`students.txt`) and includes an authentication module.

## Folder Structure

````plaintext
New file of student managemnet/
├── Auth/
│   ├── auth.c
│   └── auth.h
├── function/
│   ├── create/
│   │   ├── create.c
│   │   └── create.h
│   ├── delete/
│   │   ├── delete.c
│   │   └── delete.h
│   ├── read/
│   │   ├── read.c
│   │   └── read.h
│   ├── update/
│   │   ├── update.c
│   │   └── update.h
│   ├── util/
│   │   ├── util.c
│   │   └── util.h
├── main.c
├── README.md
├── student.c
├── student.h
├── students.txt
└── student_management


## Running Tests

To run tests, run the following command

```bash
  rm student_management
  gcc main.c ./Auth/auth.c function/create/create.c function/delete/delete.c function/read/read.c function/update/update.c function/util/util.c -o student_management

  ./student_management
````

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
- **students.txt**: Stores student data in CSV format (`ID,Name,Age,Province,Phone,Major,Math,Science,English`).

## Usage

- **Authentication**: The program starts with a login function defined in `auth.c`. Follow the prompts to log in.
- **Menu Options**: After logging in, you can:
  - **Add a new student** (via `Inputs student details including name, age, province, phone, field of study, and grades for math, science, and english (auto-generates ID).`).
  - **Display all students** (via `Views all students in a tabulated format.`).
  - **Update a student’s details** (via `Modifies existing student details by ID.`).
  - **Delete a student** (via `Removes a student by ID.`).
  - **Import Students from File** (via `Loads student data from an external CSV file.c`).
  - **Search Student by ID** (via `Finds a student by their ID.`).
  - **Search Students by Province** (via `Lists students from a specific province.`).
  - **Exit** (via `Terminates the program.`).
- Data is saved to and loaded from `students.txt` using utility functions in `utils.c`.

## Author

Chhunkea

## Update Notes (June 10, 2025)

- **Enhanced with auto-generated student IDs.**
- **Added fields: age, province, phone, sex, and subject grades (math, science, english) with calculated average.**
- **Included import from external files and search by ID/province.**
