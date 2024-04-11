#include <stdio.h>
#include <stdlib.h>

struct Node {
    int start;
    int length;
    struct Node* next;
};

void displayList(struct Node* head) {
    printf("Linked List: ");
    while (head != NULL) {
        printf("[%d, %d] -> ", head->start, head->length);
        head = head->next;
    }
    printf("NULL\n");
}

void allocateBlocks(struct Node** head, int start, int length) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->start = start;
    newNode->length = length;
    newNode->next = *head;
    *head = newNode;
}

void deallocateBlocks(struct Node** head, int start) {
    struct Node* current = *head;
    struct Node* prev = NULL;

    while (current != NULL && current->start != start) {
        prev = current;
        current = current->next;
    }

    if (current != NULL) {
        if (prev == NULL) {
            *head = current->next;
        } else {
            prev->next = current->next;
        }
        free(current);
    }
}

int main() {
    struct Node* head = NULL;
    int choice, start, length;

    while (1) {
        displayList(head);
        printf("\nOptions:\n");
        printf("1. Allocate Blocks\n");
        printf("2. Deallocate Blocks\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter start block and length to allocate: ");
                scanf("%d %d", &start, &length);
                allocateBlocks(&head, start, length);
                break;
            case 2:
                printf("Enter start block to deallocate: ");
                scanf("%d", &start);
                deallocateBlocks(&head, start);
                break;
            case 3:
                printf("Exiting the program.\n");
                printf("\n\n===============================================");
                printf("\nLab No: 9(b)");
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

