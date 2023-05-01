#include<stdio.h>
int check(int* p,int n){
	int i;
    for( i=0;i<n;i++){
        if(p[i]==0)
        return 1;
    }
    return 0;
}
int main(){
    //Algorithm uses 4 Data Structures
    int t;//No of types of Resources
    int n;//No of processes
    int i,j;
    printf("\nEnter number of Resource types :");
    scanf("%d",&t);
    printf("\nEnter number of Processes :");
    scanf("%d",&n);
    int seq[n];//To print the safe sequence
    int r[t];
    int alloc[n][t],max[n][t],need[n][t];
    int avai[t],cur[t];
    for(i=0;i<t;i++)
    avai[i]=0;
    for(i=0;i<t;i++){
        printf("\n Instances : ");
        scanf("%d",&r[i]);
        cur[i]=0;
    }
    for(i=0;i<n;i++){
        printf("\nMax Need : ");
        for(j=0;j<t;j++){
            scanf("%d",&max[i][j]);
        }
        printf("\nAllocated : ");
        for(j=0;j<t;j++){
            scanf("%d",&alloc[i][j]);
            need[i][j]=max[i][j]-alloc[i][j];
            cur[j]+=alloc[i][j];
        }
        seq[i]=-1;
        
    }
    for(i=0;i<t;i++){
        cur[i]=r[i]-cur[i];
    }
    printf("\nCurrent Resources Availble");
    for(i=0;i<t;i++)
    printf("\t%d",cur[i]);

    //Bankers Algorithm
    int k=1;
    int finish[n];
    for(i=0;i<n;i++){
        finish[i]=0;
    }
    do{
    for(i=0;i<n;i++){
        if(finish[i]==0){
            int j;
            for(j=0;j<t;j++){
                if(need[i][j]>cur[j])
                j=t+1;
            }
            if(j==t){
                for(j=0;j<t;j++){
                    cur[j]+=alloc[i][j];
                    alloc[i][j]=0;
                    need[i][j]=0;
                }
                finish[i]=1;
                seq[i]=k;
                k++;
            }
        }
    }
    }while(check(finish,n));
    printf("\n Safe Sequence . . . : ");
    int pseq[n];
	for(i=0;i<n;i++){
    pseq[seq[i]-1]=i+1;
	}
	for(i=0;i<n;i++){
		printf("%d",pseq[i]);
	}
}
