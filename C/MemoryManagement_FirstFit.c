#include<stdio.h>
int main(){
    //First Fit Algorithm
    //Chooses the first one with the sufficient Memory Size 
    
    int n;
    printf("\nEnter the number of Processes : ");
    scanf("%d",&n);
    int p[n];
    for(int i=0;i<n;i++){
        printf("\nEnter Mem Requirement :");
        scanf("%d",&p[i]);
    }
    printf("\nEnter the number of Memory Blocks : ");
    int m;
    scanf("%d",&m);
    int mem[m];
    for(int i=0;i<m;i++){
        printf("\nEnter Memory Size : ");
        scanf("%d",&mem[i]);
    }
    for(int i=0;i<n;i++){
        //Allocating Process i
        int k=-1;
        for(int j=0;j<m;j++){
            if(p[i]<=mem[j]){
                k=j;
                break;
            }
        }
        p[i]=k;
        if(k!=-1)
        mem[k]=-1;
        }
    for(int i=0;i<n;i++){
        if(p[i]==-1)
            printf("\nProcess %d is not allocated any memory ",i+1);
        else
            printf("\nProcess %d is allocated Memory Index %d ",i+1,p[i]);
        }
}
