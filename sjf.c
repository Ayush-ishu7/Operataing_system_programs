#include <stdio.h>

int main()
{
    int n, i, time = 0, done = 0;
    int at[20], bt[20], ct[20], wt[20], tat[20];
    int visited[20] = {0}, order[20], start[20];
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("AT and BT for P%d: ", i);
        scanf("%d %d", &at[i], &bt[i]);
    }

    while (done < n)
    {
        int min = -1;

        for (i = 0; i < n; i++)
        {
            if (at[i] <= time && !visited[i])
            {
                if (min == -1 || bt[i] < bt[min])
                    min = i;
            }
        }

        if (min == -1)
        {
            time++;
        }
        else
        {
            start[done] = time;
            order[done] = min;

            ct[min] = time + bt[min];
            tat[min] = ct[min] - at[min];
            wt[min] = tat[min] - bt[min];

            avg_wt += wt[min];
            avg_tat += tat[min];

            time = ct[min];
            visited[min] = 1;
            done++;
        }
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage WT = %.2f", avg_wt / n);
    printf("\nAverage TAT = %.2f\n", avg_tat / n);

    // Gantt Chart
    printf("\nGantt Chart:\n| ");
    for (i = 0; i < n; i++)
        printf("P%d | ", order[i]);

    printf("\n%d", start[0]);
    for (i = 0; i < n; i++)
        printf("   %d", ct[order[i]]);

    return 0;
}