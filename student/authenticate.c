// student/authenticate.c
#include "../student_management.h"

int authenticate() {
    char username[50], password[50];
    int attempts = 3;
    while (attempts > 0) {
        printf("Enter username: ");
        if (!validateStringInput("", username, sizeof(username))) return 0;
        printf("Enter password: ");
        if (!validateStringInput("", password, sizeof(password))) return 0;
        if (strcmp(username, creds.username) == 0 && strcmp(password, creds.password) == 0) {
            printf("Login successful!\n");
            return 1;
        }
        attempts--;
        printf("Invalid credentials. %d attempts remaining.\n", attempts);
    }
    printf("Too many failed attempts. Exiting.\n");
    return 0;
}