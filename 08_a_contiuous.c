#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_FILES 20

struct File {
    char name[10];
    int start;
    int length;
};

int main() {
    struct File files[MAX_FILES];
    int num_files = 0;
    int ch;

    while (1) {
        printf("\n\nContiguous file allocation\n");
        printf("1. File Creation\n");
        printf("2. File Deletion\n");
        printf("3. Display File Allocation Table\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                if (num_files >= MAX_FILES) {
                    printf("Cannot create more files. Maximum limit reached.\n");
                    break;
                }
                printf("Enter the name of the file: ");
                scanf("%s", files[num_files].name);
                printf("Enter the start block of the file: ");
                scanf("%d", &files[num_files].start);
                printf("Enter the length of the file: ");
                scanf("%d", &files[num_files].length);

                // Check for overlap with existing files
                int overlap = 0;
                for (int i = 0; i < num_files; i++) {
                    if ((files[num_files].start >= files[i].start && 
                         files[num_files].start < files[i].start + files[i].length) ||
                        (files[i].start >= files[num_files].start && 
                         files[i].start < files[num_files].start + files[num_files].length)) {
                        overlap = 1;
                        break;
                    }
                }

                if (overlap) {
                    printf("Cannot allocate disk space. File overlaps with existing file(s).\n");
                    break;
                }

                printf("File %s allocated disk space\n", files[num_files].name);
                num_files++;
                break;

            case 2:
                if (num_files == 0) {
                    printf("No files to delete.\n");
                    break;
                }
                printf("Enter the name of the file to be deleted: ");
                char del[10];
                scanf("%s", del);

                // Search for the file to delete
                for (int i = 0; i < num_files; i++) {
                    if (strcmp(files[i].name, del) == 0) {
                        printf("File %s deleted\n", files[i].name);
                        for (int j = i; j < num_files - 1; j++) {
                            strcpy(files[j].name, files[j + 1].name);
                            files[j].start = files[j + 1].start;
                            files[j].length = files[j + 1].length;
                        }
                        num_files--;
                        break;
                    }
                }
                break;

            case 3:
                printf("File Allocation Table\n");
                printf("FileName\tStartBlock\tLength\n");

                for (int i = 0; i < num_files; i++) {
                    printf("%s\t\t%d\t\t%d\n", files[i].name, files[i].start, files[i].length);
                }
                break;

            case 4:
                printf("Exiting...\n");
                printf("\n\n===============================================");
  printf("\nLab No: 8(a)");
  printf("\nName: Dipesh Shrestha\n");
  printf("Roll No.: 08\n");
  printf("Section: B.Sc.CSIT 4th Semester\n");
  printf("===============================================\n");

                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

  printf("\n\n===============================================");
  printf("\nLab No: 8(a)");
  printf("\nName: Dipesh Shrestha\n");
  printf("Roll No.: 08\n");
  printf("Section: B.Sc.CSIT 4th Semester\n");
  printf("===============================================\n");

    return 0;
}
