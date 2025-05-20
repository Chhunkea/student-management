// student/validate_numeric_input.c
#include "../student_management.h"

int validateNumericInput(const char *prompt, int *value, int min, int max) {
    char buffer[MAX_LINE_LENGTH];
    int valid = 0;
    do {
        printf("%s", prompt);
        if (fgets(buffer, MAX_LINE_LENGTH, stdin) == NULL) return 0;
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove trailing newline
        if (sscanf(buffer, "%d", value) == 1 && *value >= min && *value <= max) {
            valid = 1;
        } else {
            printf("Invalid input. Please enter a number between %d and %d.\n", min, max);
        }
    } while (!valid);
    return 1;
}