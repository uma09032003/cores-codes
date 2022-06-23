#include <stdio.h>
#include<stdlib.h>
struct index
{
    int data;
    struct index *c;
}*p,*t,o[10];
struct index **a;
void init()
{
    a=(struct index**)malloc(10*(sizeof(struct index*)));
    int i=0;
    for(i=0;i<10;i++)
    {
        a[i]=&o[i];
        a[i]->data=-1;
        a[i]->c=NULL;
    }
}
void enter_data(int d)
{
    int i=d%10;
    if(a[i]->data==-1)
    {
        a[i]->data=d;
        printf("\n No Collision \n Data Entered Successfully ! ");
    }
    else
    {
        printf("\n Collision ! ");
        p=a[i];
        t=a[i]->c;
        while(t!=NULL)
        {
            p=t;
            t=t->c;
        }
        printf("\n Data to be entered adjacent to : %d ",p->data);
        t=(struct index*)malloc(sizeof(struct index));
        t->data=d;
        p->c=t;
    }
}
void probe(int d)
{
    int i=d%10;
    if(a[i]->data==-1)
    {
        printf("\n No data found ! ");
    }
    else
    {
        if(a[i]->data==d)
        {
            printf("\n Data found ! \n Index  : %d \n No Collision has taken place while entering the data ! ",i);
            return;
        }
        else
        {
            t=a[i];
            p=a[i]->c;
            int k=1;
            while(p!=NULL)
            {
                if(p->data==d)
                {
                    printf("\n Data found at the index : %d \n Chain Element  : %d ",i,k);
                    return ;
                }
                p=p->c;
                k++;
            }
            printf("\n Data not found ! ");
        }
    }
}

int main()
{
    init();
    printf("\n Enter the number of elements to be entered  : ");
    int n;
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)
    {
        int d;
        printf("\n Enter element %d : ",i+1);
        scanf("%d",&d);
        enter_data(d);
    }
    printf("\n Enter the data to be searched  : ");
    int d;
    scanf("%d",&d);
    probe(d);
}
