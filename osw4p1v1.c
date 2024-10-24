//round robin algorithm
#include<stdio.h>
struct process{
    int pid;
    int at;
    int bt;
    int rt;
    int wt;
    int tat;
    int ct;
};

void roundrobin(struct process p[],int n,int quantum){
    int complete=0,time=0;
    int totalwt=0,totaltat=0;
    printf("Gantt Chart: ");
    while(complete<n){
        for(int i=0;i<n;i++){
            if(p[i].rt>0 && p[i].at<=time){
                if(p[i].rt<=quantum){
                    time+=p[i].rt;
                    p[i].ct=time;
                    p[i].rt=0;
                    p[i].tat=p[i].ct-p[i].at;
                    p[i].wt=p[i].tat-p[i].bt;
                    totalwt+=p[i].wt;
                    totaltat+=p[i].tat;
                    complete++;
                }else{
                    time+=quantum;
                    p[i].rt-=quantum;
                }
                printf("P%d ",p[i].pid);
            }
        }
    }
    }
    printf("\n");
    printf("Average waiting time: %f\n",(float)totalwt/n);
    printf("Average turn around time: %f",(float)totaltat/n);
}
 int main(){
    int n,quantum;
    printf("Enter the no. of process:");
    scanf("%d",&n);
    struct process p[n];
    for(int i=0;i<n;i++){
        printf("Enter arrival time and burst time for process P%d: ",i);
        scanf("%d%d",&p[i].at,&p[i].bt);
        p[i].pid=i;
        p[i].rt=p[i].bt;
    }
    printf("Enter the time quantum: ");
    scanf("%d",&quantum);
    roundrobin(p,n,quantum);
    return 0;
 }
