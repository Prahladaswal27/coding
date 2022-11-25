#include <bits/stdc++.h>
using namespace std;
struct pro
{
    int pid;
    int at;
    int st;
    int bt;
    int ct;
    int tat;
    int wt;
    int rt;
    int bt_rem;
} p[10];

bool compfunc(struct pro a, struct pro b)
{
    int x = a.at;
    int y = b.at;
    return x < y;
}

int main()
{
    int n, index, completed = 0;

    cout << "Enter no. of processes: ";
    cin >> n;
    queue<int> q;
    bool vis[n] = {false};
    bool is_first_process = true;
    int current = 0, idle_time = 0, length_cycle;
    int i;
    int sum_tat = 0;
    int sum_wt = 0;
    int sum_rt = 0;
    for (i = 0; i < n; i++)
    {
        printf("\nEnter arrival time of P%d :", i + 1);
        cin >> p[i].at;
        printf("\nEnter burst time of P%d :", i + 1);
        cin >> p[i].bt;

        p[i].pid = i + 1;

        p[i].bt_rem = p[i].bt;
    }

    int time_quanta;
    cout << "\nEnter time quanta : ";
    cin >> time_quanta;

    sort(p, p + n, compfunc);
    q.push(0);
    vis[0] = true;

    while (completed != n)
    {
        index = q.front();
        q.pop();

        if (p[index].bt_rem == p[index].bt)
        {
            p[index].st = max(current, p[index].at);
            idle_time += (is_first_process == true) ? 0 : p[index].st - current;
            current = p[index].st;
            is_first_process = false;
        }

        if (p[index].bt_rem - time_quanta > 0)
        {
            p[index].bt_rem -= time_quanta;
            current += time_quanta;
        }
        else
        {
            current += p[index].bt_rem;
            p[index].bt_rem = 0;
            completed++;

            p[index].ct = current;
            p[index].tat = p[index].ct - p[index].at;
            p[index].wt = p[index].tat - p[index].bt;
            p[index].rt = p[index].st - p[index].at;

            sum_tat += p[index].tat;
            sum_rt += p[index].rt;
            sum_wt += p[index].wt;
        }

        for (i = 1; i < n; i++)
        {
            if (vis[i] == false && p[i].at <= current && p[i].bt_rem > 0)
            {
                q.push(i);
                vis[i] = true;
            }
        }

        if (p[index].bt_rem > 0)
        {
            q.push(index);
        }

        if (q.empty())
        {
            for (i = 1; i < n; i++)
            {
                if (p[i].bt_rem > 0)
                {
                    q.push(i);
                    vis[i] = true;
                    break;
                }
            }
        }
    }

    int total_time = INT_MIN;
    for (i = 0; i < n; i++)
        total_time = max(total_time, p[i].ct);

    length_cycle = total_time - p[0].at;

    cout << "\nPID.\tAT\tBT\tST\tCT\tTAT\tWT\tRT\n";
    for (int i = 0; i < n; i++)
        cout << p[i].pid << "\t  " << p[i].at << "\t" << p[i].bt << "\t" << p[i].st << "\t " << p[i].ct << "\t " << p[i].tat << "\t " << p[i].wt << "\t " << p[i].rt << endl;
    cout << endl;

    cout << "\nAverage Turn Around time= " << (float)sum_tat / n;
    cout << "\nAverage Waiting Time= " << (float)sum_wt / n;
    cout << "\nAverage Response Time= " << (float)sum_rt / n;
    cout << "\nThroughput= " << n / (float)length_cycle;
    cout << "\nCPU Utilization(Percentage)= " << (length_cycle - idle_time) * 100 / (float)length_cycle;

    return 0;
}
/*
   at    bt
1  1     8
2  2     6
3  17    2
4  20    3

tq = 2


*/