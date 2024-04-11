#include <stdio.h>
#include <string.h>

#define MAX_BLOCKS 5
#define MAX_FILES 5

struct File {
    char name[20];
    int startBlock;
    int size;
};

struct FATEntry {
    int used;
    int nextBlock;
};

struct File files[MAX_FILES];
struct FATEntry fat[MAX_BLOCKS];
int currentFileIndex = 0;

void initializeFAT() {
    for (int i = 0; i < MAX_BLOCKS; i++) {
        fat[i].used = 0;
        fat[i].nextBlock = -1;
    }
}

void displayFAT() {
    printf("\nFile Allocation Table (FAT)\n");
    printf("Block\tUsed\tNext Block\n");
    for (int i = 0; i < MAX_BLOCKS; i++) {
        printf("%d\t%d\t%d\n", i, fat[i].used, fat[i].nextBlock);
    }
}

int allocateBlocks(int size) {
    int start = -1;
    int count = 0;

    for (int i = 0; i < MAX_BLOCKS; i++) {
        if (!fat[i].used) {
            if (count == 0) {
                start = i;
            }
            count++;
            if (count == size) {
                return start;
            }
        } else {
            count = 0;
        }
    }

    return -1; // Not enough contiguous blocks
}

int createFile(char name[], int size) {
    int startBlock = allocateBlocks(size);

    if (startBlock != -1) {
        strcpy(files[currentFileIndex].name, name);
        files[currentFileIndex].startBlock = startBlock;
        files[currentFileIndex].size = size;

        int currentBlockPointer = startBlock;
        for (int i = 0; i < size; i++) {
            fat[currentBlockPointer].used = 1;
            fat[currentBlockPointer].nextBlock = (i < size - 1) ? currentBlockPointer + 1 : -1;
            currentBlockPointer++;
        }

        printf("File %s created successfully.\n", name);
        currentFileIndex++;
        return 1;
    } else {
        printf("Error: Not enough contiguous blocks to create the file.\n");
        return 0;
    }
}

int deleteFile(char name[]) {
    for (int i = 0; i < MAX_FILES; i++) {
        if (strcmp(files[i].name, name) == 0) {
            int startBlock = files[i].startBlock;
            int currentBlockPointer = startBlock;

            while (currentBlockPointer != -1) {
                int nextBlock = fat[currentBlockPointer].nextBlock;
                fat[currentBlockPointer].used = 0;
                fat[currentBlockPointer].nextBlock = -1;
                currentBlockPointer = nextBlock;
            }

            printf("File %s deleted successfully.\n", name);
            return 1;
        }
    }

    printf("Error: File %s not found.\n", name);
    return 0;
}

int main() {
    int choice;
    char fileName[20];
    int size;

    initializeFAT();

    do {
        printf("\nFile Allocation using FAT\n");
        printf("1. Display FAT\n");
        printf("2. Create File\n");
        printf("3. Delete File\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayFAT();
                break;
            case 2:
                printf("Enter file name: ");
                scanf("%s", fileName);
                printf("Enter file size (blocks): ");
                scanf("%d", &size);
                createFile(fileName, size);
                break;
            case 3:
                printf("Enter file name to delete: ");
                scanf("%s", fileName);
                deleteFile(fileName);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

 printf("\n\n===============================================");
  printf("\nLab No: 8(c)");
  printf("\nName: Dipesh Shrestha\n");
  printf("Roll No.: 08\n");
  printf("Section: B.Sc.CSIT 4th Semester\n");
  printf("===============================================\n");

    return 0;
}
