//Write a C Program using system calls having one child process where the parent process reads the content written by the child process

#include<stdio.h>
#include<sys/file.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<unistd.h>

int main(){
    
    pid_t p=fork();
    if(p==0){
        printf("\nIn Child Process . . . .");
        printf("\nCurrent Process ID : %d,\nParent Process ID : %d ",getpid(),getppid());
        int k=creat("Myfile.txt",S_IWRITE|S_IREAD);
        
        printf("\nEnter Text to Input into the file : ");
        char a[5];
        scanf("%s",a);
        write(k,a,5);
        printf("Written to the file from the Child Process !");
        close(k);
    }
    else if(p>0){
        int g;
        int w=wait(&g);//Wait until the child process terminates 
        char a[100];
        int k=open("Myfile.txt",O_RDONLY);
        read(k,a,99);
        printf("\nPrinting from the Parent Process . . . .  ");
        printf("\n%s",a);
        printf("\nCurrent Process ID : %d ",getpid());
    }
    else if(p==-1){
        char b[]="Error Creating the Child Process!";
        write(2,b,sizeof(b)+1);
    }
}
