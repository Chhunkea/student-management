// student/clear_input_buffer.c
#include "../student_management.h"

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}