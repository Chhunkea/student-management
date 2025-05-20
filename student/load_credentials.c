// student/load_credentials.c
#include "../student_management.h"

void loadCredentials() {
    FILE *file = fopen(CREDENTIALS_FILE, "r");
    if (file == NULL) {
        // File doesn't exist, use default credentials and create the file
        saveCredentials();
        return;
    }
    char buffer[MAX_LINE_LENGTH];
    if (fgets(buffer, MAX_LINE_LENGTH, file)) {
        buffer[strcspn(buffer, "\n")] = '\0';
        strncpy(creds.username, buffer, sizeof(creds.username) - 1);
        creds.username[sizeof(creds.username) - 1] = '\0';
    }
    if (fgets(buffer, MAX_LINE_LENGTH, file)) {
        buffer[strcspn(buffer, "\n")] = '\0';
        strncpy(creds.password, buffer, sizeof(creds.password) - 1);
        creds.password[sizeof(creds.password) - 1] = '\0';
    }
    fclose(file);
}