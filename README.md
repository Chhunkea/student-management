Student Management System
This is a simple C program for managing student records. It allows you to add, view, update, and delete student information, with a basic login system and file storage for saving data.
Features

Login System: Requires a username and password to access the program.
Add Student: Add new students with an ID, name, and grade.
View Students: Display a list of all students.
Update Student: Change the name or grade of an existing student.
Delete Student: Remove a student from the list.
File Storage: Saves student data to a text file (students.txt) and loads it when the program starts.

Requirements

A C compiler (e.g., GCC) installed on your system.
macOS, Linux, or Windows with a compatible terminal.

File Structure

main.c: The main program that runs the menu and calls other functions.
auth.h: Header file for the login function.
auth.c: Contains the login implementation.
student.h: Header file for student management functions and structure.
student.c: Contains the CRUD (add, view, update, delete) functions and file I/O.
students.txt: Text file to store student data (created automatically).
README.md: This file with instructions.

How to Set Up and Run
1. Install GCC
If you don’t have GCC installed:

On macOS: Run xcode-select --install in the terminal.
On Linux: Run sudo apt install gcc (Ubuntu/Debian) or sudo yum install gcc (CentOS).
Verify installation with gcc --version.

2. Save the Files

Create a new folder for the project.
Copy the contents of main.c, auth.h, auth.c, student.h, and student.c (provided earlier) into separate files with those names in the folder.

3. Compile the Program
Open a terminal in the project folder and run:
gcc -Wall main.c auth.c student.c -o student_management


The -Wall flag shows warnings if there are any issues.
This creates an executable file named student_management.

4. Run the Program
Execute the program with:
./student_management


Log in with:
Username: admin
Password: 1234


Follow the menu prompts to manage students.

5. Check the Data File

After adding students, check the students.txt file in the same folder. It will contain data in the format id,name,grade (e.g., 1,Chhunkea,80.00).

Usage Instructions

Menu Options:

Add New Student: Enter ID, name, and grade.



View All Students: See the list of all students.



Update Student Info: Enter an ID to update a student’s name or grade.



Delete Student: Enter an ID to remove a student.



Exit: Close the program.




Data is saved to students.txt after each change and loaded when the program starts.

Example Output
Student List:
    ID         Name                    Grade
--------------------------------
    1         Chhunkea                  80.00
   45         Cooking with kya         12.00
   12         Bruhhhhsahdjassad      1000.00
  190         keachhun                 12.00

Troubleshooting

Compilation Fails: Ensure all files are in the same folder and filenames match exactly (e.g., main.c, not Main.c).
Program Doesn’t Run: Check for student_management in the folder with ls -l (macOS/Linux) or dir (Windows). Make it executable with chmod +x student_management if needed.
Alignment Issues: The table should align with the current code. If not, ensure the displayStudents function uses %5d %20s %10.2f.

Notes

Grades can be any number (e.g., 1000.00). To limit to 0-100, ask for code modifications.
Names longer than 20 characters will be truncated.
Data persists between runs via students.txt.

Created On

May 28, 2025, 02:00 PM +07

