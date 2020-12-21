#include "menu.h"

int getUserEnter(const char* userTitle) {
    int userEnter;
    printf("%s \n:::", userTitle);
    scanf("%d", &userEnter);
    return userEnter;
}


void menuPrintFile(DynamicString* path) {
    FILE* file;
    if (!(file = fopen(path->string, "rb"))) {
        printf("Oops, sorry but we could not open the file, write something to it, then it will be automatically created!\n");
        return;
    }
    printAllFileContent(file);
    printf("\n");
    fclose(file);
}

void menuGetInt(DynamicString *path) {
    FILE* file;
    if (!(file = fopen(path->string, "rb"))) {
        printf("Error! File not open\n");
        return;
    }
    int index = getUserEnter("Enter the id of number you want to see");

    int result = getIntElementInIndex(index, file);
    printf("Result: %i\n", result);

    fclose(file);
}

void menuSetInt(DynamicString *path) {
    FILE* file;
    if (!(file = fopen(path->string, "r+b"))) {
        printf("Oops, we were unable to get read / write access to the file\n");
        return;
    }
    int index = getUserEnter("Enter the element index");
    int num = getUserEnter("Enter number");

    setIntElementInIndex(num, index, file);

    fclose(file);
    printf("Profit\n");
}

DynamicString* getPath() {
    DynamicString *path = initString();
    printf("Please enter path: ");
    readToString(path);
    return path;
}

int printMainMenu() {
    printf("=======Super-Puper Menu=======\n");
    printf("1. Print all content\n");
    printf("2. Get int\n");
    printf("3. Set int\n");
    printf("4. Exit\n");
    return getUserEnter("Select element");
}

void menu(DynamicString *path) {
    int userEnterMenu = printMainMenu();
    switch (userEnterMenu) {
        case 1:
            menuPrintFile(path);
            break;
        case 2:
            menuGetInt(path);
            break;
        case 3:
            menuSetInt(path);
            break;
        case 4:
            printf("Bye!\n");
            exit(0);
        default:
            printf("Unknown element!\n");
            break;
    }
}