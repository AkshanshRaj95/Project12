#include<stdio.h>
#include<conio.h> 
void main() 
{
	int at[10],burst_time[10],temp[10],bt[10];
	int i,smallest,count=0,time,limit,flag=0,time_quantum,remain;
	double wait_time=0,turnaround_time=0;
	float average_waiting_time,average_turnaround_time;
	printf("\nEnter the Total Number of Processes:\t");
	scanf("%d",&limit);
	remain=limit;  
	printf("\nEnter Details of %d Processes\n",limit);
	for(i=0;i<limit;i++)
	{
		printf("\nEnter Arrival Time:\t");
		scanf("%d",&at[i]);
		printf("Enter Burst Time:\t");
		scanf("%d",&burst_time[i]); 
		temp[i]=burst_time[i];
		bt[i]=burst_time[i];
	}
	printf("Enter Time Quantum:\t"); 
	scanf("%d",&time_quantum); 
	printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
	burst_time[9]=9999;  
	for(time=0;count!=limit;)
	{
		smallest=9;
		for(i=0;i<limit;i++)
		{
			if(at[i]<=time&&burst_time[i]<burst_time[smallest]&&burst_time[i]>0)
			{
				smallest=i;
			}
		}
		if(burst_time[smallest]<=time_quantum&&burst_time[smallest]>0)
		{
			time+=burst_time[smallest];
			burst_time[smallest]=0;
			flag=1;
		}
		else if(burst_time[smallest]>0)
		{
			burst_time[smallest]-=time_quantum;
			time+=time_quantum;
		}
		if(burst_time[smallest]==0&&flag==1)
		{
			count++;
			printf("P[%d]\t|\t%d\t|\t%d\n",smallest+1,time-at[smallest],time-at[smallest]-bt[smallest]);
			wait_time+=time-at[smallest]-bt[smallest];
			turnaround_time+=time-at[smallest];
			flag=0;
		}
	}
	
	getch();
}
