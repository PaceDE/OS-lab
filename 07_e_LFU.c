#include <stdio.h>
#include <stdlib.h>

#define MAX_PAGES 100

typedef struct {
    int pageNumber;
    int frequency;
    int counter;
} Page;

void displayFrames(int frames[], int frequencies[], int numFrames) {
    printf("Frames: ");
    for (int i = 0; i < numFrames; i++) {
        if (frames[i] == -1)
            printf("- ");
        else
            printf("%d(%d) ", frames[i], frequencies[i]);
    }
    printf("\n");
}

int main() {
    int numFrames, numPages, pageFaults = 0;
    printf("Enter the number of frames: ");
    scanf("%d", &numFrames);

    printf("Enter the number of pages: ");
    scanf("%d", &numPages);

    int referenceString[numPages];
    printf("Enter the reference string: ");
    for (int i = 0; i < numPages; i++) {
        scanf("%d", &referenceString[i]);
    }

    Page pages[MAX_PAGES];
    int frames[numFrames];
    int frequencies[numFrames];

    // Initialize pages
    for (int i = 0; i < MAX_PAGES; i++) {
        pages[i].pageNumber = -1;
        pages[i].frequency = 0;
        pages[i].counter = 0;
    }

    // Initialize frames
    for (int i = 0; i < numFrames; i++) {
        frames[i] = -1;
        frequencies[i] = 0;
    }

    printf("Step\tPage\tFrames\n");
    printf("---------------------\n");

    for (int i = 0; i < numPages; i++) {
        int page = referenceString[i];
        int frameIndex = -1;

        // Check if page is already in memory
        for (int j = 0; j < numFrames; j++) {
            if (frames[j] == page) {
                frameIndex = j;
                break;
            }
        }

        // Page not found in memory
        if (frameIndex == -1) {
            pageFaults++;

            // Find the frame with the minimum frequency
            int minFrequency = pages[0].frequency;
            int minCounter = pages[0].counter;
            int minIndex = 0;

            for (int j = 1; j < numFrames; j++) {
                if (pages[j].frequency < minFrequency || 
                    (pages[j].frequency == minFrequency && pages[j].counter < minCounter)) {
                    minFrequency = pages[j].frequency;
                    minCounter = pages[j].counter;
                    minIndex = j;
                }
            }

            // Replace the page in the frame with the least frequently used page
            frames[minIndex] = page;
            frequencies[minIndex] = 1;
            pages[minIndex].pageNumber = page;
            pages[minIndex].frequency = 1;
            pages[minIndex].counter = i;
        } else {
            // Increment the frequency of the page
            frequencies[frameIndex]++;
            pages[frameIndex].frequency++;
        }

        // Update the counter for all pages
        for (int j = 0; j < numFrames; j++) {
            if (frames[j] != -1)
                pages[j].counter++;
        }

        printf("%d\t%d\t", i+1, page);
        displayFrames(frames, frequencies, numFrames);
    }

    printf("---------------------\n");
    printf("Total page faults: %d\n", pageFaults);
    
    printf("\n\n===============================================");
                printf("\nLab No: 7(e)");
                printf("\nName: Dipesh Shrestha\n");
                printf("Roll No.: 08\n");
                printf("Section: B.Sc.CSIT 4th Semester\n");

    return 0;
}

