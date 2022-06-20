#include <stdio.h>
//Worst fit Algorithm
int main()
{
    int n;
    printf("\nEnter the number of processes : ");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("\nEnter the number of memory slots : ");
    int m;
    scanf("%d",&m);
    int b[m];
    for(int i=0;i<m;i++){
        scanf("%d",&b[i]);
    }
    //Worst Fit 
    //Highest of the sufficient memory
    int all[n];
    for(int i=0;i<n;i++)
    all[i]=-1;
    for(int i=0;i<n;i++){
        int k=a[i];
        int p=-1;
        int x=-1;
        for(int j=0;j<m;j++){
            if(b[j]>=k&&p<b[j]&&b[j]!=-1)
            {
                p=b[j];
                x=j;
            }
        }
        if(x!=-1){
        all[i]=x;
        b[x]=-1;
        }
    }
    for(int i=0;i<n;i++){
        if(all[i]!=-1)
        printf("\nProcess %d is allocated Memory at Index : %d",i+1,all[i]);
        else
        printf("\nProcess %d is not allocated any memory",i+1);
    }

    return 0;
}
