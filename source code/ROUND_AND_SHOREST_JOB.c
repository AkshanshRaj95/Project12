#include<stdio.h>
#include<conio.h> 
void main() 
{
	int at[10],burst_time[10],bt[10];
	char pro_id[10];
	char te;
	int i,smallest,count=0,time=3,limit,flag=0,j,remain,time_q=10,pos,temp,n;
	float wait_time=0,turnaround_time=0;
	float average_waiting_time,average_turnaround_time;
	printf("\nEnter the Total Number of Processes:\t");
	scanf("%d",&limit);
	remain=limit;  
	printf("\nEnter Details of %d Processes\n",limit);
	for(i=0;i<limit;i++)
	{
		printf("\n\nEnter the schedule id:\t");
		fflush(stdin);
		scanf("%c",&pro_id[i]);
		printf("Enter Arrival Time:\t");
		scanf("%d",&at[i]);
		printf("Enter Burst Time:\t");
		scanf("%d",&bt[i]); 
	}
	for(i=0;i<limit;i++)
    {
        pos=i;
        for(j=i+1;j<limit;j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
        }
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 		te=pro_id[i];
 		pro_id[i]=pro_id[pos];
 		pro_id[pos]=te;
        temp=at[i];
        at[i]=at[pos];
        at[pos]=temp;
    }
    smallest=at[0];
    
	for(i=0;i<limit;i++)
		burst_time[i]=bt[i]; 
	
	for(i=0;count!=limit;i++)
	{
		if(at[i]<=time)
		{
			if(bt[i]<=time_q&&bt[i]>0)
			{
				time+=bt[i];
				bt[i]=0;
				flag=1;
			}
			else if(bt[i]>0)
			{
				bt[i]-=time_q;
				time+=time_q;
			}
			if(bt[i]==0&&flag==1)
			{
				count++;
				printf("P[%c]\t|\t%d\t|\t%d\n",pro_id[i],time-at[i],time-at[i]-burst_time[i]);
				wait_time+=time-at[i]-burst_time[i];
				turnaround_time+=time-at[i];
				flag=0;
			}
		}
		if((i+1)==limit)
			i=-1;
	}
	printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n); 
    printf("Avg Turnaround Time = %f",turnaround_time*1.0/n); 
}
