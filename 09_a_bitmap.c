#include <stdio.h>
#include <stdlib.h>

#define MAX_BLOCKS 32 // Assuming 32 blocks for simplicity

void initializeBitmap(int *bitmap, int numBlocks) {
    for (int i = 0; i < numBlocks; i++) {
        bitmap[i] = 0; // 0 represents free block
    }
}

void displayBitmap(int *bitmap, int numBlocks) {
    printf("Bitmap: ");
    for (int i = 0; i < numBlocks; i++) {
        printf("%d ", bitmap[i]);
    }
    printf("\n");
}

int allocateBlocks(int *bitmap, int numBlocks, int numToAllocate) {
    int allocatedCount = 0;
    for (int i = 0; i < numBlocks && allocatedCount < numToAllocate; i++) {
        if (bitmap[i] == 0) {
            bitmap[i] = 1; // Mark block as allocated
            allocatedCount++;
        }
    }
    return allocatedCount;
}

void deallocateBlocks(int *bitmap, int numBlocks, int numToDeallocate) {
    int deallocatedCount = 0;
    for (int i = numBlocks - 1; i >= 0 && deallocatedCount < numToDeallocate; i--) {
        if (bitmap[i] == 1) {
            bitmap[i] = 0; // Mark block as free
            deallocatedCount++;
        }
    }
}

int main() {
   
    int bitmap[MAX_BLOCKS];
    int numBlocks = MAX_BLOCKS;
    int choice, numToAllocate, numToDeallocate;

    initializeBitmap(bitmap, numBlocks);

    while (1) {
        displayBitmap(bitmap, numBlocks);
        printf("\nOptions:\n");
        printf("1. Allocate Blocks\n");
        printf("2. Deallocate Blocks\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of blocks to allocate: ");
                scanf("%d", &numToAllocate);
                allocateBlocks(bitmap, numBlocks, numToAllocate);
                break;
            case 2:
                printf("Enter the number of blocks to deallocate: ");
                scanf("%d", &numToDeallocate);
                deallocateBlocks(bitmap, numBlocks, numToDeallocate);
                break;
            case 3:
                printf("Exiting the program.\n");
                printf("\n\n===============================================");
                printf("\nLab No: 9(a)");
                printf("\nName: Dipesh Shrestha\n");
                printf("Roll No.: 08\n");
                printf("Section: B.Sc.CSIT 4th Semester\n");
                printf("===============================================\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

