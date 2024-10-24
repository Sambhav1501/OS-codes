//round robin v2
#include <stdio.h>

struct Process {
    int pid;       // Process ID
    int bt;        // Burst Time
    int at;        // Arrival Time
    int wt;        // Waiting Time
    int tat;       // Turnaround Time
    int rem_bt;    // Remaining Burst Time
};

void findWaitingTime(struct Process proc[], int n, int quantum) {
    int t = 0; // Current time
    int done;  // Indicates if all processes are done
    printf("\nGantt Chart:\n");
    do {
        done = 1; // Assume all processes are done

        for (int i = 0; i < n; i++) {
            if (proc[i].at <= t && proc[i].rem_bt > 0) {
                done = 0; // There are still processes left

                if (proc[i].rem_bt > quantum) {
                    t += quantum;
                    proc[i].rem_bt -= quantum;
                } else {
                    t += proc[i].rem_bt;
                    proc[i].wt = t - proc[i].bt - proc[i].at;
                    proc[i].rem_bt = 0;
                }
                printf("P%d ",proc[i].pid);
            }
        }
    } while (!done);
}

void findTurnaroundTime(struct Process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].tat = proc[i].bt + proc[i].wt;
    }
}

void roundRobinScheduling(struct Process proc[], int n, int quantum) {
    findWaitingTime(proc, n, quantum);
    findTurnaroundTime(proc, n);
}

void display(struct Process proc[], int n) {
    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].at, proc[i].bt, proc[i].wt, proc[i].tat);
    }
}

int main() {
    int n, quantum;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process proc[n];

    for (int i = 0; i < n; i++) {
        proc[i].pid = i + 1;
        printf("Enter arrival time and burst time for process P%d: ", i + 1);
        scanf("%d", &proc[i].at);
        scanf("%d", &proc[i].bt);
        proc[i].rem_bt = proc[i].bt; // Initialize remaining burst time
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    roundRobinScheduling(proc, n, quantum);
    display(proc, n);

    return 0;
}

