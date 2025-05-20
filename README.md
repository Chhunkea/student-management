# Student Management System - Project Report

**Submission Date and Time: 09:18 PM +07, Tuesday, May 20, 2025**  
**Author: Kim Chhunkea**

## Introduction
This project, the Student Management System (SMS), is a C-based console application developed as part of my programming coursework. The system manages student records with features such as adding, viewing, updating, and deleting students, generating grade reports, searching by name, and implementing user authentication. The design emphasizes modularity, zero-bug robustness, and cross-platform compatibility, achieved by separating functionality into individual files within a `student/` directory. This report outlines the project structure, explains each file's role, and reflects on the learning process and technical decisions.

## Project Objectives
- Implement a functional student management system with persistent data storage.
- Apply C programming concepts (structures, file I/O, input validation).
- Practice modular design and code organization.
- Ensure cross-platform compatibility (Windows and Unix-like systems).
- Achieve zero bugs through rigorous validation and error handling.

## System Architecture
The project is organized into:
- `student_management.h`: Central header file with definitions and prototypes.
- `student_management.c`: Main implementation file linking all functions.
- `main.c`: Program entry point with the user interface.
- `student/`: Directory containing individual function files.
- `store/`: Directory for data files (`credentials.txt`, `students_store.txt`).

This modular approach enhances maintainability and scalability, allowing each function to be developed, tested, and modified independently.

## Detailed File Analysis

### 1. `student_management.h`
- **Role**: Defines constants (e.g., `MAX_STUDENTS = 100`), structures (`struct Student`, `struct Credentials`), and function prototypes. Declares global variables (`students`, `student_count`, `creds`) as `extern`.
- **Learning Outcome**: Understanding header files as interfaces and the use of `extern` for global variable sharing.
- **Design Rationale**: Centralizing definitions ensures consistency. Including `sys/stat.h` with conditional `mkdir` supports cross-platform directory creation.

### 2. `student_management.c`
- **Role**: Includes all `.c` files from the `student/` directory and defines global variables.
- **Learning Outcome**: Grasping the importance of a main implementation file to coordinate modular components.
- **Design Rationale**: Using `#include` for `.c` files simplifies the build for a small project, though a Makefile would be preferable for larger systems to compile files separately.

### 3. `main.c`
- **Role**: Contains the `main()` function with a menu-driven loop (options 1-8) to invoke other functions. Handles initialization (directory, authentication, data load) and exit.
- **Learning Outcome**: Mastering program flow control and user interface design in C.
- **Design Rationale**: The menu structure provides an intuitive interface, while input validation via `validateNumericInput` ensures robustness.

### 4. `student/clear_input_buffer.c`
- **Role**: Implements `clearInputBuffer()` to clear the input buffer.
- **Learning Outcome**: Recognizing the need to manage input streams to avoid buffer overflow.
- **Design Rationale**: A simple loop with `getchar()` efficiently handles residual input, critical after `scanf`-like operations.

### 5. `student/validate_numeric_input.c`
- **Role**: Implements `validateNumericInput()` to validate integer input within a range.
- **Learning Outcome**: Learning input validation and error handling loops.
- **Design Rationale**: Using `fgets` and `sscanf` prevents buffer overflows, with retries improving user experience.

### 6. `student/validate_float_input.c`
- **Role**: Implements `validateFloatInput()` for float validation.
- **Learning Outcome**: Applying similar validation techniques to different data types.
- **Design Rationale**: Consistent with integer validation, ensuring scores (0.0-10.0) are valid.

### 7. `student/validate_string_input.c`
- **Role**: Implements `validateStringInput()` to validate and trim strings.
- **Learning Outcome**: Understanding string handling and whitespace management.
- **Design Rationale**: `fgets` supports names with spaces, and trimming enhances data quality.

### 8. `student/check_duplicate_id.c`
- **Role**: Implements `checkDuplicateID()` to prevent duplicate student IDs.
- **Learning Outcome**: Implementing data integrity checks.
- **Design Rationale**: A linear search suffices for the small array size, ensuring unique IDs.

