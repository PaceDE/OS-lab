#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_function(void *arg) {
    printf("Thread is running.\n");
    pthread_exit(NULL);
}

int main() {
  
    pthread_t thread_id;
    int result;

    result = pthread_create(&thread_id, NULL, thread_function, NULL);

    if (result != 0) {
        fprintf(stderr, "Failed to create a thread: %d\n", result);
        exit(EXIT_FAILURE);
    }

    printf("Main thread is running.\n");

    pthread_join(thread_id, NULL);
    printf("Thread has terminated.\n");

    printf("This is a message from the main thread.\n");

    printf("\n\n===============================================");
    printf("\nLab No: 3\n");
    printf("Name: Dipesh Shrestha\n");
    printf("Roll No.: 08\n");
    printf("Section: B.Sc.CSIT 4th Semester\n");
    printf("===============================================\n");

    pthread_exit(NULL);

    
    return 0;
}
