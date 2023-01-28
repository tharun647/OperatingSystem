#include <stdio.h>
struct Process {
    int pid;
    int burst_time;
};

int main() {
    struct Process processes[] = {{1, 8}, {2, 4}, {3, 9}, {4, 5}};
    int num_processes = sizeof(processes) / sizeof(processes[0]);
  int completion_time[num_processes];
    int total_waiting_time = 0;
    int current_time = 0;
    float avg_waiting_time;
    for (int i = 0; i < num_processes; i++) {
        completion_time[i] = current_time + processes[i].burst_time;
        current_time = completion_time[i];
        int waiting_time = completion_time[i] - processes[i].burst_time;
        total_waiting_time += waiting_time;
        printf("Process %d: burst time = %d, waiting time = %d, completion time = %d\n",
               processes[i].pid, processes[i].burst_time, waiting_time, completion_time[i]);
    }
    avg_waiting_time = (float) total_waiting_time / num_processes;

    printf("\nAverage waiting time: %f\n", avg_waiting_time);

    return 0;
}

