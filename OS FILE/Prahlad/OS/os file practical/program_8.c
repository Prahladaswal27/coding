/*
    Write a C program to demonstrate Round Robin Scheduling.

    Round Robin CPU Algorithm generally focuses on Time Sharing technique. The period of time for which a process or job is allowed to run in a pre-emptive method is called time quantum. Each process or job present in the ready queue is assigned the CPU for that time quantum, if the execution of the process is completed during that time then the process will end else the process will go back to the waiting table and wait for its next turn to complete the execution.
*/
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef struct round_robin
{
    int pid, at, bt, ct, tat, wt, rt, st, r_bt, vis;
} rr;
int comp(const void *num1, const void *num2)
{
    rr *p1 = (rr *)num1;
    rr *p2 = (rr *)num2;
    return p1->at > p2->at;
}
int max_value(int x, int y)
{
    if (x <= y)
        return y;

    return x;
}

int main()
{
    printf("\nName - Prahlad Singh Aswal\nSection - A\n");
    printf("Student ID - 20011854\n");

    int n, i = 0, curr_time = 0, first_process = 0, time_quan, front = -1, rear = -1;
    int q[100];
    float idle_time = 0;
    printf("\nEnter the Number of Process: ");
    scanf("%d", &n);

    rr arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter Arrival time and Burst time for process P%d : ", i + 1);
        arr[i].pid = i + 1;
        scanf("%d%d", &arr[i].at, &arr[i].bt);
        arr[i].r_bt = arr[i].bt;
        arr[i].vis = 0;
    }

    printf("\nEnter the time quantam: ");
    scanf("%d", &time_quan);
    qsort(arr, n, sizeof(rr), comp);
    arr[0].vis = 1;
    front = rear = 0;
    q[rear] = 0;

    while (i != n)
    {
        int j = q[front];
        front++;
        if (arr[j].bt == arr[j].r_bt)
        {
            arr[j].st = max_value(curr_time, arr[j].at);
            curr_time = arr[j].st;
            if (first_process == 1)
            {
                idle_time += 0;
            }
            else
            {
                idle_time += arr[j].st - curr_time;
            }
        }
        if (arr[j].r_bt - time_quan > 0)
        {
            arr[j].r_bt -= time_quan;
            curr_time += time_quan;
        }
        else
        {
            curr_time += arr[j].r_bt;
            i++;
            arr[j].ct = curr_time;
            arr[j].tat = arr[j].ct - arr[j].at;
            arr[j].wt = arr[j].tat - arr[j].bt;
            arr[j].rt = arr[j].st - arr[j].at;
            arr[j].r_bt = 0;
        }
        for (int i = 0; i < n; i++)
        {
            if (arr[i].at <= curr_time && arr[i].vis != 1)
            {
                rear++;
                q[rear] = i;
                arr[i].vis = 1;
            }
        }
        if (arr[j].r_bt != 0)
        {
            rear++;
            q[rear] = j;
        }
    }
    float sum_wt = 0, sum_tat = 0, sum_rt = 0;
    printf("\nPid\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++)
    {
        sum_wt += arr[i].wt;
        sum_tat += arr[i].tat;
        sum_rt += arr[i].rt;
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", arr[i].pid, arr[i].at, arr[i].bt, arr[i].ct, arr[i].tat, arr[i].wt, arr[i].rt);
    }
    float avg_wt = sum_wt / (float)n, avg_tat = sum_tat / (float)n, avg_rt = sum_rt / (float)n;
    printf("\nAverage Waiting time: %f\n", avg_wt);
    printf("Average Turn Around time: %f\n", avg_tat);
    printf("Average Response time: %f\n", avg_rt);
    printf("CPU utilization(in percentage): %f\n", ((arr[n - 1].ct - idle_time) / (float)arr[n - 1].ct) * 100);
    printf("Throughput: %f\n", (float)n / (arr[n - 1].ct - arr[0].at));
    return 0;
}