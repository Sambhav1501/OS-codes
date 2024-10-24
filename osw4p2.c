//priority scheduling
#include <stdio.h>

// Define a structure for the process
struct Process {
    int pid;        // Process ID
    int burst;      // Burst time
    int arrival;    // Arrival time
    int priority;   // Priority
    int waiting;    // Waiting time
    int turnaround; // Turnaround time
    int completion; // Completion time
    int completed;  // Flag to indicate if the process is completed
};

int main() {
    int n;
    

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    struct Process proc[n];
    //int ganttChart[n]; // To store the execution order of processes
    //int ganttTime[n];  // To store the times at which processes are completed
    
    for (int i = 0; i < n; i++) {
        printf("Enter Burst Time, Arrival Time, and Priority for Process %d: ", i + 1);
        proc[i].pid = i + 1;
        scanf("%d %d %d", &proc[i].burst, &proc[i].arrival, &proc[i].priority);
        proc[i].waiting = 0;
        proc[i].turnaround = 0;
        proc[i].completion = 0;
        proc[i].completed = 0;  // Initialize as not completed
    }

    int time = 0, completedCount = 0, ganttIndex = 0;
    printf("Gantt Chart: ");
    while (completedCount < n) {
        int minPriority = __INT_MAX__;
        int minIndex = -1;
        
        // Find the process with the highest priority that has arrived
        for (int i = 0; i < n; i++) {
            if (proc[i].arrival <= time && !proc[i].completed && proc[i].priority < minPriority) {
                minPriority = proc[i].priority;
                minIndex = i;
            }
        }

        if (minIndex != -1) {
            proc[minIndex].waiting = time - proc[minIndex].arrival;
            proc[minIndex].turnaround = proc[minIndex].waiting + proc[minIndex].burst;
            time += proc[minIndex].burst;
            proc[minIndex].completion = time; // Store the completion time for the process
            proc[minIndex].completed = 1;
            //ganttChart[ganttIndex] = minIndex; // Store the index of the executed process
            //ganttTime[ganttIndex] = time;      // Store the time when the process finished
            //ganttIndex++;
            completedCount++;
            printf("  P%d  ", proc[minIndex].pid);
        } else {
            time++;
        }
    }

    // Print results
    int totalWait = 0, totalTurnaround = 0;

    for (int i = 0; i < n; i++) {
        totalWait += proc[i].waiting;
        totalTurnaround += proc[i].turnaround;
    }

    printf("\nAverage Waiting Time: %.2f\n", (float)totalWait / n);
    printf("Average Turnaround Time: %.2f\n", (float)totalTurnaround / n);

    /* Print Gantt Chart
    printf("\n|");
    for (int i = 0; i < ganttIndex; i++) {
        printf("  P%d  |", proc[ganttChart[i]].pid);
    }*/
    return 0;
}
