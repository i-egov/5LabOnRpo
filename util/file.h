#ifndef UTIL_FILE_H
#define UTIL_FILE_H

#include <stdlib.h>
#include <stdio.h>

void printAllFileContent(FILE* file); // Вывод всего контента файла
int getIntElementInIndex(int elementID, FILE* file); // Получение элемента по индексу
int setIntElementInIndex(int num, int elementID, FILE* file); // Запись элемента по индексу

#endif