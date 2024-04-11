#include <stdio.h>
#include <stdlib.h>

struct Block {
    int index;
    int allocated;
    struct Block* next;
};

struct Block* createBlock(int index) {
    struct Block* block = (struct Block*)malloc(sizeof(struct Block));
    if (block) {
        block->index = index;
        block->allocated = 0;
        block->next = NULL;
    }
    return block;
}

void displayBlocks(struct Block* head) {
    while (head) {
        printf("%d -> %s\n", head->index, head->allocated ? "allocated" : "free");
        head = head->next;
    }
}

// Function to allocate memory blocks
void allocateBlocks(struct Block* head, int start, int length) {
    struct Block* current = head;
    while (current && start > 0) {
        current = current->next;
        start--;
    }

    while (current && length > 0) {
        current->allocated = 1;
        current = current->next;
        length--;
    }
}

int main() {
    // Initialize memory blocks as a linked list
    struct Block* memory = createBlock(0);
    struct Block* current = memory;
    for (int i = 1; i < 50; i++) {
        current->next = createBlock(i);
        current = current->next;
    }

    int p, st, len, c;
    printf("Enter how many blocks are already allocated: ");
    scanf("%d", &p);

    printf("\nEnter the block numbers that are already allocated:\n");
    for (int i = 0; i < p; i++) {
        int a;
        scanf("%d", &a);
        allocateBlocks(memory, a, 1); // Mark block as allocated
    }

    do {
        printf("Enter the starting index block and length: ");
        scanf("%d %d", &st, &len);
        allocateBlocks(memory, st, len);

        printf("If you want to enter one more file? (yes-1/no-0): ");
        scanf("%d", &c);
    } while (c == 1);

    // Display memory blocks after allocation
    printf("\nMemory Allocation Status:\n");
    displayBlocks(memory);

    // Free allocated memory
    while (memory) {
        struct Block* temp = memory;
        memory = memory->next;
        free(temp);
    }
    
  printf("\n\n===============================================");
  printf("\nLab No: 8(b)");
  printf("\nName: Dipesh Shrestha\n");
  printf("Roll No.: 08\n");
  printf("Section: B.Sc.CSIT 4th Semester\n");
  printf("===============================================\n");

    return 0;
}
