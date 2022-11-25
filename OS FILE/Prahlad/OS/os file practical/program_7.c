// SRTF
#include <stdio.h>
#include <stdlib.h>

typedef struct SRTF
{
    int pid, at, bt, ct, wt, tat, st, rt, rbt;
} srtf;

int comp(const void *p1, const void *p2)
{
    int l = ((srtf *)p1)->at;
    int r = ((srtf *)p2)->at;
    return (l - r);
}

int main()
{
    int n;
    printf("\nEnter the number of process: ");
    scanf("%d", &n);
    int idt = 0, prev = 0;
    float avgwt = 0, avgtat = 0, avgrt = 0;
    srtf arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter the arrival and burst time of the process: ");
        scanf("%d %d", &arr[i].at, &arr[i].bt);
        arr[i].pid = i + 1;
        arr[i].rbt = arr[i].bt;
    }

    qsort((void *)arr, n, sizeof(arr[0]), comp);
    int i = 0, pc = 0;

    while (i < n)
    {
        int k = -1;
        int min = 9999999;
        for (int j = 0; j < n; j++)
        {
            if (arr[j].at <= pc && arr[j].rbt != 0)
            {
                if (arr[j].rbt < min)
                {
                    min = arr[j].rbt;
                    k = j;
                }
                if (arr[j].rbt == min)
                {
                    if (arr[j].at < arr[k].at)
                    {
                        min = arr[j].rbt;
                        k = j;
                    }
                }
            }
        }
        if (k != -1)
        {
            if (arr[k].rbt == arr[k].bt)
            {
                arr[k].st = pc;
                idt += arr[k].st - prev;
            }
            arr[k].rbt = arr[k].rbt - 1;
            pc++;
            prev = pc;

            if (arr[k].rbt == 0)
            {
                arr[k].ct = pc;
                i++;
                arr[k].tat = arr[k].ct - arr[k].at;
                arr[k].wt = arr[k].tat - arr[k].bt;
                arr[k].rt = arr[k].st - arr[k].at;
                avgwt = avgwt + arr[k].wt;
                avgrt = avgrt + arr[k].rt;
                avgtat = avgtat + arr[k].tat;
            }
        }
        else
            pc++;
    }
    printf("  PID\tAT\tBT\tST\tCT\tTAT\tWT\tRT\n");
    for (int j = 0; j < n; j++)
    {
        printf("  P%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", arr[j].pid, arr[j].at, arr[j].bt, arr[j].st, arr[j].ct, arr[j].tat, arr[j].wt, arr[j].rt);
    }

    int cycle_length = pc - arr[0].at;
    float cpu_util = ((cycle_length - idt) / cycle_length) * 100;
    float tp = (float)n / (cycle_length); // Throughput

    printf("Average turn around time of all processes is: %f\n", avgtat / (float)n);
    printf("Average waiting time of total processes is: %f\n", avgwt / (float)n);
    printf("Average response time of total processes is: %f\n", avgrt / (float)n);
    printf("CPU idle time is: %d\n", idt);
    printf("CPU utilization(in percentage) is: %.2f \n", (float)cpu_util);
    printf("Throughput of all processes is: %f\n\n", tp);
    return 0;
}