//Write a C Program to read from a file using System Calls and to delimit the read string and print the output based on  custom delimiter 
//New Line can introduced to print the new delimited string in the standard output 




#include <stdio.h>
#include<sys/file.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
int main()
{
    int k=open("Myfile.txt",O_RDWR);
    char *g=(char *)malloc(100*(sizeof(char)));
    int l=lseek(k,0,2); //To find the length of the file
    lseek(k,0,0);
    char c[1];
    char s[1];
    printf("\nEnter the delimiting character in the file : ");
    scanf("%c",&s[0]); //Input the custom delimiter 
    int i=0;
    while(read(k,c,1)!=0){
        if(*c==s[0]){
            *(g+i)='\0';
            printf("\n%s",g);//Print once the delimiter is read 
            free(g);
            g=(char *)malloc(100*(sizeof(char)));
            i=0;
        }
        else
        {
        *(g+i)=*c;
        *(g+i+1)='\0';
        i++;
            
        }
    }
    if(g[0]!=0)
    printf("\n%s",g);
    return 0;
}
