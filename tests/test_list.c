#include <stdio.h>
#include <string.h>

#include "list.h"

int main(int argc, char *argv[]) {
    printf("Hello World\n");

    if(argc > 1 && strcmp(argv[1], "0")) {
        printf("Good!\n");
        return 0;
    } else {
        printf("Not Good!\n");
        return 1;
    }
}
