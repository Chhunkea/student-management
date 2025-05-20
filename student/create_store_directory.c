// student/create_store_directory.c
#include "../student_management.h"

void createStoreDirectory() {
    struct stat st = {0};
    if (stat("./store", &st) == -1) {
#ifdef _WIN32
        mkdir("./store");
#else
        mkdir("./store", 0700);
#endif
    }
}