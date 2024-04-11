#include<stdio.h>
    
int main()
{
    int m, n, position, k, l;
    int a = 0, b = 0, page_fault = 0;
    
    int total_frames = 3;
    int frames[total_frames];
    int temp[total_frames];
    int pages[] = {1, 2, 3, 2, 1, 5, 2, 1, 6, 2, 5, 6, 3, 1, 3, 6, 1, 2, 4, 3};
    int total_pages = sizeof(pages) / sizeof(pages[0]);

    printf("Page\t\tFrame1\t\tFrame2\t\tFrame3\n");

    for(m = 0; m < total_frames; m++) {
        frames[m] = -1;
    }
    
    for(n = 0; n < total_pages; n++) {
        printf("%d:\t\t ", pages[n]);
        a = 0, b = 0;
        for(m = 0; m < total_frames; m++) {
            if(frames[m] == pages[n]) {
                a = 1;
                b = 1;
                break;
            }
        }
        if(a == 0) {
            for(m = 0; m < total_frames; m++) {
                if(frames[m] == -1) {
                    frames[m] = pages[n];
                    b = 1;
                    page_fault++;
                    break;
                }
            }
        }
        if(b == 0) {
            for(m = 0; m < total_frames; m++) {
                temp[m] = 0;
            }
            for(k = n - 1, l = 1; l <= total_frames - 1; l++, k--) {
                for(m = 0; m < total_frames; m++) {
                    if(frames[m] == pages[k]) {
                        temp[m] = 1;
                    }
                }
            }
            for(m = 0; m < total_frames; m++) {
                if(temp[m] == 0)
                    position = m;
            }
            frames[position] = pages[n];
            page_fault++;
        }
        
        for(m = 0; m < total_frames; m++) {
            printf("%d\t\t", frames[m]);
        }
        printf("\n");
    }
    printf("\nTotal Number of Page Faults:\t%d\n", page_fault);


  printf("\n\n===============================================");
  printf("\nLab No: 7(c)");
  printf("\nName: Dipesh Shrestha\n");
  printf("Roll No.: 08\n");
  printf("Section: B.Sc.CSIT 4th Semester\n");
  printf("===============================================\n");
    
    return 0;
}
