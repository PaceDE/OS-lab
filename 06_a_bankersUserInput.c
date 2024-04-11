#include <stdio.h>  
#define MAX 5
int main()  
{  
   
    int n, m, i, j, k;  
    n = 5;                          
    m = 3;                           
    int alloc[MAX][MAX];
    int max[MAX][MAX];
    int avail[MAX];

    printf("Enter the no of processs: ");
    scanf("%d",&n);

    printf("Enter the no of resource: ");
    scanf("%d",&m);

    printf("Enter the %d x %d allocation matrix :\n",n,m);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&alloc[i][j]);
        }
    }
    printf("Enter the %d x %d max matrix :\n",n,m);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&max[i][j]);
        }
    }
    printf("Enter the no of each available resource ");
    for(j=0;j<m;j++)
    {
        scanf("%d",&avail[j]);
    }

  
    int f[n], ans[n], ind = 0;  
    for (k = 0; k < n; k++)  
    {  
        f[k] = 0;  
    }  
    int need[n][m];  
    for (i = 0; i < n; i++)  
    {  
        for (j = 0; j < m; j++)  
            need[i][j] = max[i][j] - alloc[i][j];  
    }  
    int y = 0;  
    for (k = 0; k < 5; k++)  
    {  
        for (i = 0; i < n; i++)  
        {  
            if (f[i] == 0)  
            {  
                int flag = 0;  
                for (j = 0; j < m; j++)  
                {  
                    if (need[i][j] > avail[j])  
                    {  
                        flag = 1;  
                        break;  
                    }  
                }  
                if (flag == 0)  
                {  
                    ans[ind++] = i;  
                    for (y = 0; y < m; y++)  
                        avail[y] += alloc[i][y];  
                    f[i] = 1;  
                }  
            }  
        }  
    }  
    int flag = 1;  
    for (int i = 0; i < n; i++)  
    {  
        if (f[i] == 0)  
        {  
            flag = 0;  
            printf("The following system is not safe");  
            break;  
        }  
    }  
    if (flag == 1)  
    {  
        printf("Following is the SAFE Sequence\n");  
        for (i = 0; i < n - 1; i++)  
            printf(" P%d ->", ans[i]);  
        printf(" P%d", ans[n - 1]);  
    }  


  printf("\n\n===============================================");
  printf("\nLab No: 6(a)");
  printf("\nName: Dipesh Shrestha\n");
  printf("Roll No.: 08\n");
  printf("Section: B.Sc.CSIT 4th Semester\n");
  printf("===============================================\n");
    return (0);  
}
