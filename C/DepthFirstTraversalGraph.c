#include<stdio.h>
#include<stdlib.h>
int **ar;
void creatematrix(int n)
{
    ar=(int**)malloc(n * sizeof(int *));
    int i=0;
    for(i=0;i<n;i++)
    {
        ar[i]=(int *)malloc(n*sizeof(int*));
    }
    for(i=0;i<n;i++)
    {
        int j=0;
        for(j=0;j<n;j++)
        {
            ar[i][j]=0;
            
        }
    }
}
int s1[20],pop(),dfsa[20];
void push(int a);
int top=-1;
void push(int a)
{
    top++;
    s1[top]=a;
}
int pop()
{
    int h=top;
    top--;
    return s1[h];
    
}
void dfssource(int n)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        dfsa[i]=0;
    }
}
void adjacentmatrix(int n)
{
    creatematrix(n);
    int e;
    printf("\n Enter the No of edges : ");
    scanf("%d",&e);
    int i;
    for(i=0;i<e;i++)
    {
        int q,r;
        printf("\n Edge %d : \n Node 1 : ",i+1);
        scanf("%d",&q);
        printf("\n Node 2 : ");
        scanf("%d",&r);
        ar[q-1][r-1]=ar[r-1][q-1]=1;
        
    }
}
void dfs(int n)
{
 dfssource(n);
 while(1)
 {
 if(top==-1)
 {
     int i=0;
     while(i<n)
     {
         if(dfsa[i]==0)
         {
         push(i+1);
         dfsa[i]=-1;
         break;
         }
         i++;
     }
     
     if(i==n)
     {
         printf(" End ");
         printf("\n Depth First Traversal of Graph done ! ");
         return ;
     }
 }
 else
 {
     int p=pop();
     printf("\t %d ->",p);
     int j=0;
     while(j<n)
     {
         if(ar[p-1][j]==1)
         {
         if(dfsa[j]!=-1)
         push(j+1);
         dfsa[j]=-1;
         }
         j++;
     }
 }
 }
 
}
int main()
{
    int n;
    printf("\n Enter the number of Nodes : ");
    scanf("%d",&n);
    adjacentmatrix(n);
    printf("\n Adjacent Matrix .......\n ");
    int i,j;
    for(i=0;i<n;i++)
    {
        printf("\n ");
        for(j=0;j<n;j++)
        {
            printf("\t %d ",ar[i][j]);
        }
    }
    printf("\n");
    printf("\n Depth First Traversal of Graph ");
    dfs(n);
}
