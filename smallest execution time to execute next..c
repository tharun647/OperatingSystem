#include <stdio.h>

struct Process {
    int pid;
    int burst_time;
};

int main() {
    
    struct Process processes[] = {{1, 8}, {2, 4}, {3, 9}, {4, 5}};
    int num_processes = sizeof(processes) / sizeof(processes[0]);

    int completion_time[num_processes];

    int current_time = 0;

    while (1) {
        int min_burst_time = 99999;
        int min_burst_time_index = -1;
        int completed_processes = 0;

        for (int i = 0; i < num_processes; i++) {
            if (completion_time[i] == -1) {
                if (processes[i].burst_time < min_burst_time) {
                    min_burst_time = processes[i].burst_time;
                    min_burst_time_index = i;
                }
            } else {
                completed_processes++;
            }
        }

        if (completed_processes == num_processes) {
            break;
        }

        current_time += min_burst_time;
        completion_time[min_burst_time_index] = current_time;
    }
    for (int i = 0; i < num_processes; i++) {
        printf("Process %d: burst time = %d, completion time = %d\n",
               processes[i].pid, processes[i].burst_time, completion_time[i]);
    }

    return 0;
}