### 9. `student/create_store_directory.c`
- **Role**: Implements `createStoreDirectory()` to create the `store` directory.
- **Learning Outcome**: Exploring file system operations and cross-platform coding.
- **Design Rationale**: Conditional `mkdir` with `#ifdef _WIN32` ensures compatibility.

### 10. `student/load_credentials.c`
- **Role**: Implements `loadCredentials()` to read credentials from `credentials.txt`.
- **Learning Outcome**: Mastering file I/O and default value handling.
- **Design Rationale**: Persistent credentials with defaults ensure usability.

### 11. `student/save_credentials.c`
- **Role**: Implements `saveCredentials()` to write credentials.
- **Learning Outcome**: Understanding file writing and error handling.
- **Design Rationale**: Saves changes and exits on failure to maintain integrity.

### 12. `student/load_students.c`
- **Role**: Implements `loadStudents()` to load student data.
- **Learning Outcome**: Handling file-based data persistence.
- **Design Rationale**: Skips invalid lines to ensure robustness.

### 13. `student/save_students.c`
- **Role**: Implements `saveStudents()` to save student data.
- **Learning Outcome**: Practicing file output operations.
- **Design Rationale**: Ensures data persistence with error checking.

### 14. `student/add_student.c`
- **Role**: Implements `addStudent()` to add new students.
- **Learning Outcome**: Combining validation and array management.
- **Design Rationale**: Checks capacity and duplicates for data integrity.

### 15. `student/show_students.c`
- **Role**: Implements `showStudents()` to display records.
- **Learning Outcome**: Formatting output for readability.
- **Design Rationale**: Simple loop with empty check enhances usability.

### 16. `student/update_student.c`
- **Role**: Implements `updateStudent()` to modify records.
- **Learning Outcome**: Implementing search and update logic.
- **Design Rationale**: Linear search is efficient for small datasets.

### 17. `student/delete_student.c`
- **Role**: Implements `deleteStudent()` to remove records.
- **Learning Outcome**: Understanding array manipulation.
- **Design Rationale**: Shifting elements minimizes memory usage.

### 18. `student/update_credentials.c`
- **Role**: Implements `updateCredentials()` to change login details.
- **Learning Outcome**: Integrating user input with file updates.
- **Design Rationale**: Allows dynamic updates with persistence.

### 19. `student/authenticate.c`
- **Role**: Implements `authenticate()` with 3 attempts.
- **Learning Outcome**: Applying security concepts.
- **Design Rationale**: Limited attempts enhance security.

### 20. `student/generate_grade_report.c`
- **Role**: Implements `generateGradeReport()` for pass/fail status.
- **Learning Outcome**: Creating conditional output.
- **Design Rationale**: Simple threshold meets requirements, extensible for grades.

### 21. `student/search_student_by_name.c`
- **Role**: Implements `searchStudentByName()` for name-based search.
- **Learning Outcome**: Using string matching.
- **Design Rationale**: `strstr` provides flexible substring search.

## Compilation and Execution
- **Command**: `gcc -o student_management main.c student_management.c -I.`
- **Run**: `./student_management` (Unix) or `student_management.exe` (Windows).
- **Prerequisites**: Ensure `store/` exists with `credentials.txt` and `students_store.txt`.

## Reflection and Learning Outcomes
This project deepened my understanding of:
- C programming fundamentals (structures, pointers, file I/O).
- Modular design and its benefits for code maintenance.
- Input validation and error handling for robust software.
- Cross-platform development using conditional compilation.
Challenges included managing global variables and ensuring file compatibility, which I addressed through careful planning and testing.

## Future Improvements
- Implement a Makefile for separate compilation.
- Add case-insensitive search or score filtering.
- Enhance `generateGradeReport` with a grading scale (e.g., A/B/C).

## Conclusion
The Student Management System demonstrates my ability to design, implement, and document a functional C application. I invite feedback to further refine my skills. Thank you for reviewing this project!
