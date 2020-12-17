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
        printf("Error! File not open\n");
        return;
    }
    printFile(file);
    printf("\n");
    fclose(file);
}

void menuGetInt(DynamicString *path) {
    FILE* file;
    if (!(file = fopen(path->string, "rb"))) {
        printf("Error! File not open\n");
        return;
    }
    int i = getUserEnter("Enter the id of number you want to see");

    int result = getInt(i, file);
    printf("Result: %i\n", result);

    fclose(file);
}

void menuSetInt(DynamicString *path) {
    FILE* file;
    if (!(file = fopen(path->string, "ab"))) {
        printf("Error! File not open\n");
        return;
    }
    int i = getUserEnter("Enter the id of number you want to set");
    int num = getUserEnter("Enter new number");

    setInt(num, i, file);

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
    printf("=======Super Puper Menu=======\n");
    printf("1. Set path\n");
    printf("2. Print all content\n");
    printf("3. Get int\n");
    printf("4. Set int\n");
    printf("5. Exit\n");
    return getUserEnter("Select element");
}

void menu(DynamicString *path) {
    int userEnterMenu = printMainMenu();
    switch (userEnterMenu) {
        case 1:
            freeString(path);
            path = getPath();
            break;
        case 2:
            menuPrintFile(path);
            break;
        case 3:
            menuGetInt(path);
            break;
        case 4:
            menuSetInt(path);
            break;
        case 5:
            printf("Bye!\n");
            exit(0);
        default:
            printf("Unknown element!\n");
            break;
    }
}