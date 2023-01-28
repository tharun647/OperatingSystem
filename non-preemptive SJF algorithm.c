#include <stdio.h>
#include <stdlib.h>
#define MAX_PROCESSES 10
struct Process {
    int pid;
    int burst_time;
    int waiting_time;
    int completion_time;
};
int shortestBurstTime(struct Process processes[], int n, int time) {
    int shortest_burst_time = INT_MAX;
    int shortest_burst_time_index = -1;
    for (int i = 0; i < n; i++) {
        if (processes[i].burst_time > 0 && processes[i].burst_time < shortest_burst_time) {
            shortest_burst_time = processes[i].burst_time;
            shortest_burst_time_index = i;
        }
    }
    return shortest_burst_time_index;
}
int main() {
    struct Process processes[MAX_PROCESSES] = {
        {1, 5, 0, 0},
        {2, 4, 0, 0},
        {3, 2, 0, 0},
        {4, 6, 0, 0},
        {5, 1, 0, 0}
    };
    int n = sizeof(processes) / sizeof(processes[0]);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[i].burst_time > processes[j].burst_time) {
                struct Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
    int time = 0;
    for (int i = 0; i < n; i++) {
        int current_process = shortestBurstTime(processes, n, time);
        if (current_process != -1) {
            time += processes[current_process].burst_time;
            processes[current_process].burst_time = 0;
            processes[current_process].waiting_time = time - processes[current_process].burst_time;
            processes[current_process].completion_time = time;
        }
    }
    printf("Process ID\tBurst Time\tWaiting Time\tCompletion Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, 
            processes[i].waiting_time, processes[i].completion_time);
    }
    return 0;
}
