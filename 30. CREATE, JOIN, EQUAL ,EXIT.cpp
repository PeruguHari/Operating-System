#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *print_message(void *ptr) {
    char *message = (char *)ptr;
    printf("%s\n", message);
    pthread_exit(NULL);
}

void *print_numbers(void *ptr) {
    int n = *((int *)ptr);
    for (int i = 0; i < n; i++) {
        printf("%d\n", i);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;

    char *message = "Hello from the thread!";
    pthread_create(&thread1, NULL, print_message, (void *)message);
    int count = 10;
    pthread_create(&thread2, NULL, print_numbers, (void *)&count);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("Threads joined successfully.\n");

    if (pthread_equal(thread1, thread2)) {
        printf("Threads are equal.\n");
    } else {
        printf("Threads are not equal.\n");
    }

    pthread_exit(NULL);
}

