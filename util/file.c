#include "file.h"

void printFile(FILE* file) {
    int buf = 0;
    fseek(file, 0, SEEK_SET);
    fread(&buf, sizeof(int), 1, file);
    while (!(feof(file))) {
        printf("%i ", buf);
        fread(&buf, sizeof(int), 1, file);
    }

    printf("\n");
}

int getInt(int i, FILE* file) {
    int result = 0;

    fseek(file, sizeof(int) * (i - 1), SEEK_SET);
    fread(&result, sizeof(int), 1, file);

    return result;
}

int setInt(int num, int i, FILE* file) {
    fseek(file, sizeof(int) * (i-1), SEEK_SET);
    fwrite(&num, sizeof(int), 1, file);

    return 0;
}