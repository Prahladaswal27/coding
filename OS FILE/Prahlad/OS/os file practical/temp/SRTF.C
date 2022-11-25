// SRTF
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct process
{
    int at, bt, st, ct, tat, wt, rt, pid, bt_remaining, is_completed;
} st;
int compare(const void *a, const void *b)
{
    st *p1 = (st *)a;
    st *p2 = (st *)b;
    return p1->at > p2->at;
}
void calc_print(st *a, int n, float total_it)
{
    float total_wt = 0, total_tat = 0, total_rt = 0;
    printf("\nPid\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++)
    {
        total_wt += a[i].wt;
        total_tat += a[i].tat;
        total_rt += a[i].rt;
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", a[i].pid, a[i].at, a[i].bt, a[i].ct, a[i].tat, a[i].wt, a[i].rt);
    }
    printf("\nAverage Waiting time: %f\n", total_wt / (float)n);
    printf("Average Turn Around time %f\n", total_tat / (float)n);
    printf("Average Response time %f\n", total_rt / (float)n);
    printf("CPU utilization %f\n", ((a[n - 1].ct - total_it) / (float)a[n - 1].ct) * 100);
    printf("Throughput %f\n", (float)n / (a[n - 1].ct - a[0].at));
}
int main()
{
    int n;
    printf("Enter the No of process : ");
    scanf("%d", &n);

    st a[n];

    for (int i = 0; i < n; i++)
    {
        printf("For process %d Enter arrival time and Burst time respectively : ", i + 1);
        a[i].pid = i + 1;
        scanf("%d%d", &a[i].at, &a[i].bt);
        a[i].bt_remaining = a[i].bt;
        a[i].is_completed = 0;
    }
    int current_time = 0, completed = 0, total_it = 0, prev = 0;
    qsort(a, n, sizeof(st), compare);
    while (completed != n)
    {
        int idx = -1, mn = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (a[i].at <= current_time && a[i].is_completed == 0)
            {
                if (a[i].bt_remaining < mn)
                {
                    mn = a[i].bt_remaining;
                    idx = i;
                }
                if (a[i].bt_remaining == mn)
                {
                    if (a[i].at < a[idx].at)
                    {
                        mn = a[i].bt_remaining;
                        idx = i;
                    }
                }
            }
        }
        if (idx != -1)
        {
            if (a[idx].bt_remaining == a[idx].bt)
            {
                a[idx].st = current_time;
                total_it += a[idx].st - prev;
            }
            a[idx].bt_remaining -= 1;
            current_time++;
            prev = current_time;
            if (a[idx].bt_remaining == 0)
            {
                a[idx].ct = current_time;
                a[idx].tat = a[idx].ct - a[idx].at;
                a[idx].wt = a[idx].tat - a[idx].bt;
                a[idx].rt = a[idx].st - a[idx].at;
                a[idx].is_completed = 1;
                completed++;
            }
        }
        else
        {
            current_time++;
        }
    }
    calc_print(a, n, total_it);
}

// dilip
// #include <stdio.h>
// #include <math.h>
// struct process_struct
// {
//     int pid;
//     int at;
//     int bt;
//     int ct, wt, tat, rt, start_time;
// } p[100];

// int findmax(int a, int b)
// {
//     return a > b ? a : b;
// }

// int findmin(int a, int b)
// {
//     return a < b ? a : b;
// }

// int main()
// {

//     int n;
//     float bt_remaining[100];
//     bool is_completed[100] = {false}, is_first_process = true;
//     int current_time = 0;
//     int completed = 0;
//     ;
//     float sum_tat = 0, sum_wt = 0, sum_rt = 0, total_idle_time = 0, length_cycle, prev = 0;
//     float cpu_utilization;

//     int max_completion_time, min_aival_time;

//     printf("Enter total number of processes: ");
//     scanf("%d", &n);
//     for (int i = 0; i < n; i++)
//     {
//         printf("\nEnter Process %d aival Time: ", i);
//         scanf("%d", &ps[i].at);
//         ps[i].pid = i;
//     }

//     for (int i = 0; i < n; i++)
//     {
//         printf("\nEnter Process %d Burst Time: ", i);
//         scanf("%d", &ps[i].bt);
//         bt_remaining[i] = ps[i].bt;
//     }

//     while (completed != n)
//     {
//         // find process with min. burst time in ready queue at current time
//         int min_index = -1;
//         int minimum = INT_MAX;
//         for (int i = 0; i < n; i++)
//         {
//             if (ps[i].at <= current_time && is_completed[i] == false)
//             {
//                 if (bt_remaining[i] < minimum)
//                 {
//                     minimum = bt_remaining[i];
//                     min_index = i;
//                 }
//                 if (bt_remaining[i] == minimum)
//                 {
//                     if (ps[i].at < ps[min_index].at)
//                     {
//                         minimum = bt_remaining[i];
//                         min_index = i;
//                     }
//                 }
//             }
//         }

//         if (min_index == -1)
//         {
//             current_time++;
//         }
//         else
//         {
//             if (bt_remaining[min_index] == ps[min_index].bt)
//             {
//                 ps[min_index].start_time = current_time;
//                 total_idle_time += (is_first_process == true) ? 0 : (ps[min_index].start_time - prev);
//                 is_first_process = false;
//             }
//             bt_remaining[min_index] -= 1;
//             current_time++;
//             prev = current_time;
//             if (bt_remaining[min_index] == 0)
//             {
//                 ps[min_index].ct = current_time;
//                 ps[min_index].tat = ps[min_index].ct - ps[min_index].at;
//                 ps[min_index].wt = ps[min_index].tat - ps[min_index].bt;
//                 ps[min_index].rt = ps[min_index].start_time - ps[min_index].at;

//                 sum_tat += ps[min_index].tat;
//                 sum_wt += ps[min_index].wt;
//                 sum_rt += ps[min_index].rt;
//                 completed++;
//                 is_completed[min_index] = true;
//                 // total_idle_time += (is_first_process==true) ? 0 : (ps[min_index].start_time -  prev);
//                 //  prev= ps[min_index].ct; // or current_time;
//             }
//         }
//     }
//     // Calculate Length of Process completion cycle
//     max_completion_time = INT_MIN;
//     min_aival_time = INT_MAX;
//     for (int i = 0; i < n; i++)
//     {
//         max_completion_time = findmax(max_completion_time, ps[i].ct);
//         min_aival_time = findmin(min_aival_time, ps[i].at);
//     }
//     length_cycle = max_completion_time - min_aival_time;

//     // Output
//     printf("\nProcess No.\tAT\tCPU Burst Time\tCT\tTAT\tWT\tRT\n");
//     for (int i = 0; i < n; i++)
//         printf("%d\t\t%d\t%d\t\t%d\t%d\t%d\t%d\n", ps[i].pid, ps[i].at, ps[i].bt, ps[i].ct, ps[i].tat, ps[i].wt, ps[i].rt);

//     printf("\n");

//     cpu_utilization = (float)(length_cycle - total_idle_time) / length_cycle;

//     printf("\nAverage Turn Around time= %f ", (float)sum_tat / n);
//     printf("\nAverage Waiting Time= %f ", (float)sum_wt / n);
//     printf("\nAverage Response Time= %f ", (float)sum_rt / n);
//     printf("\nThroughput= %f", n / (float)length_cycle);
//     printf("\nCPU Utilization(Percentage)= %f", cpu_utilization * 100);
//     return 0;
// }