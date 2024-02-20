#include <stdio.h>

int find_min_burst_time_process(int burst_time[], int n, int visited[]) {
   int min = 999999, min_index = -1;
   for (int i = 0; i < n; i++) {
      if (burst_time[i] < min && visited[i] == 0) {
        min = burst_time[i];
        min_index = i;
      }
   }
   return min_index;
}

int calculate_times(int proc[], int n, int burst_time[], int wait_time[], int tat[]) {
   int total_wait_time = 0, total_turnaround_time = 0;
   int visited[n];
   for (int i = 0; i < n; i++) {
      visited[i] = 0;
   }
   for (int i = 0; i < n; i++) {
      int min_burst_time_process = find_min_burst_time_process(burst_time, n, visited);
      wait_time[min_burst_time_process] = i == 0 ? 0 : wait_time[min_burst_time_process - 1] + burst_time[min_burst_time_process - 1];
      tat[min_burst_time_process] = wait_time[min_burst_time_process] + burst_time[min_burst_time_process];
      total_wait_time += wait_time[min_burst_time_process];
      total_turnaround_time += tat[min_burst_time_process];
      visited[min_burst_time_process] = 1;
   }
   printf("Average waiting time = %f", (float)total_wait_time / (float)n);
   printf("Average turnaround time = %f", (float)total_turnaround_time / (float)n);
   return 0;
}

int main() {
   int proc[] = { 1, 2, 3};
   int n = sizeof proc / sizeof proc[0];
   int burst_time[] = {5, 8, 12};
   int wait_time[n], tat[n];
   calculate_times(proc, n, burst_time, wait_time, tat);
   return 0;
}