#include <stdio.h>
#include <math.h>
#define MAX 100


void FCFS(int arr[],int head,int size)
{
	int seek_count = 0;
	int cur_track, distance;
	int temp=head;

	for(int i=0;i<size;i++)
	{
		cur_track = arr[i];
		distance = fabs(head - cur_track);
		seek_count += distance;
		head = cur_track;
	}

	printf("\nTotal number of seek operations: %d\n",seek_count);
	
	printf("Seek Sequence is\n");
	
	printf("%d -> ",temp);
	for (int i = 0; i < size-1; i++) {
		printf("%d->",arr[i]);
	}
	printf("%d",arr[size-1]);
}

int main()
{
	
	int arr[MAX],n,i;
	int head = 50;
	printf("Enter the no of disk access: ");
	scanf("%d",&n);
	printf("Enter the order of request: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter the initial head position: ");
	scanf("%d",&head);
	
	
	printf("The disk position are:\n");
	for (i = 0; i < n; i++)
		printf("%d\t",arr[i]);
	FCFS(arr,head,n);


  printf("\n\n===============================================");
  printf("\nLab No: 10(a)");
  printf("\nName: Dipesh Shrestha\n");
  printf("Roll No.: 08\n");
  printf("Section: B.Sc.CSIT 4th Semester\n");
  printf("===============================================\n");


	return 0;
}
