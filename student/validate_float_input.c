// student/validate_float_input.c
#include "../student_management.h"

int validateFloatInput(const char *prompt, float *value, float min, float max) {
    char buffer[MAX_LINE_LENGTH];
    int valid = 0;
    do {
        printf("%s", prompt);
        if (fgets(buffer, MAX_LINE_LENGTH, stdin) == NULL) return 0;
        buffer[strcspn(buffer, "\n")] = '\0';
        if (sscanf(buffer, "%f", value) == 1 && *value >= min && *value <= max) {
            valid = 1;
        } else {
            printf("Invalid input. Please enter a number between %.1f and %.1f.\n", min, max);
        }
    } while (!valid);
    return 1;
}