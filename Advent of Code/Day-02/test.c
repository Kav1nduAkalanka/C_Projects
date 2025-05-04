#include <stdio.h>

int main() {
    FILE *fp = fopen("a.txt", "r");

    if (fp == NULL) {
        printf("Cannot access the file\n");
        return 1;
    } else {
        printf("File opened successfully!\n");
        fclose(fp);
    }

    return 0;
}
