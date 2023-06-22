#include <stdio.h>
struct process {
 int arrival_time;
 int burst_time;
 int remaining_time;
 int waiting_time;
 int turnaround_time;
 int completed;
};
int main() {
 int n = 4, t = 0, min_burst_time, min_index;
 struct process processes[] = {
 {0, 5, 5, 0, 0, 0},
 {1, 3, 3, 0, 0, 0},
 {2, 3, 3, 0, 0, 0},
 {4, 1, 1, 0, 0, 0}
 };
 while (1) {
 min_burst_time = 9999;
 min_index = -1;
for (int i = 0; i < n; i++) {
 if (processes[i].arrival_time <= t && processes[i].completed == 0) {
 if (processes[i].remaining_time < min_burst_time) {
 min_burst_time = processes[i].remaining_time;
 min_index = i;
 }
 }
 }
 if (min_index == -1) {
 break;
 }
 processes[min_index].remaining_time--;
 t++;
 for (int i = 0; i < n; i++) {
 if (processes[i].arrival_time <= t && processes[i].completed == 0) {
 if (i != min_index) {
 processes[i].waiting_time++;
 }
 if (processes[i].remaining_time == 0) {
 processes[i].completed = 1;
 processes[i].turnaround_time = t - processes[i].arrival_time;
 }
 }
 }
 }
 float avg_waiting_time = 0, avg_turnaround_time = 0;
 for (int i = 0; i < n; i++) {
 avg_waiting_time += processes[i].waiting_time;
 avg_turnaround_time += processes[i].turnaround_time;
 }
 avg_waiting_time /= n;
 avg_turnaround_time /= n;
 printf("Average Waiting Time: %.2f ms\n", avg_waiting_time);
 printf("Average Turnaround Time: %.2f ms\n", avg_turnaround_time);
 return 0;
}
