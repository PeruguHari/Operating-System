#include<stdio.h>
#include<limits.h>

#define MAX_FRAMES 3
#define MAX_PAGES 20

int findOptimal(int page_frames[], int reference_string[], int n, int current) {
    int index = -1;
    int farthest = current;
    for (int i = 0; i < MAX_FRAMES; i++) {
        int j;
        for (j = current; j < n; j++) {
            if (page_frames[i] == reference_string[j]) {
                if (j > farthest) {
                    farthest = j;
                    index = i;
                }
                break;
            }
        }
        if (j == n) {
            return i;
        }
    }
    if (index == -1) {
        index = 0;
    }
    return index;
}

int main() {
    int reference_string[MAX_PAGES];
    int page_frames[MAX_FRAMES];
    int page_faults = 0;

    for (int i = 0; i < MAX_FRAMES; i++) {
        page_frames[i] = -1;
    }

    printf("Enter the reference string (maximum 20 pages, -1 to end):\n");
    int page;
    int i = 0;
    do {
        scanf("%d", &page);
        if (page != -1) {
            reference_string[i++] = page;
        }
    } while (page != -1);

    int n = i;
    for (int j = 0; j < n; j++) {
        int page_to_refer = reference_string[j];
        int found = 0;

        for (int k = 0; k < MAX_FRAMES; k++) {
            if (page_frames[k] == page_to_refer) {
                found = 1;
                break;
            }
        }

        if (!found) {
            int index = findOptimal(page_frames, reference_string, n, j);
            page_frames[index] = page_to_refer;
            page_faults++;
        }

        printf("Page Frames: ");
        for (int k = 0; k < MAX_FRAMES; k++) {
            printf("%d ", page_frames[k]);
        }
        printf("\n");
    }

    printf("Total Page Faults: %d\n", page_faults);

    return 0;
}

