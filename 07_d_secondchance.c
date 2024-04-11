#include<stdio.h>
#include<stdbool.h>

struct Page {
    int pageNumber;
    bool referenceBit;
};

int secondChancePageReplacement(struct Page frames[], int frameSize, int pages[], int pageSize) {
    int pageFaults = 0;
    int currentIndex = 0;

    for (int i = 0; i < pageSize; i++) {
        bool pageFound = false;
        for (int j = 0; j < frameSize; j++) {
            if (frames[j].pageNumber == pages[i]) {
                frames[j].referenceBit = true;
                pageFound = true;
                break;
            }
        }

        if (!pageFound) {
            while (true) {
                if (!frames[currentIndex].referenceBit) {
                    frames[currentIndex].pageNumber = pages[i];
                    frames[currentIndex].referenceBit = true;
                    currentIndex = (currentIndex + 1) % frameSize;
                    pageFaults++;
                    break;
                } else {
                    frames[currentIndex].referenceBit = false;
                    currentIndex = (currentIndex + 1) % frameSize;
                }
            }
        }

        printf("%d: ", pages[i]);
        for (int k = 0; k < frameSize; k++) {
            printf("%d[%d]\t", frames[k].pageNumber, frames[k].referenceBit);
        }
        printf("\n");
    }

    return pageFaults;
}

int main() {
   
    int frameSize = 3;
    int pageSize = 20;
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};

    struct Page frames[frameSize];
    for (int i = 0; i < frameSize; i++) {
        frames[i].pageNumber = -1;
        frames[i].referenceBit = false;
    }

    int pageFaults = secondChancePageReplacement(frames, frameSize, pages, pageSize);

    printf("\nTotal Page Faults: %d\n", pageFaults);


  printf("\n\n===============================================");
  printf("\nLab No: 7(d)");
  printf("\nName: Dipesh Shrestha\n");
  printf("Roll No.: 08\n");
  printf("Section: B.Sc.CSIT 4th Semester\n");
  printf("===============================================\n");

    return 0;
}
