#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    FILE *file;
    char line[MAX_LINE_LENGTH];

    if (argc != 3) {
        printf("Usage: %s pattern filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[2], "r");
    if (file == NULL) {
        printf("Unable to open file: %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    printf("Lines containing pattern '%s' in file '%s':\n", argv[1], argv[2]);
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        if (strstr(line, argv[1]) != NULL) {
            printf("%s", line);
        }
    }
    fclose(file);

    return 0;
}

