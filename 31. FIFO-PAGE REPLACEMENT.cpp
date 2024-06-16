#include<stdio.h>

#define MAX_FRAMES 3
#define MAX_PAGES 20

int main() {
    int reference_string[MAX_PAGES];
    int page_frames[MAX_FRAMES];
    int page_faults = 0;
    int frame_index = 0;
    int next_frame = 0;

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

    for (int j = 0; j < i; j++) {
        int page_to_refer = reference_string[j];
        int found = 0;

        for (int k = 0; k < MAX_FRAMES; k++) {
            if (page_frames[k] == page_to_refer) {
                found = 1;
                break;
            }
        }

        if (!found) {
            page_frames[frame_index] = page_to_refer;
            frame_index = (frame_index + 1) % MAX_FRAMES;
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

