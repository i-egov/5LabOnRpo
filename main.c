#include "menu.h"
#include "util/dynamicString.h"

int main() {
    DynamicString *path = getPath();

    while (1) {
        menu(path);
    }
}
