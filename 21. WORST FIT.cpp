#include <stdio.h>

#define MAX_BLOCKS 10
#define MAX_JOBS 10

void worstFit(int blocks[], int m, int jobs[], int n) {
    int allocation[n];

    for (int i = 0; i < n; i++) {
        int worstIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blocks[j] >= jobs[i]) {
                if (worstIdx == -1 || blocks[worstIdx] < blocks[j])
                    worstIdx = j;
            }
        }

        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            blocks[worstIdx] -= jobs[i];
        } else {
            allocation[i] = -1; // Indicates failure to allocate
        }
    }

    printf("\nJob No.\tJob Size\tBlock No.\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, jobs[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

int main() {
    int blocks[MAX_BLOCKS], jobs[MAX_JOBS];
    int m, n;

    printf("Enter the number of memory blocks: ");
    scanf("%d", &m);
    printf("Enter the size of each memory block: ");
    for (int i = 0; i < m; i++)
        scanf("%d", &blocks[i]);

    printf("\nEnter the number of jobs: ");
    scanf("%d", &n);
    printf("Enter the size of each job: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &jobs[i]);

    worstFit(blocks, m, jobs, n);

    return 0;
}

