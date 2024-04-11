#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h> 
#include <sys/msg.h> 
#define MAX 100 

struct mesg_buffer { 
	long mesg_type; 
	char mesg_text[MAX]; 
} message; 

int main() 
{ 
	key_t key; 
	int msgid; 

	key = ftok("progfile", 65); 

	msgid = msgget(key, 0666 | IPC_CREAT); 
	message.mesg_type = 1; 

	printf("Write Data : "); 
	fgets(message.mesg_text, MAX, stdin); 

	message.mesg_text[strcspn(message.mesg_text, "\n")] = '\0';

	msgsnd(msgid, &message, sizeof(message), 0); 

	printf("Data sent is: %s\n", message.mesg_text); 
    
	msgrcv(msgid, &message, sizeof(message), 1, 0); 

	printf("Data received is: %s\n", message.mesg_text); 

	msgctl(msgid, IPC_RMID, NULL); 

	printf("\n\n===============================================");
    printf("\nLab No: 4(b)");
    printf("\nName: Dipesh Shrestha\n");
    printf("Roll No.: 08\n");
    printf("Section: B.Sc.CSIT 4th Semester\n");
    printf("===============================================\n");

	return 0; 
} 
 
