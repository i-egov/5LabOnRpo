#include "file.h"

void printFile(FILE* file) {
    int buf = 0;
    fseek(file, 0, SEEK_SET);
    fread(&buf, sizeof(int), 1, file);
    while (!(feof(file))) {
        printf("%i ", buf);
        fread(&buf, sizeof(int), 1, file);
    }
    fseek(file, 0, SEEK_SET);

    printf("\n");
}

int getInt(int i, FILE* file) {
    int result = 0;

    fseek(file, (i - 1) * sizeof(int), SEEK_SET);
    fread(&result, sizeof(int), 1, file);
    fseek(file, 0, SEEK_SET);

    return result;
}


int setInt(int num, int i, FILE* file) {
    fseek(file, (i - 1) * sizeof(int), SEEK_SET);
    fwrite(&num, sizeof(int), 1, file);
    rewind(file);

    return 0;
}