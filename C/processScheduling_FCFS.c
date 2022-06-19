#include <stdio.h>

int main()
{
    int n;
    printf("\n Enter the number of processes : ");
    scanf("%d",&n);
    int at[n],bt[n],wt[n],tt[n];
    for(int i=0;i<n;i++){
        printf("\nArrival Time : ");
        scanf("%d",&at[i]);
        printf("\n Burst Time : ");
        scanf("%d",&bt[i]);
    }
    for(int i=0;i<n;i++){
        int k=at[i];
        int z=bt[i];
        for(int j=i+1;j<n;j++){
            if(k>at[j]){
                int p=at[j];
                at[j]=k;
                k=p;
                p=bt[j];
                bt[j]=z;
                z=p;
            }
        }
        at[i]=k;
        bt[i]=z;
    }
  
  int c=0;
  c=at[0]+bt[0];
  tt[0]=c-at[0];
  wt[0]=0;
  for(int i=1;i<n;i++){
      wt[i]=(c-at[i]-at[0])>0?(c-at[i]-at[0]):0;
      c=c+((c-at[i]-at[0])<0?(at[0]+at[i]-c):0);
      c+=bt[i];
      tt[i]=bt[i]+wt[i];
  }
  for(int i=0;i<n;i++){
      printf("\n P%d : TT: %d WT: %d",i+1,tt[i],wt[i]);
  }
    return 0;
}
