#include <stdio.h>
#include <stdlib.h>
struct process_struct
{
    int pid;
    int at;                          // Arrival Time
    int bt;                          // CPU Burst time
    int ct, wt, tat, rt, start_time; // Completion, waiting, turnaround, response
} prcs[100];                         // Array of structure to store the info of each process.

int findmax(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int comp_AT(const void *a, const void *b)
{
    int x = ((struct process_struct *)a)->at;
    int y = ((struct process_struct *)b)->at;
    if (x < y)
        return -1;   // No sorting
    else if (x >= y) // = is for stable sort
        return 1;    // Sort
}
int main()
{
    printf("Name- Vibhor Goswami\nSec-A\nStudent id=20011888");
    int n;
    printf("\nTotal Processes: ");
    scanf("%d", &n);
    float sum_tat = 0, sum_wt = 0, sum_rt = 0;
    int LC, total_idle_time = 0; // Length Cycle
    float cpu_util;

    for (int i = 0; i < n; i++)
    {
        printf("Enter Process %d Arrival Time: ", i);
        scanf("%d", &prcs[i].at);
        prcs[i].pid = i;
    }

    for (int i = 0; i < n; i++)
    {
        printf("Enter Process %d Burst Time: ", i);
        scanf("%d", &prcs[i].bt);
    }

    // sort
    qsort((void *)prcs, n, sizeof(struct process_struct), comp_AT);

    // calculations
    for (int i = 0; i < n; i++)
    {
        prcs[i].start_time = (i == 0) ? prcs[i].at : findmax(prcs[i].at, prcs[i - 1].ct);
        prcs[i].ct = prcs[i].start_time + prcs[i].bt;
        prcs[i].tat = prcs[i].ct - prcs[i].at;
        prcs[i].wt = prcs[i].tat - prcs[i].bt;
        prcs[i].rt = prcs[i].wt;

        sum_tat += prcs[i].tat;
        sum_wt += prcs[i].wt;
        sum_rt += prcs[i].rt;
        total_idle_time += (i == 0) ? 0 : (prcs[i].start_time - prcs[i - 1].ct);
    }
    LC = prcs[n - 1].ct - prcs[0].start_time;

    printf("\nProcess No.\tAT\tCPU Burst Time\tCT\tTAT\tWT\tRT\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t%d\t\t%d\t%d\t%d\t%d\n", prcs[i].pid, prcs[i].at, prcs[i].bt, prcs[i].ct, prcs[i].tat, prcs[i].wt, prcs[i].rt);

        printf("\n");
    }

    cpu_util = (float)(LC - total_idle_time) / LC;

    printf("\nAverage TAT :- %f ", sum_tat / n);
    printf("\nAverage WT :- %f ", sum_wt / n);
    printf("\nAverage RT :- %f ", sum_rt / n);
    printf("\nThroughput :- %f", n / (float)LC);
    printf("\nCPU Utilization (in Percentage) :- %f", cpu_util * 100);

    printf("\n");
    return 0;
}

// FCFS
// •  Schedules the jobs according to their arrival time. The job which comes first in the ready queue will get the CPU first.
// •  The lesser the arrival time of the job, the sooner the job will get the CPU.
