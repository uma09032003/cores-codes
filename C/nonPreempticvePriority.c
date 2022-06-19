//The following code implements Non-Pre emptive Scheduling Algorithm for Processes with different Arrival Time and C
//The program is written assuming the lower number corresponds to higher priority and priority number ranges from 0 to n
//Priority of -1 is used to indicate that the process has already been scheduled 
//The below program does not use queue data structure, it uses only array
//This can be optimized and implemented using Queue Data Structure 


#include<stdio.h>
int main(){
    int n;
    printf("\nEnter the number of Processes : ");
    scanf("%d",&n);
    int at[n],bt[n],pt[n];//For Process Arrival Time,Burst Time and Prioriy
    for(int i=0;i<n;i++){
        printf("\nAt: ");
        scanf("%d",&at[i]);
        printf("\nBT: ");
        scanf("%d",&bt[i]);
        printf("\nPriority: ");
        scanf("%d",&pt[i]);
    }
    //Above for loop inputs at,bt,and priority of respective processes 
    for(int i=0;i<n;i++){
        int a=at[i];
        int b=bt[i],c=pt[i];
        for(int j=i+1;j<n;j++){
            if(a>at[j]){
                int x=at[j];
                at[j]=a;
                a=x;
                //Swapping the Bust Time and the Priority too
                x=bt[j];
                bt[j]=b;
                b=x;
                x=pt[j];
                pt[j]=c;
                c=x;
            }
        }
        at[i]=a;
        bt[i]=b;
        pt[i]=c;
    }
    int tat[n],wt[n];
    //Scheduling based on Priority 
    int s=0;//Initial Execution time is assumed to be 0  
    for(int i=0;i<n;i++){
        int j=i+1;
        //To find the pool of processes having same arrival time or the arrival time less then completion time of the previous process
        while((at[i]==at[j]||at[j]<=s)&&j<n)
        j++;
        
        int p=i;
        int g=i;
        //If there are more than 1 process in the pool
        if(j>i+1){
                for(int l=i;l<j;l++){
                    if((pt[p]>pt[l])&&pt[l]!=-1){
                        p=l;
                        i=g-1;
                    }
                }
        }  
                if(pt[p]!=-1){
                //If there is a waiting or a stall as there are no process in the queue
                if(s<at[p]){
                    s=s+(at[p]-s);
                }
                wt[p]=s-at[p];;
                tat[p]=bt[p]+wt[p];
                s+=bt[p];
                pt[p]=-1;//To indicate the process has already been allocated 
        }
    }
        //Displaying the Process Arrival Time, Burst Time, Priority and Turn Around Time, and Waiting Time
        printf("\nProcess    AT    BT       TAT    WT");
        for(int i=0;i<n;i++){
        printf("\n   %d      %d    %d        %d     %d ",i+1,at[i],bt[i],tat[i],wt[i]);       
        }   
}
