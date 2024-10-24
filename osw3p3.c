//shortest job first premptive
#include<stdio.h>
struct process{
    int pid;
    int at;
    int bt;
};

void sjf_p(struct process p[],int n){
    int wt[n],tat[n];
    int totalwt=0,totaltat=0;
    int rt[n];
    for(int i=0;i<n;i++){
        rt[i]=p[i].bt;
    }
    int complete=0,time=0,min;
    printf("Gantt Chart: ");
    while(1){
        min=-1;
        for(int i=0;i<n;i++){
            if(p[i].at<=time && rt[i]>0){
                if(min==-1||rt[i]<rt[min]){
                    min=i;
                }
            }
        }
        if(min==-1){
            break;
        }
        printf("P%d ",p[min].pid);
        rt[min]--;
        time++;
        if(rt[min]==0){
            wt[min]=time-p[min].at-p[min].bt;
            tat[min]=time-p[min].at;
            totalwt+=wt[min];
            totaltat+=tat[min];
        }
    }
    printf("\n");
    printf("Average waiting time: %f\n",(float)totalwt/n);
    printf("Average turn around time: %f\n",(float)totaltat/n);
}

int main(){
    int n;
    printf("Enter the no. of process:");
    scanf("%d",&n);
    struct process p[n];
    for(int i=0;i<n;i++){
        printf("Enter arrival time and burst time for process P%d: ",i);
        scanf("%d%d",&p[i].at,&p[i].bt);
        p[i].pid=i;
    }
    sjf_p(p,n);
    return 0;
}
