#include "fileTools.h"

void printBinaryFile(FILE* file) {
    int buf = 0;
    fseek(file, 0, SEEK_SET);
    fread(&buf, sizeof(int), 1, file);
    // short readFlag = (feof(file)) ? 0 : 1;
    while (!(feof(file))) {
        printf("%i ", buf);
        fread(&buf, sizeof(int), 1, file);
        // readFlag = (feof(file)) ? 0 : 1;
    }

    printf("\n");
}

int get_int(int i, FILE* file) {
    int result = 0;

    fseek(file, sizeof(int) * (i - 1), SEEK_SET);
    fread(&result, sizeof(int), 1, file);

    return result;
}

int set_int(int num, int i, FILE* file) {
    fseek(file, sizeof(int) * (i-1), SEEK_SET);
    fwrite(&num, sizeof(int), 1, file);

    return 0;
}