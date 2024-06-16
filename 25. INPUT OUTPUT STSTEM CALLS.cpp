#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

int main() {
   
    int fd = open("file.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    printf("File opened successfully.\n");

    int flags = fcntl(fd, F_GETFL);
    if (flags == -1) {
        perror("fcntl");
        exit(EXIT_FAILURE);
    }
    printf("File flags: %d\n", flags);

    off_t offset = lseek(fd, 0, SEEK_END);
    if (offset == -1) {
        perror("lseek");
        exit(EXIT_FAILURE);
    }
    printf("File size: %ld bytes\n", (long)offset);

    struct stat file_stat;
    if (stat("file.txt", &file_stat) == -1) {
        perror("stat");
        exit(EXIT_FAILURE);
    }
    printf("File permissions: %o\n", file_stat.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO));

    DIR *dir;
    struct dirent *dir_entry;

    dir = opendir(".");
    if (dir == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    printf("Contents of current directory:\n");
    while ((dir_entry = readdir(dir)) != NULL) {
        printf("%s\n", dir_entry->d_name);
    }

    closedir(dir);

    if (close(fd) == -1) {
        perror("close");
        exit(EXIT_FAILURE);
    }
    printf("File closed.\n");

    return 0;
}

