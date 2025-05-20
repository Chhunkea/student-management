// student/check_duplicate_id.c
#include "../student_management.h"

int checkDuplicateID(int id) {
    for (int i = 0; i < student_count; i++) {
        if (students[i].id == id) return 1; // Duplicate found
    }
    return 0; // No duplicate
}