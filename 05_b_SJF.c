#include <stdio.h>
#define MAX 100
struct SJF{
    int pid;
    int at;
    int bt;
    int ct;
    int tt;
    int wt;
};
void sort(struct SJF *,int);

int main()  
{  
    struct SJF p[MAX];
    int n,i,j,time=0,temp[MAX];
    printf("Enter the number of processes: ");
    scanf("%d",&n);
 
    printf("Enter process id of all the process: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&p[i].pid);
    }

    printf("Enter arrival time of all the processes: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&p[i].at);
    }
  
    printf("Enter burst time of all the processes: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&p[i].bt);
    }

// aranging in order of burst time
sort(p,n);
 
    for(i=0;i<n;i++)
    {
        temp[i]=p[i].bt;
    }
    printf("Process ID     Arrival Time     Burst Time     Completion Time     TurnAround Time     Waiting Time\n");
    float total_wt=0.0;
    float total_tt= 0.0;
    for(int count=0,time=0; count<n;count++)   
    {    

        again:
        int Emptyq=0;
        for(j=0;j<n;j++)
        {
            
            if(p[j].at>time || temp[j] == 0)
                {
                    Emptyq++;
                }
            if(Emptyq==n)
            {
                time++;
                goto again;
            }

        }

      for(i=0;i<n;i++)
      {
        if (p[i].at<=time && temp[i] !=0)
        {
            p[i].ct=time+p[i].bt;
            time=  p[i].ct;
            temp[i]=0;
            p[i].tt=  p[i].ct - p[i].at;
            p[i].wt=  p[i].tt-  p[i].bt;

            printf("%d\t\t",   p[i].pid);
            printf("%d\t\t",p[i].at);
            printf("%d\t\t",   p[i].bt);
            printf("%d\t\t\t",   p[i].ct);
            printf("%d\t\t",   p[i].tt);

            printf("%d\t\t",   p[i].wt);
            printf("\n");
            break;
        }
      }

 
        //for calculating total waiting time
        total_tt +=   p[i].tt;
 
        //for calculating total turnaround time
        total_wt +=   p[i].wt;
    }
    float att,awt;
 
    //for calculating average waiting time
    awt = total_wt/n;
 
    //for calculating average turnaround time
    att = total_tt/n;
    printf("Avg. waiting time= %f\n",awt);
    printf("Avg. turnaround time= %f \n\n",att);


  printf("\n\n===============================================");
  printf("\nLab No: 5(b)");
  printf("\nName: Dipesh Shrestha\n");
  printf("Roll No.: 08\n");
  printf("Section: B.Sc.CSIT 4th Semester\n");
  printf("===============================================\n");
}

void sort(struct SJF *p, int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if (p[j].bt>p[j+1].bt)
            {
                struct SJF temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
}