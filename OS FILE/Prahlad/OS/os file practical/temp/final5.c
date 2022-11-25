#include <stdio.h>
#include <stdlib.h>
typedef struct FCFS_scheduling
{
    int at, bt, ct, tat; // arrival,burst,completion,turnaround time
    int wt, rt, st;      // waiting,response,start time
} fcfs;

int comparator(const void *num1, const void *num2)
{
    struct FCFS_scheduling *a = (struct FCFS_scheduling *)num1;
    struct FCFS_scheduling *b = (struct FCFS_scheduling *)num2;
    if (a->at >= b->at)
        return 1;
    else
        return -1;
}

int main()
{
    int n;
    printf("\nEnter the total number of Processs: ");
    scanf("%d", &n);

    fcfs arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter Arrival time and Burst time respectively for process %d  : ", i + 1);
        // arr[i].pid = i + 1;
        scanf("%d%d", &arr[i].at, &arr[i].bt);
    }

    qsort(arr, n, sizeof(fcfs), comparator);

    arr[0].ct = arr[0].at + arr[0].bt;
    arr[0].tat = arr[0].ct - arr[0].at;
    arr[0].wt = arr[0].tat - arr[0].bt;
    arr[0].rt = arr[0].ct - arr[0].bt;
    float avg_tat = arr[0].tat, avg_wt = arr[0].wt;
    float avg_rt = arr[0].rt;
    float cycle_length;
    for (int i = 1; i < n; i++)
    {
        if (arr[i].at >= arr[i - 1].ct)
        {
            arr[i].ct = arr[i].at + arr[i].bt;
        }
        else
            arr[i].ct = arr[i - 1].ct + arr[i].bt;
    }

    for (int i = 1; i < n; i++)
    {
        arr[i].tat = arr[i].ct - arr[i].at;
        arr[i].wt = arr[i].tat - arr[i].bt;
        arr[i].rt = arr[i].ct - arr[i].bt;
    }
    int idt = 0; // idle time variable
    for (int i = 1; i < n; i++)
    {
        int x;
        avg_tat += arr[i].tat;
        avg_wt += arr[i].wt;
        avg_rt += arr[i].rt;
        if (arr[i].at > arr[i - 1].at)
        {
            x = arr[i].at - arr[i - 1].at;
            idt += x;
        }
    }
    // printing table
    printf("  PID\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for (int j = 0; j < n; j++)
    {
        printf("  P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", j + 1, arr[j].at, arr[j].bt, arr[j].ct, arr[j].tat, arr[j].wt, arr[j].rt);
    }

    cycle_length = arr[n - 1].ct;
    float cpu_util = (idt / cycle_length) * 100;
    float tp = (float)n / (cycle_length); // Throughput

    // printing all values
    printf("Average turn around time of all processes is: %f\n", avg_tat / (float)n);
    printf("Average waiting time of total processes is: %f\n", avg_wt / (float)n);
    printf("Average response time of total processes is: %f\n\n", avg_rt / (float)n);
    printf("CPU idle time is: %d\n", idt);
    printf("CPU utilization(in percentage) is: %.2f \n", (float)cpu_util);
    printf("Throughput of all processes is: %f\n\n", tp);
    return 0;
}
