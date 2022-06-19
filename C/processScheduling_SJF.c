//The below program implements SJF Process Scheduling Algorithm only using Arrays 
//Program implements SJF where different AT of the process is allowed
//BT -1 indicates that the process has already been scheduled in th program

#include<stdio.h>
int main(){
    int n;
    //No of Processes 
    printf("\nEnter the number of processes : ");
    scanf("%d",&n);
    int at[n],bt[n],tat[n],wt[n];
    for(int i=0;i<n;i++){
        printf("\nEnter AT: ");
        scanf("%d",&at[i]);
        printf("\nEnter BT: ");
        scanf("%d",&bt[i]);
    }
    //Sorting all the processes according to their arrival time 
    for(int i=0;i<n;i++){
        int a=at[i];
        int b=bt[i];
        for(int j=i+1;j<n;j++){
            if(a>at[j]){
                int x=at[j];
                at[j]=a;
                a=x;
                x=bt[j];
                bt[j]=b;
                b=x;
            }
        }
        at[i]=a;
        bt[i]=b;
    }
  //Scheduling based on Burst Time of the Processes in the waiting queue 
  int s=0;//Assumed Arrival Time for the Processes 
  for(int i=0;i<n;i++){
      int j=i+1;
      while(at[i]==at[j]||at[j]<=s)
      j++;
      int p=i;
      int g=i;
      if(j>i+1){
          for(int k=i;k<j;k++){
              if((bt[k]<bt[p])&&bt[k]!=-1){//bt=-1 indicates that the process has already been scheduled 
              p=k;
              i=g-1;
          }
      }
      }
      if(bt[p]!=-1){
          if(s<at[p]){
              s=at[p];
          }
          wt[p]=s-at[p];
          printf("\n!!!!%d",bt[p]);
          tat[p]=wt[p]+bt[p];
          s+=bt[p];
          bt[p]=-1;
      }
  }
  //Printing the Arrival Time,Turn around time and the Waiting time of all the processes 
  printf("\nProcess    AT    TAT    WT");
  for(int i=0;i<n;i++)
  printf("\n   %d      %d    %d     %d",i+1,at[i],tat[i],wt[i]);
}
