// student/save_credentials.c
#include "../student_management.h"

void saveCredentials() {
    FILE *file = fopen(CREDENTIALS_FILE, "w");
    if (file == NULL) {
        printf("Error: Cannot write to credentials file.\n");
        exit(1);
    }
    fprintf(file, "%s\n%s\n", creds.username, creds.password);
    fclose(file);
}