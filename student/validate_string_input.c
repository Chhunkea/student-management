// student/validate_string_input.c
#include "../student_management.h"

int validateStringInput(const char *prompt, char *buffer, int max_length) {
    printf("%s", prompt);
    if (fgets(buffer, max_length, stdin) == NULL) return 0;
    buffer[strcspn(buffer, "\n")] = '\0'; // Remove trailing newline
    // Trim leading/trailing whitespace
    int start = 0, end = strlen(buffer) - 1;
    while (start <= end && isspace(buffer[start])) start++;
    while (end >= start && isspace(buffer[end])) end--;
    if (start > end) {
        printf("Input cannot be empty. Please try again.\n");
        return 0;
    }
    memmove(buffer, buffer + start, end - start + 1);
    buffer[end - start + 1] = '\0';
    return 1;
}