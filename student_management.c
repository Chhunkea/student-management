// student_management.c
#include "student_management.h"
#include "student/clear_input_buffer.c"
#include "student/validate_numeric_input.c"
#include "student/validate_float_input.c"
#include "student/validate_string_input.c"
#include "student/check_duplicate_id.c"
#include "student/create_store_directory.c"
#include "student/load_credentials.c"
#include "student/save_credentials.c"
#include "student/load_students.c"
#include "student/save_students.c"
#include "student/add_student.c"
#include "student/show_students.c"
#include "student/update_student.c"
#include "student/delete_student.c"
#include "student/update_credentials.c"
#include "student/authenticate.c"
#include "student/generate_grade_report.c"
#include "student/search_student_by_name.c"

// Global variables (defined here)
struct Student students[MAX_STUDENTS];
int student_count = 0;
struct Credentials creds = {"admin", "password123"}; // Default credentials