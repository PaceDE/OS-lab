#include <stdio.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_BLOCKS 100

struct Inode {
    char filename[20];
    int size;
    int blocks[10];  
};

struct Block {
    char data[256];  
};

struct Inode inodes[MAX_FILES];
struct Block blocks[MAX_BLOCKS];
int currentInode = 0;

int allocateBlocks(int size) {
    int allocatedBlocks = 0;
    for (int i = 0; i < MAX_BLOCKS; i++) {
        if (allocatedBlocks == size) return i - size;  
        if (blocks[i].data[0] == '\0') allocatedBlocks++;
        else allocatedBlocks = 0;
    }
    return -1;  
}

void createFile(char filename[], int size) {
    if (currentInode >= MAX_FILES) {
        printf("Error: Maximum number of files reached.\n");
        return;
    }
    int startBlock = allocateBlocks(size);
    if (startBlock == -1) {
        printf("Error: Not enough contiguous blocks to create the file.\n");
        return;
    }
    strcpy(inodes[currentInode].filename, filename);
    inodes[currentInode].size = size;
    for (int i = 0; i < size; i++) {
        inodes[currentInode].blocks[i] = startBlock + i;
        blocks[startBlock + i].data[0] = '\0';  
    }
    printf("File %s created successfully.\n", filename);
    currentInode++;
}

void deleteFile(char filename[]) {
    for (int i = 0; i < currentInode; i++) {
        if (strcmp(inodes[i].filename, filename) == 0) {
            for (int j = 0; j < inodes[i].size; j++) {
                blocks[inodes[i].blocks[j]].data[0] = '\0';  
            }
            for (int k = i; k < currentInode - 1; k++) {
                inodes[k] = inodes[k + 1];
            }
            currentInode--;
            printf("File %s deleted successfully.\n", filename);
            return;
        }
    }
    printf("Error: File %s not found.\n", filename);
}

void displayInodes() {
    printf("\nInodes\n");
    printf("Filename\tSize\tBlocks\n");
    for (int i = 0; i < currentInode; i++) {
        printf("%s\t%d\t", inodes[i].filename, inodes[i].size);
        for (int j = 0; j < inodes[i].size; j++) {
            printf("%d ", inodes[i].blocks[j]);
        }
        printf("\n");
    }
}

int main() {
    int choice, size;
    char filename[20];

    do {
        printf("\nFile Allocation using Inode\n");
        printf("1. Create File\n");
        printf("2. Delete File\n");
        printf("3. Display Inodes\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter file name: ");
                scanf("%s", filename);
                printf("Enter file size (blocks): ");
                scanf("%d", &size);
                createFile(filename, size);
                break;
            case 2:
                printf("Enter file name to delete: ");
                scanf("%s", filename);
                deleteFile(filename);
                break;
            case 3:
                displayInodes();
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    printf("\n\n===============================================");
    printf("\nLab No: 8(d)");
    printf("\nName: Dipesh Shrestha\n");
    printf("Roll No.: 08\n");
    printf("Section: B.Sc.CSIT 4th Semester\n");
    printf("===============================================\n");

    return 0;
}

