#ifndef UTIL_FILE_H
#define UTIL_FILE_H

#include <stdlib.h>
#include <stdio.h>

void printFile(FILE* file);
int getInt(int i, FILE* file);
int setInt(int num, int i, FILE* file);

#endif