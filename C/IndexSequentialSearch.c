#include<stdio.h>
#include<stdlib.h>
int partition(int *a,int b, int e)
{
    int x=a[e];
    int i=b-1;
    int j=b;
    for(j;j<e;j++)
    {
        if(a[j]<=x)
        {
            i++;
            int k=a[j];
            a[j]=a[i];
            a[i]=k;
            
        }
        
    }
    i++;
    int k=a[i];
    a[i]=x;
    a[e]=k;
    return i;
}
void quicksort(int *a,int b,int e)
{
    if(b<e)
    {
        int p=partition(a,b,e);
        quicksort(a,b,p-1);
        quicksort(a,p+1,e);
    }
}
int main()
{
    int i;
    int a[100];
    for(i=0;i<10;i++)
    {
        printf("\n Enter a number %d : ",i+1);
        scanf("%d",&a[i]);
    
    }
    
    printf("\n Enter the element to be searched : ");
    int elem;
    scanf("%d",&elem);
    int x=2;
    quicksort(a,0,9);
    int start,end,l=0;
    for(start=0,end=x;end<10;start=end+1,end=end+x)
    {
        if(a[end]>=elem)
        {
            if(a[end]==elem)
            {
                printf("\n Element found at the index %d : ",end);
                printf("\n l value %d  : ",l);
                break;
            }
            for(i=start;i<end;i++)
            {
                if(a[i]==elem)
                {
                    printf("\n Element found at the index  : %d ",i);
                    break;
                }
            }
            break;
        }
        l++;
    }
    if(end>=10)
    printf("\n Element not found ! ");
    
}
