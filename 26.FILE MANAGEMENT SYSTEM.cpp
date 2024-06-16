#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *filePointer;
    char data[100];

    filePointer = fopen("file.txt", "w");
    if (filePointer == NULL) {
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }
    printf("Enter data to write to the file: ");
    fgets(data, sizeof(data), stdin);
    fputs(data, filePointer);
    fclose(filePointer);
    printf("Data written to the file successfully.\n");

    filePointer = fopen("file.txt", "r");
    if (filePointer == NULL) {
        printf("Unable to open file.\n");
        exit(EXIT_FAILURE);
    }

    printf("Contents of the file:\n");
    while (fgets(data, sizeof(data), filePointer) != NULL) {
        printf("%s", data);
    }
    fclose(filePointer);

    return 0;
}

