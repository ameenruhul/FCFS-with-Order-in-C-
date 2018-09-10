#include<stdio.h>
 
int main()
{
    int bt[20],p[20],wt[20],tat[20],pr[20],i,j,n,total=0,pos,temp,avg_wt,avg_tat;
    
    const int maxWidth=100;
    int scalingFactor,counter,tempi,currentTime;
    
    printf("Enter Total Number of Process:");
    scanf("%d",&n);
 
    printf("\nEnter Burst Time and Priority\n");
    for(i=0;i<n;i++)
    {
        printf("\nP[%d]\n",i+1);
        printf("Burst Time:");
        scanf("%d",&bt[i]);
        printf("Order:");
        scanf("%d",&pr[i]);
        p[i]=i+1;           //contains process number
    }
 
    //sorting burst time, priority and process number in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }
 
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 
    wt[0]=0;    //waiting time for first process is zero
 
    //calculate waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
 
        total+=wt[i];
    }
 
    avg_wt=total/n;      //average waiting time
    total=0;
 
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     //calculate turnaround time
        total+=tat[i];
        printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }
 
    avg_tat=total/n;     //average turnaround time
    printf("\n\nAverage Waiting Time=%d",avg_wt);
    printf("\nAverage Turnaround Time=%d\n",avg_tat);
    
    
    
    printf("The gantt chart for the given processes is : \n\n");

    scalingFactor=maxWidth/total;
    
    for(i=0;i<scalingFactor*total+2+n;i++)
    {
        printf("-");
    }
    printf("\n|");
    counter=0,tempi=0;
    for(i=0;i<scalingFactor*total;i++)
    {
        if(i==bt[counter]*scalingFactor+tempi)
        {
            counter++;
            tempi=i;
            printf("|");
        }
        else if(i==(bt[counter]*scalingFactor)/2+tempi)
        {
            printf("P%d",p[counter]);
        }
        else
        {
            printf(" ");
        }

    }
    printf("|");
    printf("\n");
    for(i=0;i<scalingFactor*total+2+n;i++)
    {
        printf("-");
    }
    printf("\n");

    /* printing the time labels of the gantt chart */ 
    counter=0;
    tempi=0;
    currentTime=0;
    printf("%d",currentTime);
    for(i=0;i<scalingFactor*total;i++)
    {
        if(i==bt[counter]*scalingFactor+tempi)
        {

            tempi=i;
            currentTime+=bt[counter];
            avg_wt+=currentTime;
            counter++;
            printf("%2d",currentTime);
        }
        else
        {
            printf(" ");
        }
    }
    currentTime+=bt[counter];

    
    
}






