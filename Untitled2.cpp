#include<stdio.h>
#include<stdlib.h>
void merger(int no_of_process,int arr_time[],int bur_time[])
{
	int i,t,sum=0,priority[no_of_process],flag,max=0,wait_time[no_of_process];
	int avg_w_time=0,arr[no_of_process];
	for(i=0;i<no_of_process;i++)       //copying the burst time of all the processes in separate array for calculating average waiting time
	{
		arr[i]=bur_time[i];
	}
	for(i=0;i<no_of_process;i++)      //initially assigning 0 priority to all the processes
	{
		priority[i]=0;
	}
	for(i=0;i<no_of_process;i++)      //finding sum of all the burst time so that total iteration can be known 
	{
		sum=sum+bur_time[i];
	}
	for(t=0;t<sum;t++)
	{   flag=0;
		for(i=0;i<no_of_process;i++)
	    {
		    if(t>=arr_time[i] && flag==0 && priority[i]==max && bur_time[i]>0)  //when process is running i.e. in running queue
			{
				printf("Process %d is executed at time %d\n",i+1,t);
				priority[i]+=1;
				flag=1;
				bur_time[i]-=1;
				if(bur_time[i]==0)
				{
					wait_time[i]=(t+1)-arr_time[i]-arr[i];
			    }
			}
			else if(t>=arr_time[i] && bur_time[i]>0)   //when process is in ready queue
			priority[i]+=2;	
		}
		if(flag==0)      //calculating the maximum priority process
		sum+=1;
		max=priority[0];
		for(i=1;i<no_of_process;i++)
		{    if(priority[i]>max)
	               max=priority[i];
}
	}
	for(i=0;i<no_of_process;i++)      //loop to calculate average waiting time of the  process 
	{
		avg_w_time=avg_w_time+wait_time[i];
	}
	printf("\n\nProcess No.\t\tArrival Time\t\tBurst Time\t\t Waiting Time\n");
	for(i=0;i<no_of_process;i++)     //final table printing
	{
		printf("%d\t\t\t%d\t\t\t%d\t\t\t%d",(i+1),arr_time[i],arr[i],wait_time[i]);
		printf("\n");
	}
	printf("\nAverage waiting time is %d",avg_w_time/no_of_process);
}
int main()
{
	//taking the number of processes their arrival and burst time from the user
	int i,no_of_process;
	printf("Enter number of processess : ");
	scanf("%d",&no_of_process);
	int arr_time[no_of_process],bur_time[no_of_process];
	printf("\n");
	for(i=0;i<no_of_process;i++)
	{
		printf("Enter arrival time of Process %d = ",i+1);
		scanf("%d",&arr_time[i]);
		printf("Enter burst time of Process %d = ",i+1);
		scanf("%d",&bur_time[i]);
	}
	//sending all the values to the function defined as merger
	merger(no_of_process,arr_time,bur_time);
}


