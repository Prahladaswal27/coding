#include <stdio.h>
#include <stdlib.h>
struct srtf
{
  int pid;
  int at;
  int bt;
  int rbt;
  int ct;
  int tat;
  int wt;
  int rt;
  int st;
};
int com(const void *p, const void *q)
{
  int l = ((struct srtf *)p)->at;
  int r = ((struct srtf *)q)->at;
  return (l - r);
}
int main()
{
      printf("Jay Upadhyay\n");
      int p;
      int total_idle_time = 0, prev = 0;
    float avgwt = 0, avgtat = 0, avgrt = 0;
    printf("enter total process :\n");
    scanf("%d", &p);
    printf("\nenter at and bt: \n");
    struct srtf a[p];
    for (int i = 0; i < p; i++)
    {
      a[i].pid = i + 1;
      scanf("%d%d", &a[i].at, &a[i].bt);
      a[i].rbt = a[i].bt;
    }
    qsort((void *)a, p, sizeof(a[0]), com);
    int pc = 0, i = 0;
    while (i < p)
    {
      int k = -1;
      int min = 9999999;
      for (int j = 0; j < p; j++)
      {
        if (a[j].at <= pc && a[j].rbt != 0)
        {
          if (a[j].rbt < min)
          {
            min = a[j].rbt;
            k = j;
          }
          if (a[j].rbt == min)
          {
            if (a[j].at < a[k].at)
            {
              min = a[j].rbt;
              k = j;
            }
          }
        }
      }
      if (k != -1)
      {
        if (a[k].rbt == a[k].bt)
        {
          a[k].st = pc;
          total_idle_time += a[k].st - prev;
        }
        a[k].rbt -= 1;
        pc++;
        prev = pc;
        if (a[k].rbt == 0)
        {
          a[k].ct = pc;
          i++;
          a[k].tat = a[k].ct - a[k].at;
          a[k].wt = a[k].tat - a[k].bt;
          a[k].rt = a[k].st - a[k].at;
          avgwt = avgwt + a[k].wt;
          avgrt = avgrt + a[k].rt;
          avgtat = avgtat + a[k].tat;
        }
      }
      else
      {
        pc++;
      }
    }
  printf("pid\tat\tbt\tst\tct\ttat\twt\trt \n");
  for (i = 0; i < p; i++)
  {
    printf("\n%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d", a[i].pid, a[i].at, a[i].bt, a[i].st, a[i].ct, a[i].tat, a[i].wt, a[i].rt);
  }
  printf("\n average waiting time : %f \n average response time : %f \n average tat : %f \n cpu ideal time : %d \n", avgwt / p, avgrt / p, avgtat / p, total_idle_time);

  float length_cycle = pc - a[0].at;
  float cpu = (length_cycle - total_idle_time) / length_cycle * 100;
  printf("\nlength cycle : %f\n Cpu utilisation: %f\n throughput : %f ", length_cycle, cpu, (float)(p) / (length_cycle));
}

// #include <stdio.h>
// #include <stdlib.h>

// typedef struct process
// {
//     int pid, at, bt, st, ct, tat, wt, rt, rbt;
// } SRTF;

// int comp(const void *num1, const void *num2)
// {
//     int l = ((struct process *)num1)->at;
//     int r = ((struct process *)num2)->at;
//     return (l - r);
// }

// int main()
// {
//     int n;
//     scanf("%d", &n);

//     int idlt = 0, prev = 0;
//     float total_tat = 0, total_wt = 0, total_rt = 0;
//     SRTF arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         printf("\nEnter the values of arrival and burst time of P%d: ", i + 1);
//         scanf("%d %d", &arr[i].at, &arr[i].bt);
//         arr[i].pid = i + 1;
//         arr[i].rbt = arr[i].bt;
//     }

//     qsort((void *)arr, n, sizeof(arr[0]), comp);
//     int currentime = 0, i = 0;
//     while (i < n)
//     {
//         int k = -1;
//         int min = 9999999;

//         for (int j = 0; j < n; j++)
//         {
//             if (arr[j].at <= currentime && arr[j].rbt != 0)
//             {
//                 if (arr[j].rbt < min)
//                 {
//                     min = arr[j].rbt;
//                     k = j;
//                 }
//                 if (arr[j].rbt == min)
//                 {
//                     if (arr[j].at < arr[k].at)
//                     {
//                         min = arr[j].rbt;
//                         k = j;
//                     }
//                 }
//             }
//         }
//         if (k != -1)
//         {
//             if (arr[k].rbt == arr[k].bt)
//             {
//                 arr[k].st = currentime;
//                 idlt = idlt + arr[k].st - prev;
//             }
//             arr[k].rbt -= 1;
//             currentime++;
//             prev = currentime;

//             if (arr[k].rbt == 0)
//             {
//                 arr[k].ct = currentime;
//                 i++;

//                 arr[k].tat = arr[k].ct - arr[k].at;
//                 arr[k].wt = arr[k].tat - arr[k].bt;
//                 arr[k].rt = arr[k].st - arr[k].at;
//                 total_tat += arr[k].tat;
//                 total_wt += arr[k].wt;
//                 total_rt += arr[k].rt;
//             }
//         }

//         else
//         {
//             currentime++;
//         }

//         printf("pid\tat\tbt\tst\tct\ttat\twt\trt \n");
//         for (i = 0; i < n; i++)
//         {
//             printf("\n%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d", arr[i].pid, arr[i].at, arr[i].bt, arr[i].st, arr[i].ct, arr[i].tat, arr[i].wt, arr[i].rt);
//         }
//         printf("\n average waiting time : %f \n average response time : %f \n average tat : %f \n cpu ideal time : %d \n", total_wt / n, total_rt / n, total_tat / n, idlt);

//         float length_cycle = currentime - arr[0].at;
//         float cpu = (length_cycle - idlt) / length_cycle * 100;
//         printf("\nlength cycle : %f\n Cpu utilisation: %f\n throughput : %f ", length_cycle, cpu, (float)(n) / (length_cycle));
//     }

//     return 0;
// }
