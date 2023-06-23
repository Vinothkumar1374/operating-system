}#include<stdio.h>
struct Process {
    int pid;
    int burst_time;
    int priority;
    int waiting_time;
    int turnaround_time;
};
int main() {
    int n = 3;
    struct Process processes[n];
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    processes[0].pid = 1;
    processes[0].burst_time = 30;
    processes[0].priority = 2;
	processes[1].pid = 2;
    processes[1].burst_time = 5;
    processes[1].priority = 1;
	processes[2].pid = 3;
    processes[2].burst_time = 12;
    processes[2].priority = 3;
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(processes[i].priority > processes[j].priority) {
                struct Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
    processes[0].waiting_time = 0;
    processes[0].turnaround_time = processes[0].burst_time;
	for(int i = 1; i < n; i++) {
        processes[i].waiting_time = processes[i-1].turnaround_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }
    for(int i = 0; i < n; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }
    printf("Process\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for(int i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, processes[i].priority, processes[i].waiting_time, processes[i].turnaround_time);
    }
	float avg_waiting_time = (float)total_waiting_time / n;
    float avg_turnaround_time = (float)total_turnaround_time / n;
	printf("Average Waiting Time = %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time = %.2f\n", avg_turnaround_time);
}
