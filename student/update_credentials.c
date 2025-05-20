// student/update_credentials.c
#include "../student_management.h"

void updateCredentials() {
    printf("Current username: %s\n", creds.username);
    if (!validateStringInput("Enter new username: ", creds.username, sizeof(creds.username))) return;
    printf("Current password: %s\n", creds.password);
    if (!validateStringInput("Enter new password: ", creds.password, sizeof(creds.password))) return;
    saveCredentials();
    printf("Credentials updated successfully!\n");
}