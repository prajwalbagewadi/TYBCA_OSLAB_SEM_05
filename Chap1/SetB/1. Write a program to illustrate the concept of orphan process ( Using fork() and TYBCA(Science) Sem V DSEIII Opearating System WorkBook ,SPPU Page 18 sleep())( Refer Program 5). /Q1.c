/*
1. Write a program to illustrate the concept of orphan process ( Using fork() and
TYBCA(Science) Sem V DSEIII Opearating System WorkBook ,SPPU Page 18
sleep())( Refer Program 5). 
*/
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
int main(){
    int stat;
    pid_t pid;
    //child process creation
    pid=fork();
    if(pid>0){
        printf("Parent Process in Execution.\n");
        printf("Parent Process (Pid:%d)\n",getpid());
        printf("Parent Process Terminated.\n\n");
    }
    else if(pid==0){
        printf("child Process in Execution.\n");
        printf("Child Process (Pid:%d)\n",pid);
        printf("Parent Process (Pid:%d)\n\n",getpid());
        printf("sleep mode Active:\n");
        sleep(10);// lets Child process to sleep mode.
        printf("Child Process (Pid:%d)\n",pid);
        printf("Parent Process (Pid:%d)\n",getpid());
        printf("Child Process Terminated.\n\n");
        
    }
    else{
        printf("Child Process execution Failed.\n\n");
    }
    printf("current program Parent process(Pid:%d)\n",getpid());
    return 0;
}
