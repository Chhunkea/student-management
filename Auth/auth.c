#include "auth.h"
#include <stdio.h>
#include <string.h>

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

  if (strcmp(username, correctUsername) == 0 &&
      strcmp(password, correctPassword) == 0) {
    printf("Login successful!\n");
    return 1; // Success
  } else {
    printf("Invalid username or password.\n");
    return 0; // Failure
  }
}