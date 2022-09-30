
#include<stdio.h>
#include<stdlib.h>

struct fcfs{
 int pid, arrival_time, bus_time, waiting_time, completion_time, response_time,total_arrival_time,total_waiting_time;
};


int compare (const void *p1, const void *p2)
{

 int first = ((struct fcfs *)p1)->arrival_time;
 int second = ((struct fcfs *)p2)->arrival_time;
 
 if(first < second)
  return -1;
 else
  return 1;

}

int processcompare (const void *p1, const void *p2)
{

 int first = ((struct fcfs *)p1)->pid;
 int second = ((struct fcfs *)p2)->pid;
 
 if(first < second)
  return -1;
 else
  return 1;

}

int main(){

 int n;
 printf("Enter the Number of Process : ");
 scanf("%d",&n);
 
 
 struct fcfs process[n];
 int Average_Completion_Time = 0, Average_Waiting_Time = 0 , sumOfWaitingTime = 0, sumOfArrivalTime = 0; 
 
 for(int i = 0; i<n; ++i)
 {
  process[i].pid = i+1;
  printf("Enter the arrival time of process : ");
  scanf(" %d",&process[i].arrival_time) ;
 
  printf("Enter the bus time of process : ");
  scanf(" %d",&process[i].bus_time) ;
 }
 
 for(int i= 0; i<n; ++i)
 {
  printf("%d %d\n",process[i].arrival_time,process[i].bus_time);
 }
 
 qsort ((void *)process, n, sizeof(struct fcfs), compare);

 
 for(int i = 0; i<n; ++i)
 {
  if(i == 0)
  {
   process[i].completion_time = process[i].arrival_time + process[i].bus_time;
  }
  
  else if(process[i].arrival_time >= process[i-1].completion_time)
  {
   process[i].completion_time = process[i].arrival_time + process[i].bus_time;
  }
  else
  {
   process[i].completion_time = process[i-1].completion_time + process[i].bus_time;
  }
  
  
  process[i].total_arrival_time = process[i].completion_time + process[i].bus_time;
  process[i].waiting_time = process[i].total_arrival_time - process[i].bus_time;
  
  sumOfWaitingTime = process[i].total_waiting_time;
  sumOfArrivalTime = process[i].total_arrival_time;
 
 
   process[i].response_time = process[i].completion_time - process[i].bus_time;
 }
 
 
 Average_Completion_Time = sumOfArrivalTime / n;
 Average_Waiting_Time = sumOfWaitingTime / n ;
 

 qsort ((void *)process, n, sizeof(struct fcfs), processcompare);

 printf("\nProcess ID\tArrival Time\tBus Time\tCompletion Time\tArrival Time\tWaiting Time \tResponse Time\n");
 
   for(int i=0;i<n;i++)
   {
      printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",process[i].pid,process[i].arrival_time,process[i].bus_time,process[i].completion_time,process[i].total_arrival_time,process[i].waiting_time,process[i].response_time);
   }
 
   printf("\nSum of Turn Around Time: %d\nAverage of Turn Around Time: %d\n",sumOfArrivalTime,Average_Completion_Time);
   printf("Sum of Waiting Time: %d\nAverage of Waiting Time: %d\n\n",sumOfWaitingTime,Average_Waiting_Time);

return 0;

}
