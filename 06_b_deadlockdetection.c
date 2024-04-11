#include <stdio.h>

int main() {
    static int mark[20];
    int i, j, np, nr;

    printf("\nEnter the number of processes: ");
    scanf("%d", &np);

    printf("\nEnter the number of resources: ");
    scanf("%d", &nr);

    int alloc[10][10], request[10][10], avail[10], r[10], w[10];

    // Input total amount of each resource
    for (i = 0; i < nr; i++) {
        printf("\nEnter the total amount of Resource R%d: ", i + 1);
        scanf("%d", &r[i]);
    }

    // Input the request matrix
    printf("\nEnter the request matrix:\n");
    for (i = 0; i < np; i++) {
        for (j = 0; j < nr; j++) {
            scanf("%d", &request[i][j]);
        }
    }

    // Input the allocation matrix
    printf("\nEnter the allocation matrix:\n");
    for (i = 0; i < np; i++) {
        for (j = 0; j < nr; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    // Available Resource calculation
    for (j = 0; j < nr; j++) {
        avail[j] = r[j];
        for (i = 0; i < np; i++) {
            avail[j] -= alloc[i][j];
        }
    }

    // Marking processes with zero allocation
    for (i = 0; i < np; i++) {
        int count = 0;
        for (j = 0; j < nr; j++) {
            if (alloc[i][j] == 0) {
                count++;
            } else {
                break;
            }
        }
        if (count == nr) {
            mark[i] = 1;
        }
    }

    // Initialize w with avail
    for (j = 0; j < nr; j++) {
        w[j] = avail[j];
    }

    // Mark processes with request less than or equal to W
    for (i = 0; i < np; i++) {
        int canbeprocessed = 0;
        if (mark[i] != 1) {
            for (j = 0; j < nr; j++) {
                if (request[i][j] <= w[j]) {
                    canbeprocessed = 1;
                } else {
                    canbeprocessed = 0;
                    break;
                }
            }
            if (canbeprocessed) {
                mark[i] = 1;
                for (j = 0; j < nr; j++) {
                    w[j] += alloc[i][j];
                }
            }
        }
    }

    // Checking for unmarked processes
    int deadlock = 0;
    for (i = 0; i < np; i++) {
        if (mark[i] != 1) {
            deadlock = 1;
            break;
        }
    }
    
    if (deadlock) {
        printf("\nDeadlock detected");
    } else {
        printf("\nNo Deadlock possible");
    }

      printf("\n\n===============================================");
  printf("\nLab No: 6(a)");
  printf("\nName: Dipesh Shrestha\n");
  printf("Roll No.: 08\n");
  printf("Section: B.Sc.CSIT 4th Semester\n");
  printf("===============================================\n");
    return (0);  

    return 0;
}
