//without structure
#include<stdio.h>

void FCFS(int at[],int bt[],int n)
{
	int wt[n];
	wt[0]=0;
	printf("pn\t\t at\t\t bt\t\t wt\n\n");
	printf("1\t\t %d\t\t %d\t\t %d\n\n",at[0],bt[0],wt[0]);
	for(int i=1;i<n;i++)
	{
		wt[i]=(at[i-1]+wt[i-1]+bt[i-1])-at[i];
		printf("%d\t\t %d\t\t %d\t\t %d\n\n",i+1,at[i],bt[i],wt[i]);
	}
	float art=0;
	float awt=0;
	float att=bt[0]+wt[0];
	for(int i=1;i<n;i++)
	{
		art=art+wt[i];
		awt=awt+wt[i];
		att=att+bt[i]+wt[i];
	}
	printf("avg waiting time = %f\n",(awt/n));
	printf("avg response time = %f\n",(art/n));
	printf("avg turnaround time = %f\n",(att/n));
}

int main()
{
	int n=0;
	printf("enter the total no of processes");
	scanf("%d",&n);
	int at[n];
	int wt[n];
	for(int i=0;i<n;i++)
	{
		printf("Enter the arrival and waiting time\n");
		scanf("%d%d",&at[i],&wt[i]);
	}
	FCFS(at,wt,n);
	return 0;
}
