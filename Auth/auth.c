#include <stdio.h>
#include <string.h>
#include "auth.h"

int login() {
    char username[20];
    char password[20];
    const char correctUsername[] = "admin";
    const char correctPassword[] = "1234";

    printf("Enter Username: ");
    fgets(username, 20, stdin);
    username[strcspn(username, "\n")] = 0; // Remove newline

    printf("Enter Password: ");
    fgets(password, 20, stdin);
    password[strcspn(password, "\n")] = 0; // Remove newline

    return 0;
}