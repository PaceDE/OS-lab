#include<stdio.h>  
#define MAX 100
struct RR{
     int pid;
     int at;
    int bt;
    int ct;
    int tt;
    int wt;
};

struct queue{
  int item[MAX];
  int front;
  int rear;
}q;
void enQueue(struct queue *,int);
int deQueue(struct queue *);

  
int main()  
{  
    q.front=0,q.rear=-1;
    struct RR p[MAX];
    // initlialize the variable name  
    int i,j, NOP, time=0,count=0, y, quant,temp[MAX],arrived=0;  
    float total_tt=0, total_wt=0;
    float avg_wt, avg_tat;  
    printf(" Total number of process in the system: ");  
    scanf("%d", &NOP);  
    y = NOP; // Assign the number of process to variable y  
  
// Use for loop to enter the details of the process like Arrival time and the Burst Time  
    printf("Enter process id of all the process: ");
    for(int i=0;i<NOP;i++)
    {
        scanf("%d",&p[i].pid);
    }

    printf("Enter arrival time of all the processes: ");
    for(int i=0;i<NOP;i++)
    {
        scanf("%d",&p[i].at);
    }

    for(i=0;i<NOP-1;i++)
    {
        for(j=0;j<NOP-1-i;j++)
        {
            if (p[j].at>p[j+1].at)
            {
                struct RR temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
  
    printf("Enter burst time of all the processes: ");
    for(int i=0;i<NOP;i++)
    {
        scanf("%d",&p[i].bt);
        temp[i]=p[i].bt;
    }
// Accept the Time qunat  
    printf("Enter the Time Quantum for the process: \t");  
    scanf("%d", &quant);  
// aranging in order of arrival time
    for(i=0;i<NOP-1;i++)
    {
        for(j=0;j<NOP-1-i;j++)
        {
            if (p[j].at>p[j+1].at)
            {
                struct RR temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }

    for(int i=0;i<NOP;i++)
    {
        temp[i]=p[i].bt;
    }
    j=0;
    while(p[j].at<=time)
    {
        enQueue(&q,j);
        j++;
    }

// Display the process No, burst time, Turn Around Time and the waiting time  
    printf("\n Process No \t\t Arrival Time \t\t Burst Time \t\t Completion Time \t\t TAT \t\t Waiting Time \n");  
    for(time=0; y!=0;)  
    {  
        i = deQueue(&q);
        if(temp[i] <= quant && temp[i] > 0) // define the conditions   
        {  
            p[i].ct=time+temp[i];
            time = p[i].ct; 
            p[i].tt=  p[i].ct - p[i].at;
            p[i].wt=  p[i].tt-  p[i].bt;
            temp[i] = 0;  
            count=1;  
        }     
        else if(temp[i] > 0)  
        {  
            temp[i] = temp[i] - quant;  
            time = time + quant; 

        }  

             while(p[j].at<=time && j<NOP )
            {
              enQueue(&q,j);
              j++;
            }
        
        if(temp[i]==0 && count==1)  
        {  
            y--; //decrement the process no.  
            printf(" %d\t\t\t",   p[i].pid);
            printf(" %d\t\t\t",p[i].at);
            printf(" %d\t\t\t",   p[i].bt);
            printf(" %d\t\t\t",   p[i].ct);         
            printf(" %d\t\t\t",   p[i].tt);
            printf(" %d\t\t\t",   p[i].wt);
            printf("\n");
                    //for calculating total waiting time
            total_tt +=   p[i].tt;
                    //for calculating total turnaround time
            total_wt +=   p[i].wt;
            count =0;     
        }  
        else{
            enQueue(&q,i);
        }
        while(q.rear<q.front && y!=0)
        {
            time++;
                while(p[j].at<=time && j<NOP)
                {
                    enQueue(&q,j);
                    j++;
                }
        }
        
        
    }       //      epresents the average waiting time and Turn Around time  
    avg_wt = total_wt/NOP;  
    avg_tat = total_tt/NOP;  
    printf("\n Average Turn Around Time: \t%f", avg_tat);  
    printf("\n Average Waiting Time: \t%f", avg_wt);  

  printf("\n\n===============================================");
  printf("\nLab No: 5(d)");
  printf("\nName: Dipesh Shrestha\n");
  printf("Roll No.: 08\n");
  printf("Section: B.Sc.CSIT 4th Semester\n");
  printf("===============================================\n");

}  

void enQueue(struct queue *q,int value){
   if(q->rear == MAX-1)
      printf("\nQueue is Full!!! Insertion is not possible!!!\n");
   else{
      q->item[++q->rear]=value;
   }
}
int deQueue(struct queue *q){
    int value;
    if(q->rear < q->front)
      printf("\nQueue is Empty!!! Deletion is not possible!!!\n");
    else{

            value=q->item[q->front];
            q->front++;
            return value;
   }
}


