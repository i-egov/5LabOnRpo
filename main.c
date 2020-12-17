#include "dynStr.h"
#include "fileTools.h"

int showPrompt(const char* prompt) {
    int userOption;
    printf("%s: ", prompt);
    scanf("%i", &userOption);
    return userOption;
}

short mainMenu(DynamicString* pathPointer) {
    printf("Currently working with file:\n%s\n", pathPointer->string);
    printf("1) Print contents of file\n");
    printf("2) Get int\n");
    printf("3) Set int\n");
    printf("4) Set file path\n");
    printf("0) Exit\n\n");

    int option = showPrompt("Please, make your choice");
    printf("\n");

    return option;
}

short printFile_Menu(DynamicString* path) {
    FILE* file;
    if (!(file = fopen(path->string, "rb"))) {
        printf("Can't open file using given path\n");
        return 1;
    }
    printBinaryFile(file);
    printf("\n");
    fclose(file);
    return 0;
}

short getInt_Menu(DynamicString* path) {
    FILE* file;
    if (!(file = fopen(path->string, "rb"))) {
        printf("Can't open file using given path\n");
        return 1;
    }
    printf("File is open\n");
    int i = showPrompt("Enter the id of number you want to see");

    int result = get_int(i, file);
    printf("The result is: %i\n", result);

    fclose(file);
    printf("File closed\n\n");

    return 0;
}

short setInt_Menu(DynamicString* path) {
    FILE* file;
    if (!(file = fopen(path->string, "ab"))) {
        printf("Can't open file using given path\n");
        return 1;
    }
    printf("File is open\n");
    int i = showPrompt("Enter the id of number you want to set");
    int num = showPrompt("Enter the number you want to set in that place");

    set_int(num, i, file);

    fclose(file);
    printf("File closed\n\n");
    return 0;
}

short setPath_Menu(DynamicString* path) { 
    freeString(path);
    path = (DynamicString*)initString();

    printf("Please, enter the new path:\n");
    readToString(path);

    if (path->currentlyUsed == 0) {
        setString(path, "wow.txt");
    }

    return 0;
}

int main() {
    DynamicString* path = (DynamicString*)initString();
    setString(path, "wow.txt");
    short runningFlag = 1;

    while (runningFlag) {
        short option = mainMenu(path);

        switch (option) {
        case 0:
            runningFlag = 0;
            break;

        case 1:
            printFile_Menu(path);
            break;

        case 2:
            getInt_Menu(path);
            break;

        case 3:
            setInt_Menu(path);
            break;

        case 4:
            setPath_Menu(path);
            break;

        default:
            printf("No such option\n");
            break;
        }
    }

    freeString(path);
    return 0;
}
