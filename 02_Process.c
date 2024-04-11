#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    
    pid_t pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Failed to fork the process.\n");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        printf("Child process is running with PID: %d\n", getpid());
        exit(EXIT_SUCCESS);
    } else {
        printf("\nParent process is running with PID: %d\n", getpid());
        wait(NULL);
        printf("Child process has terminated.\n");
    }

    printf("This is a message from process with PID: %d\n", getpid());

    printf("\n\n===============================================");
    printf("\nLab No: 2");
    printf("\nName: Dipesh Shrestha\n");
    printf("Roll No.: 08\n");
    printf("Section: B.Sc.CSIT 4th Semester\n");
    printf("===============================================\n");
    exit(EXIT_SUCCESS);
    
}
