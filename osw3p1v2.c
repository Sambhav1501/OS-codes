#include <stdio.h>

struct Process {
    int id;     // Process ID
    int bt;     // Burst Time
    int at;     // Arrival Time
    int wt;     // Waiting Time
    int tat;    // Turnaround Time
    int ct;     // Completion Time
};

// Function to sort proccess based on their arrival time, then by burst time
void sortProcesses(struct Process proc[], int n) {
    struct Process temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (proc[j].at > proc[j + 1].at || 
                (proc[j].at == proc[j + 1].at && proc[j].bt > proc[j + 1].bt)) {
                // Swap
                temp = proc[j];
                proc[j] = proc[j + 1];
                proc[j + 1] = temp;
            }
        }
    }
}

// Function to calculate waiting time, turnaround time, and completion time
void calculateTimes(struct Process proc[], int n) {
    int currentTime = 0;
    float awt=0.0;
    float atat=0.0;
    printf(" Gantt Chart \n");
    for (int i = 0; i < n; i++) {
        if (currentTime < proc[i].at) {
            currentTime = proc[i].at;  // If CPU is idle, jump to process arrival time
        }
        
        proc[i].wt = currentTime - proc[i].at;
        proc[i].ct = currentTime + proc[i].bt;
        proc[i].tat = proc[i].ct - proc[i].at;
        
        currentTime += proc[i].bt; // Update current time to completion of this process
        awt=awt+proc[i].wt;
        atat=atat+proc[i].tat;
        printf(" P%d ",proc[i].id);//to print the Gantt chart
    }
    printf("\naverage waiting time= %f \n",awt/n);
    printf("average turn around time= %f \n",atat/n);
}

int main() {
    int n;

    printf("Enter number of proc: ");
    scanf("%d", &n);
    
    struct Process proc[n];

    // Input process details
    for (int i = 0; i < n; i++) {
        proc[i].id = i + 1; // Process ID starts from 1
        printf("Enter arrival time and burst time for process P%d: ", proc[i].id);
        scanf("%d %d", &proc[i].at, &proc[i].bt);
    }

    // Sort proc by arrival time, and burst time in case of tie
    sortProcesses(proc, n);
    
    // Calculate waiting time, turnaround time, and completion time
    calculateTimes(proc, n);

    // Print the results
    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t\t%d\n", proc[i].id, proc[i].at, proc[i].bt, proc[i].wt, proc[i].tat);
    }

    return 0;
}
