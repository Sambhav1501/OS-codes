//shortest job first non premptive
#include<stdio.h>

struct process{
    int pid;
    int at;
    int bt;
};

void sjf(struct process p[],int n){
    int wt[n],tat[n];
    int totalwt=0,totaltat=0;
    int complete=0,time=0,min;
    int iscomplete[10]={0};
    printf("Gantt Chart: ");
    while(complete<n){
        min=-1;
        for(int i=0;i<n;i++){
            if(p[i].at<=time &&!iscomplete[i]){
                if(min==-1||p[i].bt<p[min].bt){
                    min=i;
                }
            }
        }
        if(min==-1){
            time++;
            continue;
        }
        printf("P%d ",p[min].pid);
        time+=p[min].bt;
        wt[min]=time-p[min].at-p[min].bt;
        tat[min]=time-p[min].at;
        totalwt+=wt[min];
        totaltat+=tat[min];
        iscomplete[min]=1;
        complete++;
        }
        printf("\n");
        printf("Average waiting time: %f\n",(float)totalwt/n);
        printf("Average turn around time: %f\n",(float)totaltat/n);
}

int main(){
    int n;
    printf("Enter the no. of processes: ");
    scanf("%d",&n);
    struct process p[n];
    for(int i=0;i<n;i++){
        printf("Enter arrival time and burst time of process P%d: ",i);
        scanf("%d%d",&p[i].at,&p[i].bt);
        p[i].pid=i;
    }
    sjf(p,n);
    return 0;
}
