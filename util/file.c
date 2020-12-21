#include "file.h"

void printAllFileContent(FILE* file) {
    int buffer = 0;
    fseek(file, 0, SEEK_SET);
    fread(&buffer, sizeof(int), 1, file);

    while (!(feof(file))) {
        printf("%i ", buffer);
        fread(&buffer, sizeof(int), 1, file);
    }

    printf("\n");
}

int getIntElementInIndex(int elementID, FILE* file) {
    int element = 0;

    fseek(file, (elementID - 1) * sizeof(int), SEEK_SET);
    fread(&element, sizeof(int), 1, file);

    return element;
}


int setIntElementInIndex(int num, int elementID, FILE* file) {
    fseek(file, (elementID - 1) * sizeof(int), SEEK_SET);
    fwrite(&num, sizeof(int), 1, file);
    rewind(file);

    return 0;
}