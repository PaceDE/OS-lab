#include <stdio.h>
#include <stdlib.h>

int main() {
    int queue[20], n, head, i, seek = 0, max, temp;
    float avg;

    printf("Enter the max range of disk: ");
    scanf("%d", &max);
    printf("Enter the initial head position: ");
    scanf("%d", &head);
    printf("Enter the size of queue request: ");
    scanf("%d", &n);
    printf("Enter the queue of disk positions to be read: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }

    // Sorting the queue
    for (i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (queue[i] > queue[j]) {
                temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
            }
        }
    }

    // Finding the position of the head in the sorted queue
    int pos;
    for (i = 0; i < n; i++) {
        if (queue[i] >= head) {
            pos = i;
            break;
        }
    }

    // SCAN towards the right
    for (i = pos; i < n; i++) {
        seek += abs(queue[i] - head);
        printf("Disk head moves from %d to %d\n", head, queue[i]);
        head = queue[i];
    }

    // Move to the maximum range if not already there
    if (head != max) {
        seek += abs(max - head);
        printf("Disk head moves from %d to %d\n", head, max);
        head = max;
    }

    // SCAN towards the left
    for (i = pos - 1; i >= 0; i--) {
        seek += abs(queue[i] - head);
        printf("Disk head moves from %d to %d\n", head, queue[i]);
        head = queue[i];
    }

    printf("Total seek time is %d\n", seek);
    avg = (float) seek / n;
    printf("Average seek time is %f\n", avg);

    printf("\n\n===============================================");
    printf("\nLab No: 10(c)");
    printf("\nName: Dipesh Shrestha\n");
    printf("Roll No.: 08\n");
    printf("Section: B.Sc.CSIT 4th Semester\n");
    printf("===============================================\n");

    return 0;
}

