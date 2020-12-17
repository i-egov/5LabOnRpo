#ifndef MENU_H
#define MENU_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "util/file.h"
#include "util/dynamicString.h"

void menu(DynamicString *path);
DynamicString* getPath();

#endif