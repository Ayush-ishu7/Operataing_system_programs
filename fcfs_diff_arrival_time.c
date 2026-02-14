// write a program to show fcfs(first come first serve) with different arrival time.

#include <stdio.h>

int main()
{
    int bt[20], wt[20], tat[20], at[20], ct[20];
    int i, n;
    float wtavg = 0, tatavg = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter Arrival Time for Process %d: ", i);
        scanf("%d", &at[i]);

        printf("Enter Burst Time for Process %d: ", i);
        scanf("%d", &bt[i]);
    }

    ct[0] = at[0] + bt[0];
    tat[0] = ct[0] - at[0];
    wt[0]  = tat[0] - bt[0];

    for(i = 1; i < n; i++)
    {
        if(ct[i-1] < at[i])
            ct[i] = at[i] + bt[i];   
        else
            ct[i] = ct[i-1] + bt[i];

        tat[i] = ct[i] - at[i];
        wt[i]  = tat[i] - bt[i];
    }

    printf("\nPROCESS\tAT\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\n",
               i, at[i], bt[i], wt[i], tat[i]);

        wtavg += wt[i];
        tatavg += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", wtavg / n);
    printf("\nAverage Turnaround Time = %.2f\n", tatavg / n);

    return 0;
}
