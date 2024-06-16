#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    int fd, ret;
    char buffer[100];

    fd = creat("file.txt", 0644);
    if (fd == -1) {
        perror("creat");
        exit(EXIT_FAILURE);
    }
    printf("File created successfully.\n");

    fd = open("file.txt", O_WRONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    ret = write(fd, "Hello, World!\n", 14);
    if (ret == -1) {
        perror("write");
        exit(EXIT_FAILURE);
    }
    printf("Data written to the file.\n");

    ret = close(fd);
    if (ret == -1) {
        perror("close");
        exit(EXIT_FAILURE);
    }
    printf("File closed.\n");

    fd = open("file.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    ret = read(fd, buffer, sizeof(buffer));
    if (ret == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }
    buffer[ret] = '\0'; // Null-terminate the string

    printf("Data read from the file: %s\n", buffer);

    ret = close(fd);
    if (ret == -1) {
        perror("close");
        exit(EXIT_FAILURE);
    }
    printf("File closed.\n");

    return 0;
}

