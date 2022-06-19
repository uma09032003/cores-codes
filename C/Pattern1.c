//Write a C Program to print the following pattern
/*
ABCDEFGFEDCBA
ABCDEF FEDCBA
ABCDE   EDCBA
ABCD     DCBA
ABC       CBA
AB         BA
A           A
*/
#include <stdio.h>

void print()
{
    int k=0;
    int p=0;
    printf("\n");
    while(p<7)
    {
        int i;
        int a=65,b=70;
    for( i=0;i<7-k;i++)
    {
        printf("%c",(char)a);
        a++;
    }
    k+=1;
    for(i;i<7;i++)
    printf(" ");
    int t=0;
    for(i=0;i<6;i++)
    {
        if(t<p-1)
        {
            printf(" ");
            t++;
        }
        else
        {
        printf("%c",(char)b);
        }       
        b--;
    }
    p+=1;
    printf("\n");
}
}
int main()
{
    print();
}

